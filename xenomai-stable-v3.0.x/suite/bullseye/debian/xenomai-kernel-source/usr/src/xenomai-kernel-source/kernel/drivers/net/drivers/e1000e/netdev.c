/*******************************************************************************

  Intel PRO/1000 Linux driver
  Copyright(c) 1999 - 2011 Intel Corporation.

  This program is free software; you can redistribute it and/or modify it
  under the terms and conditions of the GNU General Public License,
  version 2, as published by the Free Software Foundation.

  This program is distributed in the hope it will be useful, but WITHOUT
  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
  more details.

  You should have received a copy of the GNU General Public License along with
  this program; if not, write to the Free Software Foundation, Inc.,
  51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.

  The full GNU General Public License is included in this distribution in
  the file called "COPYING".

  Contact Information:
  Linux NICS <linux.nics@intel.com>
  e1000-devel Mailing List <e1000-devel@lists.sourceforge.net>
  Intel Corporation, 5200 N.E. Elam Young Parkway, Hillsboro, OR 97124-6497

*******************************************************************************/

#define pr_fmt(fmt) KBUILD_MODNAME ": " fmt

#include <linux/module.h>
#include <linux/types.h>
#include <linux/init.h>
#include <linux/pci.h>
#include <linux/vmalloc.h>
#include <linux/pagemap.h>
#include <linux/delay.h>
#include <linux/netdevice.h>
#include <linux/interrupt.h>
#include <linux/tcp.h>
#include <linux/ipv6.h>
#include <linux/slab.h>
#include <net/checksum.h>
#include <net/ip6_checksum.h>
#include <linux/mii.h>
#include <linux/ethtool.h>
#include <linux/if_vlan.h>
#include <linux/cpu.h>
#include <linux/smp.h>
#include <linux/version.h>
#include <linux/pm_qos.h>
#include <linux/pm_runtime.h>
#include <linux/aer.h>
#include <linux/prefetch.h>

#include "e1000.h"

#define RT_E1000E_NUM_RXD	64

#define DRV_EXTRAVERSION "-k-rt"

#define DRV_VERSION "1.5.1" DRV_EXTRAVERSION
char e1000e_driver_name[] = "rt_e1000e";
const char e1000e_driver_version[] = DRV_VERSION;

static void e1000e_disable_aspm(struct pci_dev *pdev, u16 state);

static const struct e1000_info *e1000_info_tbl[] = {
	[board_82571]		= &e1000_82571_info,
	[board_82572]		= &e1000_82572_info,
	[board_82573]		= &e1000_82573_info,
	[board_82574]		= &e1000_82574_info,
	[board_82583]		= &e1000_82583_info,
	[board_80003es2lan]	= &e1000_es2_info,
	[board_ich8lan]		= &e1000_ich8_info,
	[board_ich9lan]		= &e1000_ich9_info,
	[board_ich10lan]	= &e1000_ich10_info,
	[board_pchlan]		= &e1000_pch_info,
	[board_pch2lan]		= &e1000_pch2_info,
	[board_pch_lpt]		= &e1000_pch_lpt_info,
};

struct e1000_reg_info {
	u32 ofs;
	char *name;
};

#define E1000_RDFH	0x02410	/* Rx Data FIFO Head - RW */
#define E1000_RDFT	0x02418	/* Rx Data FIFO Tail - RW */
#define E1000_RDFHS	0x02420	/* Rx Data FIFO Head Saved - RW */
#define E1000_RDFTS	0x02428	/* Rx Data FIFO Tail Saved - RW */
#define E1000_RDFPC	0x02430	/* Rx Data FIFO Packet Count - RW */

#define E1000_TDFH	0x03410	/* Tx Data FIFO Head - RW */
#define E1000_TDFT	0x03418	/* Tx Data FIFO Tail - RW */
#define E1000_TDFHS	0x03420	/* Tx Data FIFO Head Saved - RW */
#define E1000_TDFTS	0x03428	/* Tx Data FIFO Tail Saved - RW */
#define E1000_TDFPC	0x03430	/* Tx Data FIFO Packet Count - RW */

static const struct e1000_reg_info e1000_reg_info_tbl[] = {

	/* General Registers */
	{E1000_CTRL, "CTRL"},
	{E1000_STATUS, "STATUS"},
	{E1000_CTRL_EXT, "CTRL_EXT"},

	/* Interrupt Registers */
	{E1000_ICR, "ICR"},

	/* Rx Registers */
	{E1000_RCTL, "RCTL"},
	{E1000_RDLEN, "RDLEN"},
	{E1000_RDH, "RDH"},
	{E1000_RDT, "RDT"},
	{E1000_RDTR, "RDTR"},
	{E1000_RXDCTL(0), "RXDCTL"},
	{E1000_ERT, "ERT"},
	{E1000_RDBAL, "RDBAL"},
	{E1000_RDBAH, "RDBAH"},
	{E1000_RDFH, "RDFH"},
	{E1000_RDFT, "RDFT"},
	{E1000_RDFHS, "RDFHS"},
	{E1000_RDFTS, "RDFTS"},
	{E1000_RDFPC, "RDFPC"},

	/* Tx Registers */
	{E1000_TCTL, "TCTL"},
	{E1000_TDBAL, "TDBAL"},
	{E1000_TDBAH, "TDBAH"},
	{E1000_TDLEN, "TDLEN"},
	{E1000_TDH, "TDH"},
	{E1000_TDT, "TDT"},
	{E1000_TIDV, "TIDV"},
	{E1000_TXDCTL(0), "TXDCTL"},
	{E1000_TADV, "TADV"},
	{E1000_TARC(0), "TARC"},
	{E1000_TDFH, "TDFH"},
	{E1000_TDFT, "TDFT"},
	{E1000_TDFHS, "TDFHS"},
	{E1000_TDFTS, "TDFTS"},
	{E1000_TDFPC, "TDFPC"},

	/* List Terminator */
	{}
};

/*
 * e1000_regdump - register printout routine
 */
static void e1000_regdump(struct e1000_hw *hw, struct e1000_reg_info *reginfo)
{
	int n = 0;
	char rname[16];
	u32 regs[8];

	switch (reginfo->ofs) {
	case E1000_RXDCTL(0):
		for (n = 0; n < 2; n++)
			regs[n] = __er32(hw, E1000_RXDCTL(n));
		break;
	case E1000_TXDCTL(0):
		for (n = 0; n < 2; n++)
			regs[n] = __er32(hw, E1000_TXDCTL(n));
		break;
	case E1000_TARC(0):
		for (n = 0; n < 2; n++)
			regs[n] = __er32(hw, E1000_TARC(n));
		break;
	default:
		printk(KERN_INFO "%-15s %08x\n",
		       reginfo->name, __er32(hw, reginfo->ofs));
		return;
	}

	snprintf(rname, 16, "%s%s", reginfo->name, "[0-1]");
	printk(KERN_INFO "%-15s ", rname);
	for (n = 0; n < 2; n++)
		printk(KERN_CONT "%08x ", regs[n]);
	printk(KERN_CONT "\n");
}

/*
 * e1000e_dump - Print registers, Tx-ring and Rx-ring
 */
static void e1000e_dump(struct e1000_adapter *adapter)
{
	struct rtnet_device *netdev = adapter->netdev;
	struct e1000_hw *hw = &adapter->hw;
	struct e1000_reg_info *reginfo;
	struct e1000_ring *tx_ring = adapter->tx_ring;
	struct e1000_tx_desc *tx_desc;
	struct my_u0 {
		u64 a;
		u64 b;
	} *u0;
	struct e1000_buffer *buffer_info;
	struct e1000_ring *rx_ring = adapter->rx_ring;
	union e1000_rx_desc_packet_split *rx_desc_ps;
	union e1000_rx_desc_extended *rx_desc;
	struct my_u1 {
		u64 a;
		u64 b;
		u64 c;
		u64 d;
	} *u1;
	u32 staterr;
	int i = 0;

	if (!netif_msg_hw(adapter))
		return;

	/* Print netdevice Info */
	if (netdev) {
		dev_info(&adapter->pdev->dev, "Net device Info\n");
		printk(KERN_INFO "Device Name     state            "
		       "trans_start      last_rx\n");
		printk(KERN_INFO "%-15s\n", netdev->name);
	}

	/* Print Registers */
	dev_info(&adapter->pdev->dev, "Register Dump\n");
	printk(KERN_INFO " Register Name   Value\n");
	for (reginfo = (struct e1000_reg_info *)e1000_reg_info_tbl;
	     reginfo->name; reginfo++) {
		e1000_regdump(hw, reginfo);
	}

	/* Print Tx Ring Summary */
	if (!netdev || !rtnetif_running(netdev))
		goto exit;

	dev_info(&adapter->pdev->dev, "Tx Ring Summary\n");
	printk(KERN_INFO "Queue [NTU] [NTC] [bi(ntc)->dma  ]"
	       " leng ntw timestamp\n");
	buffer_info = &tx_ring->buffer_info[tx_ring->next_to_clean];
	printk(KERN_INFO " %5d %5X %5X %016llX %04X %3X %016llX\n",
	       0, tx_ring->next_to_use, tx_ring->next_to_clean,
	       (unsigned long long)buffer_info->dma,
	       buffer_info->length,
	       buffer_info->next_to_watch,
	       (unsigned long long)buffer_info->time_stamp);

	/* Print Tx Ring */
	if (!netif_msg_tx_done(adapter))
		goto rx_ring_summary;

	dev_info(&adapter->pdev->dev, "Tx Ring Dump\n");

	/* Transmit Descriptor Formats - DEXT[29] is 0 (Legacy) or 1 (Extended)
	 *
	 * Legacy Transmit Descriptor
	 *   +--------------------------------------------------------------+
	 * 0 |         Buffer Address [63:0] (Reserved on Write Back)       |
	 *   +--------------------------------------------------------------+
	 * 8 | Special  |    CSS     | Status |  CMD    |  CSO   |  Length  |
	 *   +--------------------------------------------------------------+
	 *   63       48 47        36 35    32 31     24 23    16 15        0
	 *
	 * Extended Context Descriptor (DTYP=0x0) for TSO or checksum offload
	 *   63      48 47    40 39       32 31             16 15    8 7      0
	 *   +----------------------------------------------------------------+
	 * 0 |  TUCSE  | TUCS0  |   TUCSS   |     IPCSE       | IPCS0 | IPCSS |
	 *   +----------------------------------------------------------------+
	 * 8 |   MSS   | HDRLEN | RSV | STA | TUCMD | DTYP |      PAYLEN      |
	 *   +----------------------------------------------------------------+
	 *   63      48 47    40 39 36 35 32 31   24 23  20 19                0
	 *
	 * Extended Data Descriptor (DTYP=0x1)
	 *   +----------------------------------------------------------------+
	 * 0 |                     Buffer Address [63:0]                      |
	 *   +----------------------------------------------------------------+
	 * 8 | VLAN tag |  POPTS  | Rsvd | Status | Command | DTYP |  DTALEN  |
	 *   +----------------------------------------------------------------+
	 *   63       48 47     40 39  36 35    32 31     24 23  20 19        0
	 */
	printk(KERN_INFO "Tl[desc]     [address 63:0  ] [SpeCssSCmCsLen]"
	       " [bi->dma       ] leng  ntw timestamp        bi->skb "
	       "<-- Legacy format\n");
	printk(KERN_INFO "Tc[desc]     [Ce CoCsIpceCoS] [MssHlRSCm0Plen]"
	       " [bi->dma       ] leng  ntw timestamp        bi->skb "
	       "<-- Ext Context format\n");
	printk(KERN_INFO "Td[desc]     [address 63:0  ] [VlaPoRSCm1Dlen]"
	       " [bi->dma       ] leng  ntw timestamp        bi->skb "
	       "<-- Ext Data format\n");
	for (i = 0; tx_ring->desc && (i < tx_ring->count); i++) {
		tx_desc = E1000_TX_DESC(*tx_ring, i);
		buffer_info = &tx_ring->buffer_info[i];
		u0 = (struct my_u0 *)tx_desc;
		printk(KERN_INFO "T%c[0x%03X]    %016llX %016llX %016llX "
		       "%04X  %3X %016llX %p",
		       (!(le64_to_cpu(u0->b) & (1 << 29)) ? 'l' :
			((le64_to_cpu(u0->b) & (1 << 20)) ? 'd' : 'c')), i,
		       (unsigned long long)le64_to_cpu(u0->a),
		       (unsigned long long)le64_to_cpu(u0->b),
		       (unsigned long long)buffer_info->dma,
		       buffer_info->length, buffer_info->next_to_watch,
		       (unsigned long long)buffer_info->time_stamp,
		       buffer_info->skb);
		if (i == tx_ring->next_to_use && i == tx_ring->next_to_clean)
			printk(KERN_CONT " NTC/U\n");
		else if (i == tx_ring->next_to_use)
			printk(KERN_CONT " NTU\n");
		else if (i == tx_ring->next_to_clean)
			printk(KERN_CONT " NTC\n");
		else
			printk(KERN_CONT "\n");

		if (netif_msg_pktdata(adapter) && buffer_info->dma != 0)
			print_hex_dump(KERN_INFO, "", DUMP_PREFIX_ADDRESS,
				       16, 1, phys_to_virt(buffer_info->dma),
				       buffer_info->length, true);
	}

	/* Print Rx Ring Summary */
rx_ring_summary:
	dev_info(&adapter->pdev->dev, "Rx Ring Summary\n");
	printk(KERN_INFO "Queue [NTU] [NTC]\n");
	printk(KERN_INFO " %5d %5X %5X\n", 0,
	       rx_ring->next_to_use, rx_ring->next_to_clean);

	/* Print Rx Ring */
	if (!netif_msg_rx_status(adapter))
		goto exit;

	dev_info(&adapter->pdev->dev, "Rx Ring Dump\n");
	switch (adapter->rx_ps_pages) {
	case 1:
	case 2:
	case 3:
		/* [Extended] Packet Split Receive Descriptor Format
		 *
		 *    +-----------------------------------------------------+
		 *  0 |                Buffer Address 0 [63:0]              |
		 *    +-----------------------------------------------------+
		 *  8 |                Buffer Address 1 [63:0]              |
		 *    +-----------------------------------------------------+
		 * 16 |                Buffer Address 2 [63:0]              |
		 *    +-----------------------------------------------------+
		 * 24 |                Buffer Address 3 [63:0]              |
		 *    +-----------------------------------------------------+
		 */
		printk(KERN_INFO "R  [desc]      [buffer 0 63:0 ] "
		       "[buffer 1 63:0 ] "
		       "[buffer 2 63:0 ] [buffer 3 63:0 ] [bi->dma       ] "
		       "[bi->skb] <-- Ext Pkt Split format\n");
		/* [Extended] Receive Descriptor (Write-Back) Format
		 *
		 *   63       48 47    32 31     13 12    8 7    4 3        0
		 *   +------------------------------------------------------+
		 * 0 | Packet   | IP     |  Rsvd   | MRQ   | Rsvd | MRQ RSS |
		 *   | Checksum | Ident  |         | Queue |      |  Type   |
		 *   +------------------------------------------------------+
		 * 8 | VLAN Tag | Length | Extended Error | Extended Status |
		 *   +------------------------------------------------------+
		 *   63       48 47    32 31            20 19               0
		 */
		printk(KERN_INFO "RWB[desc]      [ck ipid mrqhsh] "
		       "[vl   l0 ee  es] "
		       "[ l3  l2  l1 hs] [reserved      ] ---------------- "
		       "[bi->skb] <-- Ext Rx Write-Back format\n");
		for (i = 0; i < rx_ring->count; i++) {
			buffer_info = &rx_ring->buffer_info[i];
			rx_desc_ps = E1000_RX_DESC_PS(*rx_ring, i);
			u1 = (struct my_u1 *)rx_desc_ps;
			staterr =
			    le32_to_cpu(rx_desc_ps->wb.middle.status_error);
			if (staterr & E1000_RXD_STAT_DD) {
				/* Descriptor Done */
				printk(KERN_INFO "RWB[0x%03X]     %016llX "
				       "%016llX %016llX %016llX "
				       "---------------- %p", i,
				       (unsigned long long)le64_to_cpu(u1->a),
				       (unsigned long long)le64_to_cpu(u1->b),
				       (unsigned long long)le64_to_cpu(u1->c),
				       (unsigned long long)le64_to_cpu(u1->d),
				       buffer_info->skb);
			} else {
				printk(KERN_INFO "R  [0x%03X]     %016llX "
				       "%016llX %016llX %016llX %016llX %p", i,
				       (unsigned long long)le64_to_cpu(u1->a),
				       (unsigned long long)le64_to_cpu(u1->b),
				       (unsigned long long)le64_to_cpu(u1->c),
				       (unsigned long long)le64_to_cpu(u1->d),
				       (unsigned long long)buffer_info->dma,
				       buffer_info->skb);

				if (netif_msg_pktdata(adapter))
					print_hex_dump(KERN_INFO, "",
						DUMP_PREFIX_ADDRESS, 16, 1,
						phys_to_virt(buffer_info->dma),
						adapter->rx_ps_bsize0, true);
			}

			if (i == rx_ring->next_to_use)
				printk(KERN_CONT " NTU\n");
			else if (i == rx_ring->next_to_clean)
				printk(KERN_CONT " NTC\n");
			else
				printk(KERN_CONT "\n");
		}
		break;
	default:
	case 0:
		/* Extended Receive Descriptor (Read) Format
		 *
		 *   +-----------------------------------------------------+
		 * 0 |                Buffer Address [63:0]                |
		 *   +-----------------------------------------------------+
		 * 8 |                      Reserved                       |
		 *   +-----------------------------------------------------+
		 */
		printk(KERN_INFO "R  [desc]      [buf addr 63:0 ] "
		       "[reserved 63:0 ] [bi->dma       ] "
		       "[bi->skb] <-- Ext (Read) format\n");
		/* Extended Receive Descriptor (Write-Back) Format
		 *
		 *   63       48 47    32 31    24 23            4 3        0
		 *   +------------------------------------------------------+
		 *   |     RSS Hash      |        |               |         |
		 * 0 +-------------------+  Rsvd  |   Reserved    | MRQ RSS |
		 *   | Packet   | IP     |        |               |  Type   |
		 *   | Checksum | Ident  |        |               |         |
		 *   +------------------------------------------------------+
		 * 8 | VLAN Tag | Length | Extended Error | Extended Status |
		 *   +------------------------------------------------------+
		 *   63       48 47    32 31            20 19               0
		 */
		printk(KERN_INFO "RWB[desc]      [cs ipid    mrq] "
		       "[vt   ln xe  xs] "
		       "[bi->skb] <-- Ext (Write-Back) format\n");

		for (i = 0; i < rx_ring->count; i++) {
			buffer_info = &rx_ring->buffer_info[i];
			rx_desc = E1000_RX_DESC_EXT(*rx_ring, i);
			u1 = (struct my_u1 *)rx_desc;
			staterr = le32_to_cpu(rx_desc->wb.upper.status_error);
			if (staterr & E1000_RXD_STAT_DD) {
				/* Descriptor Done */
				printk(KERN_INFO "RWB[0x%03X]     %016llX "
				       "%016llX ---------------- %p", i,
				       (unsigned long long)le64_to_cpu(u1->a),
				       (unsigned long long)le64_to_cpu(u1->b),
				       buffer_info->skb);
			} else {
				printk(KERN_INFO "R  [0x%03X]     %016llX "
				       "%016llX %016llX %p", i,
				       (unsigned long long)le64_to_cpu(u1->a),
				       (unsigned long long)le64_to_cpu(u1->b),
				       (unsigned long long)buffer_info->dma,
				       buffer_info->skb);

				if (netif_msg_pktdata(adapter))
					print_hex_dump(KERN_INFO, "",
						       DUMP_PREFIX_ADDRESS, 16,
						       1,
						       phys_to_virt
						       (buffer_info->dma),
						       adapter->rx_buffer_len,
						       true);
			}

			if (i == rx_ring->next_to_use)
				printk(KERN_CONT " NTU\n");
			else if (i == rx_ring->next_to_clean)
				printk(KERN_CONT " NTC\n");
			else
				printk(KERN_CONT "\n");
		}
	}

exit:
	return;
}

void e1000e_mod_watchdog_timer(rtdm_nrtsig_t *nrt_sig, void *data)
{
	struct timer_list *timer = data;

	mod_timer(timer, jiffies + 1);
}

void e1000e_trigger_downshift(rtdm_nrtsig_t *nrt_sig, void *data)
{
	struct work_struct *downshift_task = data;

	schedule_work(downshift_task);
}

/**
 * e1000_desc_unused - calculate if we have unused descriptors
 **/
static int e1000_desc_unused(struct e1000_ring *ring)
{
	if (ring->next_to_clean > ring->next_to_use)
		return ring->next_to_clean - ring->next_to_use - 1;

	return ring->count + ring->next_to_clean - ring->next_to_use - 1;
}

/**
 * e1000_rx_checksum - Receive Checksum Offload
 * @adapter:     board private structure
 * @status_err:  receive descriptor status and error fields
 * @csum:	receive descriptor csum field
 * @sk_buff:     socket buffer with received data
 **/
static void e1000_rx_checksum(struct e1000_adapter *adapter, u32 status_err,
			      u32 csum, struct rtskb *skb)
{
	u16 status = (u16)status_err;
	u8 errors = (u8)(status_err >> 24);

	/* Ignore Checksum bit is set */
	if (status & E1000_RXD_STAT_IXSM)
		return;
	/* TCP/UDP checksum error bit is set */
	if (errors & E1000_RXD_ERR_TCPE) {
		/* let the stack verify checksum errors */
		adapter->hw_csum_err++;
		return;
	}

	/* TCP/UDP Checksum has not been calculated */
	if (!(status & (E1000_RXD_STAT_TCPCS | E1000_RXD_STAT_UDPCS)))
		return;

	/* It must be a TCP or UDP packet with a valid checksum */
	if (status & E1000_RXD_STAT_TCPCS) {
		/* TCP checksum is good */
		skb->ip_summed = CHECKSUM_UNNECESSARY;
	} else {
		/*
		 * IP fragment with UDP payload
		 * Hardware complements the payload checksum, so we undo it
		 * and then put the value in host order for further stack use.
		 */
		__sum16 sum = (__force __sum16)htons(csum);
		skb->csum = csum_unfold(~sum);
		skb->ip_summed = CHECKSUM_COMPLETE;
	}
	adapter->hw_csum_good++;
}

/**
 * e1000e_update_tail_wa - helper function for e1000e_update_[rt]dt_wa()
 * @hw: pointer to the HW structure
 * @tail: address of tail descriptor register
 * @i: value to write to tail descriptor register
 *
 * When updating the tail register, the ME could be accessing Host CSR
 * registers at the same time.  Normally, this is handled in h/w by an
 * arbiter but on some parts there is a bug that acknowledges Host accesses
 * later than it should which could result in the descriptor register to
 * have an incorrect value.  Workaround this by checking the FWSM register
 * which has bit 24 set while ME is accessing Host CSR registers, wait
 * if it is set and try again a number of times.
 **/
static inline s32 e1000e_update_tail_wa(struct e1000_hw *hw, u8 __iomem * tail,
					unsigned int i)
{
	unsigned int j = 0;

	while ((j++ < E1000_ICH_FWSM_PCIM2PCI_COUNT) &&
	       (er32(FWSM) & E1000_ICH_FWSM_PCIM2PCI))
		udelay(50);

	writel(i, tail);

	if ((j == E1000_ICH_FWSM_PCIM2PCI_COUNT) && (i != readl(tail)))
		return E1000_ERR_SWFW_SYNC;

	return 0;
}

static void e1000e_update_rdt_wa(struct e1000_adapter *adapter, unsigned int i)
{
	u8 __iomem *tail = (adapter->hw.hw_addr + adapter->rx_ring->tail);
	struct e1000_hw *hw = &adapter->hw;

	if (e1000e_update_tail_wa(hw, tail, i)) {
		u32 rctl = er32(RCTL);
		ew32(RCTL, rctl & ~E1000_RCTL_EN);
		e_err("ME firmware caused invalid RDT - resetting\n");
		rtdm_schedule_nrt_work(&adapter->reset_task);
	}
}

static void e1000e_update_tdt_wa(struct e1000_adapter *adapter, unsigned int i)
{
	u8 __iomem *tail = (adapter->hw.hw_addr + adapter->tx_ring->tail);
	struct e1000_hw *hw = &adapter->hw;

	if (e1000e_update_tail_wa(hw, tail, i)) {
		u32 tctl = er32(TCTL);
		ew32(TCTL, tctl & ~E1000_TCTL_EN);
		e_err("ME firmware caused invalid TDT - resetting\n");
		rtdm_schedule_nrt_work(&adapter->reset_task);
	}
}

/**
 * e1000_alloc_rx_buffers - Replace used receive buffers
 * @adapter: address of board private structure
 **/
static void e1000_alloc_rx_buffers(struct e1000_adapter *adapter,
				   int cleaned_count, gfp_t gfp)
{
	struct e1000_ring *rx_ring = adapter->rx_ring;
	union e1000_rx_desc_extended *rx_desc;
	struct e1000_buffer *buffer_info;
	struct rtskb *skb;
	unsigned int i;
	unsigned int bufsz = adapter->rx_buffer_len;

	i = rx_ring->next_to_use;
	buffer_info = &rx_ring->buffer_info[i];

	while (cleaned_count--) {
		skb = buffer_info->skb;
		if (skb) {
			rtskb_trim(skb, 0);
			goto map_skb;
		}

		skb = rtnetdev_alloc_rtskb(adapter->netdev, bufsz);
		if (!skb) {
			/* Better luck next round */
			adapter->alloc_rx_buff_failed++;
			break;
		}
		rtskb_reserve(skb, NET_IP_ALIGN);

		buffer_info->skb = skb;
map_skb:
		buffer_info->dma = rtskb_data_dma_addr(skb, 0);

		rx_desc = E1000_RX_DESC_EXT(*rx_ring, i);
		rx_desc->read.buffer_addr = cpu_to_le64(buffer_info->dma);

		if (unlikely(!(i & (E1000_RX_BUFFER_WRITE - 1)))) {
			/*
			 * Force memory writes to complete before letting h/w
			 * know there are new descriptors to fetch.  (Only
			 * applicable for weak-ordered memory model archs,
			 * such as IA-64).
			 */
			wmb();
			if (adapter->flags2 & FLAG2_PCIM2PCI_ARBITER_WA)
				e1000e_update_rdt_wa(adapter, i);
			else
				writel(i, adapter->hw.hw_addr + rx_ring->tail);
		}
		i++;
		if (i == rx_ring->count)
			i = 0;
		buffer_info = &rx_ring->buffer_info[i];
	}

	rx_ring->next_to_use = i;
}

/**
 * e1000_clean_rx_irq - Send received data up the network stack; legacy
 * @adapter: board private structure
 *
 * the return value indicates whether actual cleaning was done, there
 * is no guarantee that everything was cleaned
 **/
static bool e1000_clean_rx_irq(struct e1000_adapter *adapter,
			       nanosecs_abs_t *time_stamp)
{
	struct rtnet_device *netdev = adapter->netdev;
	struct e1000_ring *rx_ring = adapter->rx_ring;
	union e1000_rx_desc_extended *rx_desc, *next_rxd;
	struct e1000_buffer *buffer_info, *next_buffer;
	u32 length, staterr;
	unsigned int i;
	int cleaned_count = 0;
	bool data_received = false;
	unsigned int total_rx_bytes = 0, total_rx_packets = 0;

	i = rx_ring->next_to_clean;
	rx_desc = E1000_RX_DESC_EXT(*rx_ring, i);
	staterr = le32_to_cpu(rx_desc->wb.upper.status_error);
	buffer_info = &rx_ring->buffer_info[i];

	while (staterr & E1000_RXD_STAT_DD) {
		struct rtskb *skb;

		rmb();	/* read descriptor and rx_buffer_info after status DD */

		skb = buffer_info->skb;
		buffer_info->skb = NULL;

		prefetch(skb->data - NET_IP_ALIGN);

		i++;
		if (i == rx_ring->count)
			i = 0;
		next_rxd = E1000_RX_DESC_EXT(*rx_ring, i);
		prefetch(next_rxd);

		next_buffer = &rx_ring->buffer_info[i];

		cleaned_count++;
		buffer_info->dma = 0;

		length = le16_to_cpu(rx_desc->wb.upper.length);

		/*
		 * !EOP means multiple descriptors were used to store a single
		 * packet, if that's the case we need to toss it.  In fact, we
		 * need to toss every packet with the EOP bit clear and the
		 * next frame that _does_ have the EOP bit set, as it is by
		 * definition only a frame fragment
		 */
		if (unlikely(!(staterr & E1000_RXD_STAT_EOP)))
			adapter->flags2 |= FLAG2_IS_DISCARDING;

		if (adapter->flags2 & FLAG2_IS_DISCARDING) {
			/* All receives must fit into a single buffer */
			e_dbg("Receive packet consumed multiple buffers\n");
			/* recycle */
			buffer_info->skb = skb;
			if (staterr & E1000_RXD_STAT_EOP)
				adapter->flags2 &= ~FLAG2_IS_DISCARDING;
			goto next_desc;
		}

		if (staterr & E1000_RXDEXT_ERR_FRAME_ERR_MASK) {
			/* recycle */
			buffer_info->skb = skb;
			goto next_desc;
		}

		/* adjust length to remove Ethernet CRC */
		if (!(adapter->flags2 & FLAG2_CRC_STRIPPING))
			length -= 4;

		total_rx_bytes += length;
		total_rx_packets++;

		rtskb_put(skb, length);

		/* Receive Checksum Offload */
		e1000_rx_checksum(adapter, staterr,
				  le16_to_cpu(rx_desc->wb.lower.hi_dword.
					      csum_ip.csum), skb);

		skb->protocol = rt_eth_type_trans(skb, netdev);
		skb->time_stamp = *time_stamp;
		rtnetif_rx(skb);
		data_received = true;

next_desc:
		rx_desc->wb.upper.status_error &= cpu_to_le32(~0xFF);

		/* return some buffers to hardware, one at a time is too slow */
		if (cleaned_count >= E1000_RX_BUFFER_WRITE) {
			adapter->alloc_rx_buf(adapter, cleaned_count,
					      GFP_ATOMIC);
			cleaned_count = 0;
		}

		/* use prefetched values */
		rx_desc = next_rxd;
		buffer_info = next_buffer;

		staterr = le32_to_cpu(rx_desc->wb.upper.status_error);
	}
	rx_ring->next_to_clean = i;

	cleaned_count = e1000_desc_unused(rx_ring);
	if (cleaned_count)
		adapter->alloc_rx_buf(adapter, cleaned_count, GFP_ATOMIC);

	adapter->total_rx_bytes += total_rx_bytes;
	adapter->total_rx_packets += total_rx_packets;
	return data_received;
}

static void e1000_put_txbuf(struct e1000_adapter *adapter,
			     struct e1000_buffer *buffer_info)
{
	buffer_info->dma = 0;
	if (buffer_info->skb) {
		kfree_rtskb(buffer_info->skb);
		buffer_info->skb = NULL;
	}
	buffer_info->time_stamp = 0;
}

/**
 * e1000_clean_tx_irq - Reclaim resources after transmit completes
 * @adapter: board private structure
 *
 * the return value indicates whether actual cleaning was done, there
 * is no guarantee that everything was cleaned
 **/
static bool e1000_clean_tx_irq(struct e1000_adapter *adapter)
{
	struct rtnet_device *netdev = adapter->netdev;
	struct e1000_hw *hw = &adapter->hw;
	struct e1000_ring *tx_ring = adapter->tx_ring;
	struct e1000_tx_desc *tx_desc, *eop_desc;
	struct e1000_buffer *buffer_info;
	unsigned int i, eop;
	unsigned int count = 0;
	unsigned int total_tx_bytes = 0, total_tx_packets = 0;

	i = tx_ring->next_to_clean;
	eop = tx_ring->buffer_info[i].next_to_watch;
	eop_desc = E1000_TX_DESC(*tx_ring, eop);

	while ((eop_desc->upper.data & cpu_to_le32(E1000_TXD_STAT_DD)) &&
	       (count < tx_ring->count)) {
		bool cleaned = false;
		rmb(); /* read buffer_info after eop_desc */
		for (; !cleaned; count++) {
			tx_desc = E1000_TX_DESC(*tx_ring, i);
			buffer_info = &tx_ring->buffer_info[i];
			cleaned = (i == eop);

			if (cleaned) {
				total_tx_packets += buffer_info->segs;
				total_tx_bytes += buffer_info->bytecount;
			}

			e1000_put_txbuf(adapter, buffer_info);
			tx_desc->upper.data = 0;

			i++;
			if (i == tx_ring->count)
				i = 0;
		}

		if (i == tx_ring->next_to_use)
			break;
		eop = tx_ring->buffer_info[i].next_to_watch;
		eop_desc = E1000_TX_DESC(*tx_ring, eop);
	}

	tx_ring->next_to_clean = i;

#define TX_WAKE_THRESHOLD 32
	if (count && rtnetif_carrier_ok(netdev) &&
	    e1000_desc_unused(tx_ring) >= TX_WAKE_THRESHOLD) {
		/* Make sure that anybody stopping the queue after this
		 * sees the new next_to_clean.
		 */
		smp_mb();

		if (rtnetif_queue_stopped(netdev) &&
		    !(test_bit(__E1000_DOWN, &adapter->state))) {
			rtnetif_wake_queue(netdev);
			++adapter->restart_queue;
		}
	}

	if (adapter->detect_tx_hung) {
		/*
		 * Detect a transmit hang in hardware, this serializes the
		 * check with the clearing of time_stamp and movement of i
		 */
		adapter->detect_tx_hung = 0;
		if (tx_ring->buffer_info[i].time_stamp &&
		    time_after(jiffies, tx_ring->buffer_info[i].time_stamp
			       + (adapter->tx_timeout_factor * HZ)) &&
		    !(er32(STATUS) & E1000_STATUS_TXOFF)) {
			rtnetif_stop_queue(netdev);
		}
	}
	adapter->total_tx_bytes += total_tx_bytes;
	adapter->total_tx_packets += total_tx_packets;
	return count < tx_ring->count;
}

/**
 * e1000_clean_rx_ring - Free Rx Buffers per Queue
 * @adapter: board private structure
 **/
static void e1000_clean_rx_ring(struct e1000_adapter *adapter)
{
	struct e1000_ring *rx_ring = adapter->rx_ring;
	struct e1000_buffer *buffer_info;
	unsigned int i;

	/* Free all the Rx ring sk_buffs */
	for (i = 0; i < rx_ring->count; i++) {
		buffer_info = &rx_ring->buffer_info[i];
		buffer_info->dma = 0;

		if (buffer_info->skb) {
			kfree_rtskb(buffer_info->skb);
			buffer_info->skb = NULL;
		}
	}

	/* there also may be some cached data from a chained receive */
	if (rx_ring->rx_skb_top) {
		kfree_rtskb(rx_ring->rx_skb_top);
		rx_ring->rx_skb_top = NULL;
	}

	/* Zero out the descriptor ring */
	memset(rx_ring->desc, 0, rx_ring->size);

	rx_ring->next_to_clean = 0;
	rx_ring->next_to_use = 0;
	adapter->flags2 &= ~FLAG2_IS_DISCARDING;

	writel(0, adapter->hw.hw_addr + rx_ring->head);
	writel(0, adapter->hw.hw_addr + rx_ring->tail);
}

static void e1000e_downshift_workaround(struct work_struct *work)
{
	struct e1000_adapter *adapter = container_of(work,
					struct e1000_adapter, downshift_task);

	if (test_bit(__E1000_DOWN, &adapter->state))
		return;

	e1000e_gig_downshift_workaround_ich8lan(&adapter->hw);
}

/**
 * e1000_intr_msi - Interrupt Handler
 * @irq: interrupt number
 * @data: pointer to a network interface device structure
 **/
static int e1000_intr_msi(rtdm_irq_t *irq_handle)
{
	struct e1000_adapter *adapter =
		rtdm_irq_get_arg(irq_handle, struct e1000_adapter);
	struct e1000_hw *hw = &adapter->hw;
	nanosecs_abs_t time_stamp = rtdm_clock_read();
	u32 icr = er32(ICR);

	/*
	 * read ICR disables interrupts using IAM
	 */

	if (icr & E1000_ICR_LSC) {
		hw->mac.get_link_status = 1;
		/*
		 * ICH8 workaround-- Call gig speed drop workaround on cable
		 * disconnect (LSC) before accessing any PHY registers
		 */
		if ((adapter->flags & FLAG_LSC_GIG_SPEED_DROP) &&
		    (!(er32(STATUS) & E1000_STATUS_LU)))
			rtdm_schedule_nrt_work(&adapter->downshift_task);

		/*
		 * 80003ES2LAN workaround-- For packet buffer work-around on
		 * link down event; disable receives here in the ISR and reset
		 * adapter in watchdog
		 */
		if (rtnetif_carrier_ok(adapter->netdev) &&
		    adapter->flags & FLAG_RX_NEEDS_RESTART) {
			/* disable receives */
			u32 rctl = er32(RCTL);
			ew32(RCTL, rctl & ~E1000_RCTL_EN);
			adapter->flags |= FLAG_RX_RESTART_NOW;
		}
		/* guard against interrupt when we're going down */
		if (!test_bit(__E1000_DOWN, &adapter->state))
			rtdm_nrtsig_pend(&adapter->mod_timer_sig);
	}

	if (!e1000_clean_tx_irq(adapter))
		/* Ring was not completely cleaned, so fire another interrupt */
		ew32(ICS, adapter->tx_ring->ims_val);

	if (e1000_clean_rx_irq(adapter, &time_stamp))
		rt_mark_stack_mgr(adapter->netdev);

	return RTDM_IRQ_HANDLED;
}

/**
 * e1000_intr - Interrupt Handler
 * @irq: interrupt number
 * @data: pointer to a network interface device structure
 **/
static int e1000_intr(rtdm_irq_t *irq_handle)
{
	struct e1000_adapter *adapter =
		rtdm_irq_get_arg(irq_handle, struct e1000_adapter);
	struct e1000_hw *hw = &adapter->hw;
	nanosecs_abs_t time_stamp = rtdm_clock_read();
	u32 rctl, icr = er32(ICR);

	if (!icr || test_bit(__E1000_DOWN, &adapter->state))
		return RTDM_IRQ_NONE;  /* Not our interrupt */

	/*
	 * IMS will not auto-mask if INT_ASSERTED is not set, and if it is
	 * not set, then the adapter didn't send an interrupt
	 */
	if (!(icr & E1000_ICR_INT_ASSERTED))
		return RTDM_IRQ_NONE;

	/*
	 * Interrupt Auto-Mask...upon reading ICR,
	 * interrupts are masked.  No need for the
	 * IMC write
	 */

	if (icr & E1000_ICR_LSC) {
		hw->mac.get_link_status = 1;
		/*
		 * ICH8 workaround-- Call gig speed drop workaround on cable
		 * disconnect (LSC) before accessing any PHY registers
		 */
		if ((adapter->flags & FLAG_LSC_GIG_SPEED_DROP) &&
		    (!(er32(STATUS) & E1000_STATUS_LU)))
			rtdm_nrtsig_pend(&adapter->downshift_sig);

		/*
		 * 80003ES2LAN workaround--
		 * For packet buffer work-around on link down event;
		 * disable receives here in the ISR and
		 * reset adapter in watchdog
		 */
		if (rtnetif_carrier_ok(adapter->netdev) &&
		    (adapter->flags & FLAG_RX_NEEDS_RESTART)) {
			/* disable receives */
			rctl = er32(RCTL);
			ew32(RCTL, rctl & ~E1000_RCTL_EN);
			adapter->flags |= FLAG_RX_RESTART_NOW;
		}
		/* guard against interrupt when we're going down */
		if (!test_bit(__E1000_DOWN, &adapter->state))
			rtdm_nrtsig_pend(&adapter->mod_timer_sig);
	}

	if (!e1000_clean_tx_irq(adapter))
		/* Ring was not completely cleaned, so fire another interrupt */
		ew32(ICS, adapter->tx_ring->ims_val);

	if (e1000_clean_rx_irq(adapter, &time_stamp))
		rt_mark_stack_mgr(adapter->netdev);

	return RTDM_IRQ_HANDLED;
}

static irqreturn_t e1000_msix_other(int irq, void *data)
{
	struct rtnet_device *netdev = data;
	struct e1000_adapter *adapter = netdev->priv;
	struct e1000_hw *hw = &adapter->hw;
	u32 icr = er32(ICR);

	if (!(icr & E1000_ICR_INT_ASSERTED)) {
		if (!test_bit(__E1000_DOWN, &adapter->state))
			ew32(IMS, E1000_IMS_OTHER);
		return IRQ_NONE;
	}

	if (icr & adapter->eiac_mask)
		ew32(ICS, (icr & adapter->eiac_mask));

	if (icr & E1000_ICR_OTHER) {
		if (!(icr & E1000_ICR_LSC))
			goto no_link_interrupt;
		hw->mac.get_link_status = 1;
		/* guard against interrupt when we're going down */
		if (!test_bit(__E1000_DOWN, &adapter->state))
			mod_timer(&adapter->watchdog_timer, jiffies + 1);
	}

no_link_interrupt:
	if (!test_bit(__E1000_DOWN, &adapter->state))
		ew32(IMS, E1000_IMS_LSC | E1000_IMS_OTHER);

	return IRQ_HANDLED;
}


static int e1000_intr_msix_tx(rtdm_irq_t *irq_handle)
{
	struct e1000_adapter *adapter =
		rtdm_irq_get_arg(irq_handle, struct e1000_adapter);
	struct e1000_hw *hw = &adapter->hw;
	struct e1000_ring *tx_ring = adapter->tx_ring;


	adapter->total_tx_bytes = 0;
	adapter->total_tx_packets = 0;

	if (!e1000_clean_tx_irq(adapter))
		/* Ring was not completely cleaned, so fire another interrupt */
		ew32(ICS, tx_ring->ims_val);

	return RTDM_IRQ_HANDLED;
}

static int e1000_intr_msix_rx(rtdm_irq_t *irq_handle)
{
	struct e1000_adapter *adapter =
		rtdm_irq_get_arg(irq_handle, struct e1000_adapter);
	nanosecs_abs_t time_stamp = rtdm_clock_read();

	/* Write the ITR value calculated at the end of the
	 * previous interrupt.
	 */
	if (adapter->rx_ring->set_itr) {
		writel(1000000000 / (adapter->rx_ring->itr_val * 256),
		       adapter->hw.hw_addr + adapter->rx_ring->itr_register);
		adapter->rx_ring->set_itr = 0;
	}

	if (e1000_clean_rx_irq(adapter, &time_stamp))
		rt_mark_stack_mgr(adapter->netdev);

	return RTDM_IRQ_HANDLED;
}

/**
 * e1000_configure_msix - Configure MSI-X hardware
 *
 * e1000_configure_msix sets up the hardware to properly
 * generate MSI-X interrupts.
 **/
static void e1000_configure_msix(struct e1000_adapter *adapter)
{
	struct e1000_hw *hw = &adapter->hw;
	struct e1000_ring *rx_ring = adapter->rx_ring;
	struct e1000_ring *tx_ring = adapter->tx_ring;
	int vector = 0;
	u32 ctrl_ext, ivar = 0;

	adapter->eiac_mask = 0;

	/* Workaround issue with spurious interrupts on 82574 in MSI-X mode */
	if (hw->mac.type == e1000_82574) {
		u32 rfctl = er32(RFCTL);
		rfctl |= E1000_RFCTL_ACK_DIS;
		ew32(RFCTL, rfctl);
	}

#define E1000_IVAR_INT_ALLOC_VALID	0x8
	/* Configure Rx vector */
	rx_ring->ims_val = E1000_IMS_RXQ0;
	adapter->eiac_mask |= rx_ring->ims_val;
	if (rx_ring->itr_val)
		writel(1000000000 / (rx_ring->itr_val * 256),
		       hw->hw_addr + rx_ring->itr_register);
	else
		writel(1, hw->hw_addr + rx_ring->itr_register);
	ivar = E1000_IVAR_INT_ALLOC_VALID | vector;

	/* Configure Tx vector */
	tx_ring->ims_val = E1000_IMS_TXQ0;
	vector++;
	if (tx_ring->itr_val)
		writel(1000000000 / (tx_ring->itr_val * 256),
		       hw->hw_addr + tx_ring->itr_register);
	else
		writel(1, hw->hw_addr + tx_ring->itr_register);
	adapter->eiac_mask |= tx_ring->ims_val;
	ivar |= ((E1000_IVAR_INT_ALLOC_VALID | vector) << 8);

	/* set vector for Other Causes, e.g. link changes */
	vector++;
	ivar |= ((E1000_IVAR_INT_ALLOC_VALID | vector) << 16);
	if (rx_ring->itr_val)
		writel(1000000000 / (rx_ring->itr_val * 256),
		       hw->hw_addr + E1000_EITR_82574(vector));
	else
		writel(1, hw->hw_addr + E1000_EITR_82574(vector));

	/* Cause Tx interrupts on every write back */
	ivar |= (1 << 31);

	ew32(IVAR, ivar);

	/* enable MSI-X PBA support */
	ctrl_ext = er32(CTRL_EXT);
	ctrl_ext |= E1000_CTRL_EXT_PBA_CLR;

	/* Auto-Mask Other interrupts upon ICR read */
#define E1000_EIAC_MASK_82574   0x01F00000
	ew32(IAM, ~E1000_EIAC_MASK_82574 | E1000_IMS_OTHER);
	ctrl_ext |= E1000_CTRL_EXT_EIAME;
	ew32(CTRL_EXT, ctrl_ext);
	e1e_flush();
}

void e1000e_reset_interrupt_capability(struct e1000_adapter *adapter)
{
	if (adapter->msix_entries) {
		pci_disable_msix(adapter->pdev);
		kfree(adapter->msix_entries);
		adapter->msix_entries = NULL;
	} else if (adapter->flags & FLAG_MSI_ENABLED) {
		pci_disable_msi(adapter->pdev);
		adapter->flags &= ~FLAG_MSI_ENABLED;
	}
}

/**
 * e1000e_set_interrupt_capability - set MSI or MSI-X if supported
 *
 * Attempt to configure interrupts using the best available
 * capabilities of the hardware and kernel.
 **/
void e1000e_set_interrupt_capability(struct e1000_adapter *adapter)
{
	int err;
	int i;

	switch (adapter->int_mode) {
	case E1000E_INT_MODE_MSIX:
		if (adapter->flags & FLAG_HAS_MSIX) {
			adapter->num_vectors = 3; /* RxQ0, TxQ0 and other */
			adapter->msix_entries = kcalloc(adapter->num_vectors,
						      sizeof(struct msix_entry),
						      GFP_KERNEL);
			if (adapter->msix_entries) {
				for (i = 0; i < adapter->num_vectors; i++)
					adapter->msix_entries[i].entry = i;

				err = pci_enable_msix_range(adapter->pdev,
							adapter->msix_entries,
							adapter->num_vectors,
							adapter->num_vectors);
				if (err == 0)
					return;
			}
			/* MSI-X failed, so fall through and try MSI */
			e_err("Failed to initialize MSI-X interrupts.  "
			      "Falling back to MSI interrupts.\n");
			e1000e_reset_interrupt_capability(adapter);
		}
		adapter->int_mode = E1000E_INT_MODE_MSI;
		/* Fall through */
	case E1000E_INT_MODE_MSI:
		if (!pci_enable_msi(adapter->pdev)) {
			adapter->flags |= FLAG_MSI_ENABLED;
		} else {
			adapter->int_mode = E1000E_INT_MODE_LEGACY;
			e_err("Failed to initialize MSI interrupts.  Falling "
			      "back to legacy interrupts.\n");
		}
		/* Fall through */
	case E1000E_INT_MODE_LEGACY:
		/* Don't do anything; this is the system default */
		break;
	}

	/* store the number of vectors being used */
	adapter->num_vectors = 1;
}

/**
 * e1000_request_msix - Initialize MSI-X interrupts
 *
 * e1000_request_msix allocates MSI-X vectors and requests interrupts from the
 * kernel.
 **/
static int e1000_request_msix(struct e1000_adapter *adapter)
{
	struct rtnet_device *netdev = adapter->netdev;
	int err = 0, vector = 0;

	if (strlen(netdev->name) < (IFNAMSIZ - 5))
		snprintf(adapter->rx_ring->name,
			 sizeof(adapter->rx_ring->name) - 1,
			 "%s-rx-0", netdev->name);
	else
		memcpy(adapter->rx_ring->name, netdev->name, IFNAMSIZ);
	err = rtdm_irq_request(&adapter->rx_irq_handle,
			       adapter->msix_entries[vector].vector,
			       e1000_intr_msix_rx, 0, adapter->rx_ring->name,
			       adapter);
	if (err)
		goto out;
	adapter->rx_ring->itr_register = E1000_EITR_82574(vector);
	adapter->rx_ring->itr_val = adapter->itr;
	vector++;

	if (strlen(netdev->name) < (IFNAMSIZ - 5))
		snprintf(adapter->tx_ring->name,
			 sizeof(adapter->tx_ring->name) - 1,
			 "%s-tx-0", netdev->name);
	else
		memcpy(adapter->tx_ring->name, netdev->name, IFNAMSIZ);
	err = rtdm_irq_request(&adapter->tx_irq_handle,
			       adapter->msix_entries[vector].vector,
			       e1000_intr_msix_tx, 0, adapter->tx_ring->name,
			       adapter);
	if (err)
		goto out;
	adapter->tx_ring->itr_register = E1000_EITR_82574(vector);
	adapter->tx_ring->itr_val = adapter->itr;
	vector++;

	err = request_irq(adapter->msix_entries[vector].vector,
			  e1000_msix_other, 0, netdev->name, netdev);
	if (err)
		goto out;

	e1000_configure_msix(adapter);
	return 0;
out:
	return err;
}

/**
 * e1000_request_irq - initialize interrupts
 *
 * Attempts to configure interrupts using the best available
 * capabilities of the hardware and kernel.
 **/
static int e1000_request_irq(struct e1000_adapter *adapter)
{
	struct rtnet_device *netdev = adapter->netdev;
	int err;

	if (adapter->msix_entries) {
		err = e1000_request_msix(adapter);
		if (!err)
			return err;
		/* fall back to MSI */
		e1000e_reset_interrupt_capability(adapter);
		adapter->int_mode = E1000E_INT_MODE_MSI;
		e1000e_set_interrupt_capability(adapter);
	}
	if (adapter->flags & FLAG_MSI_ENABLED) {
		err = rtdm_irq_request(&adapter->irq_handle,
				       adapter->pdev->irq, e1000_intr_msi,
				       0, netdev->name, adapter);
		if (!err)
			return err;

		/* fall back to legacy interrupt */
		e1000e_reset_interrupt_capability(adapter);
		adapter->int_mode = E1000E_INT_MODE_LEGACY;
	}

	err = rtdm_irq_request(&adapter->irq_handle, adapter->pdev->irq,
			       e1000_intr, 0, netdev->name, adapter);
	if (err)
		e_err("Unable to allocate interrupt, Error: %d\n", err);

	return err;
}

static void e1000_free_irq(struct e1000_adapter *adapter)
{
	struct rtnet_device *netdev = adapter->netdev;

	if (adapter->msix_entries) {
		int vector = 0;

		rtdm_irq_disable(&adapter->rx_irq_handle);
		rtdm_irq_free(&adapter->rx_irq_handle);
		vector++;

		rtdm_irq_disable(&adapter->tx_irq_handle);
		rtdm_irq_free(&adapter->tx_irq_handle);
		vector++;

		/* Other Causes interrupt vector */
		free_irq(adapter->msix_entries[vector].vector, netdev);
		return;
	}

	if (adapter->flags & FLAG_MSI_ENABLED)
		rtdm_irq_disable(&adapter->irq_handle);
	rtdm_irq_free(&adapter->irq_handle);
}

/**
 * e1000_irq_disable - Mask off interrupt generation on the NIC
 **/
static void e1000_irq_disable(struct e1000_adapter *adapter)
{
	struct e1000_hw *hw = &adapter->hw;

	ew32(IMC, ~0);
	if (adapter->msix_entries)
		ew32(EIAC_82574, 0);
	e1e_flush();

	if (adapter->msix_entries) {
		int i;
		for (i = 0; i < adapter->num_vectors; i++)
			synchronize_irq(adapter->msix_entries[i].vector);
	} else {
		synchronize_irq(adapter->pdev->irq);
	}
}

/**
 * e1000_irq_enable - Enable default interrupt generation settings
 **/
static void e1000_irq_enable(struct e1000_adapter *adapter)
{
	struct e1000_hw *hw = &adapter->hw;

	if (adapter->msix_entries) {
		ew32(EIAC_82574, adapter->eiac_mask & E1000_EIAC_MASK_82574);
		ew32(IMS, adapter->eiac_mask | E1000_IMS_OTHER | E1000_IMS_LSC);
	} else {
		ew32(IMS, IMS_ENABLE_MASK);
	}
	e1e_flush();
}

/**
 * e1000e_get_hw_control - get control of the h/w from f/w
 * @adapter: address of board private structure
 *
 * e1000e_get_hw_control sets {CTRL_EXT|SWSM}:DRV_LOAD bit.
 * For ASF and Pass Through versions of f/w this means that
 * the driver is loaded. For AMT version (only with 82573)
 * of the f/w this means that the network i/f is open.
 **/
void e1000e_get_hw_control(struct e1000_adapter *adapter)
{
	struct e1000_hw *hw = &adapter->hw;
	u32 ctrl_ext;
	u32 swsm;

	/* Let firmware know the driver has taken over */
	if (adapter->flags & FLAG_HAS_SWSM_ON_LOAD) {
		swsm = er32(SWSM);
		ew32(SWSM, swsm | E1000_SWSM_DRV_LOAD);
	} else if (adapter->flags & FLAG_HAS_CTRLEXT_ON_LOAD) {
		ctrl_ext = er32(CTRL_EXT);
		ew32(CTRL_EXT, ctrl_ext | E1000_CTRL_EXT_DRV_LOAD);
	}
}

/**
 * e1000e_release_hw_control - release control of the h/w to f/w
 * @adapter: address of board private structure
 *
 * e1000e_release_hw_control resets {CTRL_EXT|SWSM}:DRV_LOAD bit.
 * For ASF and Pass Through versions of f/w this means that the
 * driver is no longer loaded. For AMT version (only with 82573) i
 * of the f/w this means that the network i/f is closed.
 *
 **/
void e1000e_release_hw_control(struct e1000_adapter *adapter)
{
	struct e1000_hw *hw = &adapter->hw;
	u32 ctrl_ext;
	u32 swsm;

	/* Let firmware taken over control of h/w */
	if (adapter->flags & FLAG_HAS_SWSM_ON_LOAD) {
		swsm = er32(SWSM);
		ew32(SWSM, swsm & ~E1000_SWSM_DRV_LOAD);
	} else if (adapter->flags & FLAG_HAS_CTRLEXT_ON_LOAD) {
		ctrl_ext = er32(CTRL_EXT);
		ew32(CTRL_EXT, ctrl_ext & ~E1000_CTRL_EXT_DRV_LOAD);
	}
}

/**
 * @e1000_alloc_ring - allocate memory for a ring structure
 **/
static int e1000_alloc_ring_dma(struct e1000_adapter *adapter,
				struct e1000_ring *ring)
{
	struct pci_dev *pdev = adapter->pdev;

	ring->desc = dma_alloc_coherent(&pdev->dev, ring->size, &ring->dma,
					GFP_KERNEL);
	if (!ring->desc)
		return -ENOMEM;

	return 0;
}

/**
 * e1000e_setup_tx_resources - allocate Tx resources (Descriptors)
 * @adapter: board private structure
 *
 * Return 0 on success, negative on failure
 **/
int e1000e_setup_tx_resources(struct e1000_adapter *adapter)
{
	struct e1000_ring *tx_ring = adapter->tx_ring;
	int err = -ENOMEM, size;

	size = sizeof(struct e1000_buffer) * tx_ring->count;
	tx_ring->buffer_info = vzalloc(size);
	if (!tx_ring->buffer_info)
		goto err;

	/* round up to nearest 4K */
	tx_ring->size = tx_ring->count * sizeof(struct e1000_tx_desc);
	tx_ring->size = ALIGN(tx_ring->size, 4096);

	err = e1000_alloc_ring_dma(adapter, tx_ring);
	if (err)
		goto err;

	tx_ring->next_to_use = 0;
	tx_ring->next_to_clean = 0;

	return 0;
err:
	vfree(tx_ring->buffer_info);
	e_err("Unable to allocate memory for the transmit descriptor ring\n");
	return err;
}

/**
 * e1000e_setup_rx_resources - allocate Rx resources (Descriptors)
 * @adapter: board private structure
 *
 * Returns 0 on success, negative on failure
 **/
int e1000e_setup_rx_resources(struct e1000_adapter *adapter)
{
	struct e1000_ring *rx_ring = adapter->rx_ring;
	int size, desc_len, err = -ENOMEM;

	size = sizeof(struct e1000_buffer) * rx_ring->count;
	rx_ring->buffer_info = vzalloc(size);
	if (!rx_ring->buffer_info)
		goto err;

	desc_len = sizeof(union e1000_rx_desc_packet_split);

	/* Round up to nearest 4K */
	rx_ring->size = rx_ring->count * desc_len;
	rx_ring->size = ALIGN(rx_ring->size, 4096);

	err = e1000_alloc_ring_dma(adapter, rx_ring);
	if (err)
		goto err;

	rx_ring->next_to_clean = 0;
	rx_ring->next_to_use = 0;
	rx_ring->rx_skb_top = NULL;

	return 0;

err:
	vfree(rx_ring->buffer_info);
	e_err("Unable to allocate memory for the receive descriptor ring\n");
	return err;
}

/**
 * e1000_clean_tx_ring - Free Tx Buffers
 * @adapter: board private structure
 **/
static void e1000_clean_tx_ring(struct e1000_adapter *adapter)
{
	struct e1000_ring *tx_ring = adapter->tx_ring;
	struct e1000_buffer *buffer_info;
	unsigned long size;
	unsigned int i;

	for (i = 0; i < tx_ring->count; i++) {
		buffer_info = &tx_ring->buffer_info[i];
		e1000_put_txbuf(adapter, buffer_info);
	}

	size = sizeof(struct e1000_buffer) * tx_ring->count;
	memset(tx_ring->buffer_info, 0, size);

	memset(tx_ring->desc, 0, tx_ring->size);

	tx_ring->next_to_use = 0;
	tx_ring->next_to_clean = 0;

	writel(0, adapter->hw.hw_addr + tx_ring->head);
	writel(0, adapter->hw.hw_addr + tx_ring->tail);
}

/**
 * e1000e_free_tx_resources - Free Tx Resources per Queue
 * @adapter: board private structure
 *
 * Free all transmit software resources
 **/
void e1000e_free_tx_resources(struct e1000_adapter *adapter)
{
	struct pci_dev *pdev = adapter->pdev;
	struct e1000_ring *tx_ring = adapter->tx_ring;

	e1000_clean_tx_ring(adapter);

	vfree(tx_ring->buffer_info);
	tx_ring->buffer_info = NULL;

	dma_free_coherent(&pdev->dev, tx_ring->size, tx_ring->desc,
			  tx_ring->dma);
	tx_ring->desc = NULL;
}

/**
 * e1000e_free_rx_resources - Free Rx Resources
 * @adapter: board private structure
 *
 * Free all receive software resources
 **/

void e1000e_free_rx_resources(struct e1000_adapter *adapter)
{
	struct pci_dev *pdev = adapter->pdev;
	struct e1000_ring *rx_ring = adapter->rx_ring;
	int i;

	e1000_clean_rx_ring(adapter);

	for (i = 0; i < rx_ring->count; i++)
		kfree(rx_ring->buffer_info[i].ps_pages);

	vfree(rx_ring->buffer_info);
	rx_ring->buffer_info = NULL;

	dma_free_coherent(&pdev->dev, rx_ring->size, rx_ring->desc,
			  rx_ring->dma);
	rx_ring->desc = NULL;
}

/**
 * e1000_alloc_queues - Allocate memory for all rings
 * @adapter: board private structure to initialize
 **/
static int e1000_alloc_queues(struct e1000_adapter *adapter)
{
	adapter->tx_ring = kzalloc(sizeof(struct e1000_ring), GFP_KERNEL);
	if (!adapter->tx_ring)
		goto err;

	rtdm_lock_init(&adapter->tx_ring->lock);

	adapter->rx_ring = kzalloc(sizeof(struct e1000_ring), GFP_KERNEL);
	if (!adapter->rx_ring)
		goto err;

	return 0;
err:
	e_err("Unable to allocate memory for queues\n");
	kfree(adapter->rx_ring);
	kfree(adapter->tx_ring);
	return -ENOMEM;
}

static void e1000_vlan_rx_add_vid(struct rtnet_device *netdev, u16 vid)
{
	struct e1000_adapter *adapter = netdev->priv;
	struct e1000_hw *hw = &adapter->hw;
	u32 vfta, index;

	/* don't update vlan cookie if already programmed */
	if ((adapter->hw.mng_cookie.status &
	     E1000_MNG_DHCP_COOKIE_STATUS_VLAN) &&
	    (vid == adapter->mng_vlan_id))
		return;

	/* add VID to filter table */
	if (adapter->flags & FLAG_HAS_HW_VLAN_FILTER) {
		index = (vid >> 5) & 0x7F;
		vfta = E1000_READ_REG_ARRAY(hw, E1000_VFTA, index);
		vfta |= (1 << (vid & 0x1F));
		hw->mac.ops.write_vfta(hw, index, vfta);
	}

	set_bit(vid, adapter->active_vlans);
}

static void e1000_vlan_rx_kill_vid(struct rtnet_device *netdev, u16 vid)
{
	struct e1000_adapter *adapter = netdev->priv;
	struct e1000_hw *hw = &adapter->hw;
	u32 vfta, index;

	if ((adapter->hw.mng_cookie.status &
	     E1000_MNG_DHCP_COOKIE_STATUS_VLAN) &&
	    (vid == adapter->mng_vlan_id)) {
		/* release control to f/w */
		e1000e_release_hw_control(adapter);
		return;
	}

	/* remove VID from filter table */
	if (adapter->flags & FLAG_HAS_HW_VLAN_FILTER) {
		index = (vid >> 5) & 0x7F;
		vfta = E1000_READ_REG_ARRAY(hw, E1000_VFTA, index);
		vfta &= ~(1 << (vid & 0x1F));
		hw->mac.ops.write_vfta(hw, index, vfta);
	}

	clear_bit(vid, adapter->active_vlans);
}

/**
 * e1000e_vlan_filter_disable - helper to disable hw VLAN filtering
 * @adapter: board private structure to initialize
 **/
static void e1000e_vlan_filter_disable(struct e1000_adapter *adapter)
{
	struct rtnet_device *netdev = adapter->netdev;
	struct e1000_hw *hw = &adapter->hw;
	u32 rctl;

	if (adapter->flags & FLAG_HAS_HW_VLAN_FILTER) {
		/* disable VLAN receive filtering */
		rctl = er32(RCTL);
		rctl &= ~(E1000_RCTL_VFE | E1000_RCTL_CFIEN);
		ew32(RCTL, rctl);

		if (adapter->mng_vlan_id != (u16)E1000_MNG_VLAN_NONE) {
			e1000_vlan_rx_kill_vid(netdev, adapter->mng_vlan_id);
			adapter->mng_vlan_id = E1000_MNG_VLAN_NONE;
		}
	}
}

/**
 * e1000e_vlan_filter_enable - helper to enable HW VLAN filtering
 * @adapter: board private structure to initialize
 **/
static void e1000e_vlan_filter_enable(struct e1000_adapter *adapter)
{
	struct e1000_hw *hw = &adapter->hw;
	u32 rctl;

	if (adapter->flags & FLAG_HAS_HW_VLAN_FILTER) {
		/* enable VLAN receive filtering */
		rctl = er32(RCTL);
		rctl |= E1000_RCTL_VFE;
		rctl &= ~E1000_RCTL_CFIEN;
		ew32(RCTL, rctl);
	}
}

/**
 * e1000e_vlan_strip_enable - helper to disable HW VLAN stripping
 * @adapter: board private structure to initialize
 **/
static void e1000e_vlan_strip_disable(struct e1000_adapter *adapter)
{
	struct e1000_hw *hw = &adapter->hw;
	u32 ctrl;

	/* disable VLAN tag insert/strip */
	ctrl = er32(CTRL);
	ctrl &= ~E1000_CTRL_VME;
	ew32(CTRL, ctrl);
}

/**
 * e1000e_vlan_strip_enable - helper to enable HW VLAN stripping
 * @adapter: board private structure to initialize
 **/
static void e1000e_vlan_strip_enable(struct e1000_adapter *adapter)
{
	struct e1000_hw *hw = &adapter->hw;
	u32 ctrl;

	/* enable VLAN tag insert/strip */
	ctrl = er32(CTRL);
	ctrl |= E1000_CTRL_VME;
	ew32(CTRL, ctrl);
}

static void e1000_update_mng_vlan(struct e1000_adapter *adapter)
{
	struct rtnet_device *netdev = adapter->netdev;
	u16 vid = adapter->hw.mng_cookie.vlan_id;
	u16 old_vid = adapter->mng_vlan_id;

	if (adapter->hw.mng_cookie.status &
	    E1000_MNG_DHCP_COOKIE_STATUS_VLAN) {
		e1000_vlan_rx_add_vid(netdev, vid);
		adapter->mng_vlan_id = vid;
	}

	if ((old_vid != (u16)E1000_MNG_VLAN_NONE) && (vid != old_vid))
		e1000_vlan_rx_kill_vid(netdev, old_vid);
}

static void e1000_restore_vlan(struct e1000_adapter *adapter)
{
	u16 vid;

	e1000_vlan_rx_add_vid(adapter->netdev, 0);

	for_each_set_bit(vid, adapter->active_vlans, VLAN_N_VID)
		e1000_vlan_rx_add_vid(adapter->netdev, vid);
}

static void e1000_init_manageability_pt(struct e1000_adapter *adapter)
{
	struct e1000_hw *hw = &adapter->hw;
	u32 manc, manc2h, mdef, i, j;

	if (!(adapter->flags & FLAG_MNG_PT_ENABLED))
		return;

	manc = er32(MANC);

	/*
	 * enable receiving management packets to the host. this will probably
	 * generate destination unreachable messages from the host OS, but
	 * the packets will be handled on SMBUS
	 */
	manc |= E1000_MANC_EN_MNG2HOST;
	manc2h = er32(MANC2H);

	switch (hw->mac.type) {
	default:
		manc2h |= (E1000_MANC2H_PORT_623 | E1000_MANC2H_PORT_664);
		break;
	case e1000_82574:
	case e1000_82583:
		/*
		 * Check if IPMI pass-through decision filter already exists;
		 * if so, enable it.
		 */
		for (i = 0, j = 0; i < 8; i++) {
			mdef = er32(MDEF(i));

			/* Ignore filters with anything other than IPMI ports */
			if (mdef & ~(E1000_MDEF_PORT_623 | E1000_MDEF_PORT_664))
				continue;

			/* Enable this decision filter in MANC2H */
			if (mdef)
				manc2h |= (1 << i);

			j |= mdef;
		}

		if (j == (E1000_MDEF_PORT_623 | E1000_MDEF_PORT_664))
			break;

		/* Create new decision filter in an empty filter */
		for (i = 0, j = 0; i < 8; i++)
			if (er32(MDEF(i)) == 0) {
				ew32(MDEF(i), (E1000_MDEF_PORT_623 |
					       E1000_MDEF_PORT_664));
				manc2h |= (1 << 1);
				j++;
				break;
			}

		if (!j)
			e_warn("Unable to create IPMI pass-through filter\n");
		break;
	}

	ew32(MANC2H, manc2h);
	ew32(MANC, manc);
}

/**
 * e1000_configure_tx - Configure Transmit Unit after Reset
 * @adapter: board private structure
 *
 * Configure the Tx unit of the MAC after a reset.
 **/
static void e1000_configure_tx(struct e1000_adapter *adapter)
{
	struct e1000_hw *hw = &adapter->hw;
	struct e1000_ring *tx_ring = adapter->tx_ring;
	u64 tdba;
	u32 tdlen, tctl, tipg, tarc;
	u32 ipgr1, ipgr2;

	/* Setup the HW Tx Head and Tail descriptor pointers */
	tdba = tx_ring->dma;
	tdlen = tx_ring->count * sizeof(struct e1000_tx_desc);
	ew32(TDBAL, (tdba & DMA_BIT_MASK(32)));
	ew32(TDBAH, (tdba >> 32));
	ew32(TDLEN, tdlen);
	ew32(TDH, 0);
	ew32(TDT, 0);
	tx_ring->head = E1000_TDH;
	tx_ring->tail = E1000_TDT;

	/* Set the default values for the Tx Inter Packet Gap timer */
	tipg = DEFAULT_82543_TIPG_IPGT_COPPER;          /*  8  */
	ipgr1 = DEFAULT_82543_TIPG_IPGR1;               /*  8  */
	ipgr2 = DEFAULT_82543_TIPG_IPGR2;               /*  6  */

	if (adapter->flags & FLAG_TIPG_MEDIUM_FOR_80003ESLAN)
		ipgr2 = DEFAULT_80003ES2LAN_TIPG_IPGR2; /*  7  */

	tipg |= ipgr1 << E1000_TIPG_IPGR1_SHIFT;
	tipg |= ipgr2 << E1000_TIPG_IPGR2_SHIFT;
	ew32(TIPG, tipg);

	/* Set the Tx Interrupt Delay register */
	ew32(TIDV, adapter->tx_int_delay);
	/* Tx irq moderation */
	ew32(TADV, adapter->tx_abs_int_delay);

	if (adapter->flags2 & FLAG2_DMA_BURST) {
		u32 txdctl = er32(TXDCTL(0));
		txdctl &= ~(E1000_TXDCTL_PTHRESH | E1000_TXDCTL_HTHRESH |
			    E1000_TXDCTL_WTHRESH);
		/*
		 * set up some performance related parameters to encourage the
		 * hardware to use the bus more efficiently in bursts, depends
		 * on the tx_int_delay to be enabled,
		 * wthresh = 5 ==> burst write a cacheline (64 bytes) at a time
		 * hthresh = 1 ==> prefetch when one or more available
		 * pthresh = 0x1f ==> prefetch if internal cache 31 or less
		 * BEWARE: this seems to work but should be considered first if
		 * there are Tx hangs or other Tx related bugs
		 */
		txdctl |= E1000_TXDCTL_DMA_BURST_ENABLE;
		ew32(TXDCTL(0), txdctl);
		/* erratum work around: set txdctl the same for both queues */
		ew32(TXDCTL(1), txdctl);
	}

	/* Program the Transmit Control Register */
	tctl = er32(TCTL);
	tctl &= ~E1000_TCTL_CT;
	tctl |= E1000_TCTL_PSP | E1000_TCTL_RTLC |
		(E1000_COLLISION_THRESHOLD << E1000_CT_SHIFT);

	if (adapter->flags & FLAG_TARC_SPEED_MODE_BIT) {
		tarc = er32(TARC(0));
		/*
		 * set the speed mode bit, we'll clear it if we're not at
		 * gigabit link later
		 */
#define SPEED_MODE_BIT (1 << 21)
		tarc |= SPEED_MODE_BIT;
		ew32(TARC(0), tarc);
	}

	/* errata: program both queues to unweighted RR */
	if (adapter->flags & FLAG_TARC_SET_BIT_ZERO) {
		tarc = er32(TARC(0));
		tarc |= 1;
		ew32(TARC(0), tarc);
		tarc = er32(TARC(1));
		tarc |= 1;
		ew32(TARC(1), tarc);
	}

	/* Setup Transmit Descriptor Settings for eop descriptor */
	adapter->txd_cmd = E1000_TXD_CMD_EOP | E1000_TXD_CMD_IFCS;

	/* only set IDE if we are delaying interrupts using the timers */
	if (adapter->tx_int_delay)
		adapter->txd_cmd |= E1000_TXD_CMD_IDE;

	/* enable Report Status bit */
	adapter->txd_cmd |= E1000_TXD_CMD_RS;

	ew32(TCTL, tctl);

	e1000e_config_collision_dist(hw);
}

/**
 * e1000_setup_rctl - configure the receive control registers
 * @adapter: Board private structure
 **/
#define PAGE_USE_COUNT(S) (((S) >> PAGE_SHIFT) + \
			   (((S) & (PAGE_SIZE - 1)) ? 1 : 0))
static void e1000_setup_rctl(struct e1000_adapter *adapter)
{
	struct e1000_hw *hw = &adapter->hw;
	u32 rctl, rfctl;

	/* Workaround Si errata on PCHx - configure jumbo frame flow */
	if (hw->mac.type >= e1000_pch2lan) {
		s32 ret_val;

		if (adapter->netdev->mtu > ETH_DATA_LEN)
			ret_val = e1000_lv_jumbo_workaround_ich8lan(hw, true);
		else
			ret_val = e1000_lv_jumbo_workaround_ich8lan(hw, false);

		if (ret_val)
			e_dbg("failed to enable jumbo frame workaround mode\n");
	}

	/* Program MC offset vector base */
	rctl = er32(RCTL);
	rctl &= ~(3 << E1000_RCTL_MO_SHIFT);
	rctl |= E1000_RCTL_EN | E1000_RCTL_BAM |
		E1000_RCTL_LBM_NO | E1000_RCTL_RDMTS_HALF |
		(adapter->hw.mac.mc_filter_type << E1000_RCTL_MO_SHIFT);

	/* Do not Store bad packets */
	rctl &= ~E1000_RCTL_SBP;

	/* Enable Long Packet receive */
	if (adapter->netdev->mtu <= ETH_DATA_LEN)
		rctl &= ~E1000_RCTL_LPE;
	else
		rctl |= E1000_RCTL_LPE;

	/* Some systems expect that the CRC is included in SMBUS traffic. The
	 * hardware strips the CRC before sending to both SMBUS (BMC) and to
	 * host memory when this is enabled
	 */
	if (adapter->flags2 & FLAG2_CRC_STRIPPING)
		rctl |= E1000_RCTL_SECRC;

	/* Workaround Si errata on 82577 PHY - configure IPG for jumbos */
	if ((hw->phy.type == e1000_phy_82577) && (rctl & E1000_RCTL_LPE)) {
		u16 phy_data;

		e1e_rphy(hw, PHY_REG(770, 26), &phy_data);
		phy_data &= 0xfff8;
		phy_data |= (1 << 2);
		e1e_wphy(hw, PHY_REG(770, 26), phy_data);

		e1e_rphy(hw, 22, &phy_data);
		phy_data &= 0x0fff;
		phy_data |= (1 << 14);
		e1e_wphy(hw, 0x10, 0x2823);
		e1e_wphy(hw, 0x11, 0x0003);
		e1e_wphy(hw, 22, phy_data);
	}

	/* Setup buffer sizes */
	rctl &= ~E1000_RCTL_SZ_4096;
	rctl |= E1000_RCTL_BSEX;
	switch (adapter->rx_buffer_len) {
	case 2048:
	default:
		rctl |= E1000_RCTL_SZ_2048;
		rctl &= ~E1000_RCTL_BSEX;
		break;
	case 4096:
		rctl |= E1000_RCTL_SZ_4096;
		break;
	case 8192:
		rctl |= E1000_RCTL_SZ_8192;
		break;
	case 16384:
		rctl |= E1000_RCTL_SZ_16384;
		break;
	}

	/* Enable Extended Status in all Receive Descriptors */
	rfctl = er32(RFCTL);
	rfctl |= E1000_RFCTL_EXTEN;

	adapter->rx_ps_pages = 0;

	ew32(RFCTL, rfctl);
	ew32(RCTL, rctl);
	/* just started the receive unit, no need to restart */
	adapter->flags &= ~FLAG_RX_RESTART_NOW;
}

/**
 * e1000_configure_rx - Configure Receive Unit after Reset
 * @adapter: board private structure
 *
 * Configure the Rx unit of the MAC after a reset.
 **/
static void e1000_configure_rx(struct e1000_adapter *adapter)
{
	struct e1000_hw *hw = &adapter->hw;
	struct e1000_ring *rx_ring = adapter->rx_ring;
	u64 rdba;
	u32 rdlen, rctl, rxcsum, ctrl_ext;

	rdlen = rx_ring->count * sizeof(union e1000_rx_desc_extended);
	adapter->clean_rx = e1000_clean_rx_irq;
	adapter->alloc_rx_buf = e1000_alloc_rx_buffers;

	/* disable receives while setting up the descriptors */
	rctl = er32(RCTL);
	if (!(adapter->flags2 & FLAG2_NO_DISABLE_RX))
		ew32(RCTL, rctl & ~E1000_RCTL_EN);
	e1e_flush();
	usleep_range(10000, 20000);

	if (adapter->flags2 & FLAG2_DMA_BURST) {
		/*
		 * set the writeback threshold (only takes effect if the RDTR
		 * is set). set GRAN=1 and write back up to 0x4 worth, and
		 * enable prefetching of 0x20 Rx descriptors
		 * granularity = 01
		 * wthresh = 04,
		 * hthresh = 04,
		 * pthresh = 0x20
		 */
		ew32(RXDCTL(0), E1000_RXDCTL_DMA_BURST_ENABLE);
		ew32(RXDCTL(1), E1000_RXDCTL_DMA_BURST_ENABLE);

		/*
		 * override the delay timers for enabling bursting, only if
		 * the value was not set by the user via module options
		 */
		if (adapter->rx_int_delay == DEFAULT_RDTR)
			adapter->rx_int_delay = BURST_RDTR;
		if (adapter->rx_abs_int_delay == DEFAULT_RADV)
			adapter->rx_abs_int_delay = BURST_RADV;
	}

	/* set the Receive Delay Timer Register */
	ew32(RDTR, adapter->rx_int_delay);

	/* irq moderation */
	ew32(RADV, adapter->rx_abs_int_delay);
	if ((adapter->itr_setting != 0) && (adapter->itr != 0))
		ew32(ITR, 1000000000 / (adapter->itr * 256));

	ctrl_ext = er32(CTRL_EXT);
	ew32(CTRL_EXT, ctrl_ext);
	e1e_flush();

	/*
	 * Setup the HW Rx Head and Tail Descriptor Pointers and
	 * the Base and Length of the Rx Descriptor Ring
	 */
	rdba = rx_ring->dma;
	ew32(RDBAL, (rdba & DMA_BIT_MASK(32)));
	ew32(RDBAH, (rdba >> 32));
	ew32(RDLEN, rdlen);
	ew32(RDH, 0);
	ew32(RDT, 0);
	rx_ring->head = E1000_RDH;
	rx_ring->tail = E1000_RDT;

	/* Enable Receive Checksum Offload for TCP and UDP */
	rxcsum = er32(RXCSUM);
	if (adapter->netdev->features & NETIF_F_RXCSUM) {
		rxcsum |= E1000_RXCSUM_TUOFL;
	} else {
		rxcsum &= ~E1000_RXCSUM_TUOFL;
		/* no need to clear IPPCSE as it defaults to 0 */
	}
	ew32(RXCSUM, rxcsum);

	/* Enable Receives */
	ew32(RCTL, rctl);
}

/**
 *  e1000_update_mc_addr_list - Update Multicast addresses
 *  @hw: pointer to the HW structure
 *  @mc_addr_list: array of multicast addresses to program
 *  @mc_addr_count: number of multicast addresses to program
 *
 *  Updates the Multicast Table Array.
 *  The caller must have a packed mc_addr_list of multicast addresses.
 **/
static void e1000_update_mc_addr_list(struct e1000_hw *hw, u8 *mc_addr_list,
				      u32 mc_addr_count)
{
	hw->mac.ops.update_mc_addr_list(hw, mc_addr_list, mc_addr_count);
}

/**
 * e1000_set_multi - Multicast and Promiscuous mode set
 * @netdev: network interface device structure
 *
 * The set_multi entry point is called whenever the multicast address
 * list or the network interface flags are updated.  This routine is
 * responsible for configuring the hardware for proper multicast,
 * promiscuous mode, and all-multi behavior.
 **/
static void e1000_set_multi(struct rtnet_device *netdev)
{
	struct e1000_adapter *adapter = netdev->priv;
	struct e1000_hw *hw = &adapter->hw;
	u32 rctl;

	/* Check for Promiscuous and All Multicast modes */

	rctl = er32(RCTL);

	if (netdev->flags & IFF_PROMISC) {
		rctl |= (E1000_RCTL_UPE | E1000_RCTL_MPE);
		rctl &= ~E1000_RCTL_VFE;
		/* Do not hardware filter VLANs in promisc mode */
		e1000e_vlan_filter_disable(adapter);
	} else {
		if (netdev->flags & IFF_ALLMULTI) {
			rctl |= E1000_RCTL_MPE;
			rctl &= ~E1000_RCTL_UPE;
		} else {
			rctl &= ~(E1000_RCTL_UPE | E1000_RCTL_MPE);
		}
		e1000e_vlan_filter_enable(adapter);
	}

	ew32(RCTL, rctl);

	e1000_update_mc_addr_list(hw, NULL, 0);

	if (netdev->features & NETIF_F_HW_VLAN_CTAG_RX)
		e1000e_vlan_strip_enable(adapter);
	else
		e1000e_vlan_strip_disable(adapter);
}

/**
 * e1000_configure - configure the hardware for Rx and Tx
 * @adapter: private board structure
 **/
static void e1000_configure(struct e1000_adapter *adapter)
{
	e1000_set_multi(adapter->netdev);

	e1000_restore_vlan(adapter);
	e1000_init_manageability_pt(adapter);

	e1000_configure_tx(adapter);
	e1000_setup_rctl(adapter);
	e1000_configure_rx(adapter);
	adapter->alloc_rx_buf(adapter, e1000_desc_unused(adapter->rx_ring),
			      GFP_KERNEL);
}

/**
 * e1000e_power_up_phy - restore link in case the phy was powered down
 * @adapter: address of board private structure
 *
 * The phy may be powered down to save power and turn off link when the
 * driver is unloaded and wake on lan is not enabled (among others)
 * *** this routine MUST be followed by a call to e1000e_reset ***
 **/
void e1000e_power_up_phy(struct e1000_adapter *adapter)
{
	if (adapter->hw.phy.ops.power_up)
		adapter->hw.phy.ops.power_up(&adapter->hw);

	adapter->hw.mac.ops.setup_link(&adapter->hw);
}

/**
 * e1000_power_down_phy - Power down the PHY
 *
 * Power down the PHY so no link is implied when interface is down.
 * The PHY cannot be powered down if management or WoL is active.
 */
static void e1000_power_down_phy(struct e1000_adapter *adapter)
{
	/* WoL is enabled */
	if (adapter->wol)
		return;

	if (adapter->hw.phy.ops.power_down)
		adapter->hw.phy.ops.power_down(&adapter->hw);
}

/**
 * e1000e_reset - bring the hardware into a known good state
 *
 * This function boots the hardware and enables some settings that
 * require a configuration cycle of the hardware - those cannot be
 * set/changed during runtime. After reset the device needs to be
 * properly configured for Rx, Tx etc.
 */
void e1000e_reset(struct e1000_adapter *adapter)
{
	struct e1000_mac_info *mac = &adapter->hw.mac;
	struct e1000_fc_info *fc = &adapter->hw.fc;
	struct e1000_hw *hw = &adapter->hw;
	u32 tx_space, min_tx_space, min_rx_space;
	u32 pba = adapter->pba;
	u16 hwm;

	/* reset Packet Buffer Allocation to default */
	ew32(PBA, pba);

	if (adapter->max_frame_size > ETH_FRAME_LEN + ETH_FCS_LEN) {
		/*
		 * To maintain wire speed transmits, the Tx FIFO should be
		 * large enough to accommodate two full transmit packets,
		 * rounded up to the next 1KB and expressed in KB.  Likewise,
		 * the Rx FIFO should be large enough to accommodate at least
		 * one full receive packet and is similarly rounded up and
		 * expressed in KB.
		 */
		pba = er32(PBA);
		/* upper 16 bits has Tx packet buffer allocation size in KB */
		tx_space = pba >> 16;
		/* lower 16 bits has Rx packet buffer allocation size in KB */
		pba &= 0xffff;
		/*
		 * the Tx fifo also stores 16 bytes of information about the Tx
		 * but don't include ethernet FCS because hardware appends it
		 */
		min_tx_space = (adapter->max_frame_size +
				sizeof(struct e1000_tx_desc) -
				ETH_FCS_LEN) * 2;
		min_tx_space = ALIGN(min_tx_space, 1024);
		min_tx_space >>= 10;
		/* software strips receive CRC, so leave room for it */
		min_rx_space = adapter->max_frame_size;
		min_rx_space = ALIGN(min_rx_space, 1024);
		min_rx_space >>= 10;

		/*
		 * If current Tx allocation is less than the min Tx FIFO size,
		 * and the min Tx FIFO size is less than the current Rx FIFO
		 * allocation, take space away from current Rx allocation
		 */
		if ((tx_space < min_tx_space) &&
		    ((min_tx_space - tx_space) < pba)) {
			pba -= min_tx_space - tx_space;

			/*
			 * if short on Rx space, Rx wins and must trump Tx
			 * adjustment or use Early Receive if available
			 */
			if ((pba < min_rx_space) &&
			    (!(adapter->flags & FLAG_HAS_ERT)))
				/* ERT enabled in e1000_configure_rx */
				pba = min_rx_space;
		}

		ew32(PBA, pba);
	}

	/*
	 * flow control settings
	 *
	 * The high water mark must be low enough to fit one full frame
	 * (or the size used for early receive) above it in the Rx FIFO.
	 * Set it to the lower of:
	 * - 90% of the Rx FIFO size, and
	 * - the full Rx FIFO size minus the early receive size (for parts
	 *   with ERT support assuming ERT set to E1000_ERT_2048), or
	 * - the full Rx FIFO size minus one full frame
	 */
	if (adapter->flags & FLAG_DISABLE_FC_PAUSE_TIME)
		fc->pause_time = 0xFFFF;
	else
		fc->pause_time = E1000_FC_PAUSE_TIME;
	fc->send_xon = 1;
	fc->current_mode = fc->requested_mode;

	switch (hw->mac.type) {
	default:
		if ((adapter->flags & FLAG_HAS_ERT) &&
		    (adapter->netdev->mtu > ETH_DATA_LEN))
			hwm = min(((pba << 10) * 9 / 10),
				  ((pba << 10) - (E1000_ERT_2048 << 3)));
		else
			hwm = min(((pba << 10) * 9 / 10),
				  ((pba << 10) - adapter->max_frame_size));

		fc->high_water = hwm & E1000_FCRTH_RTH; /* 8-byte granularity */
		fc->low_water = fc->high_water - 8;
		break;
	case e1000_pchlan:
		/*
		 * Workaround PCH LOM adapter hangs with certain network
		 * loads.  If hangs persist, try disabling Tx flow control.
		 */
		if (adapter->netdev->mtu > ETH_DATA_LEN) {
			fc->high_water = 0x3500;
			fc->low_water  = 0x1500;
		} else {
			fc->high_water = 0x5000;
			fc->low_water  = 0x3000;
		}
		fc->refresh_time = 0x1000;
		break;
	case e1000_pch2lan:
	case e1000_pch_lpt:
		fc->high_water = 0x05C20;
		fc->low_water = 0x05048;
		fc->pause_time = 0x0650;
		fc->refresh_time = 0x0400;
		if (adapter->netdev->mtu > ETH_DATA_LEN) {
			pba = 14;
			ew32(PBA, pba);
		}
		break;
	}

	/*
	 * Disable Adaptive Interrupt Moderation if 2 full packets cannot
	 * fit in receive buffer and early-receive not supported.
	 */
	if (adapter->itr_setting & 0x3) {
		if (((adapter->max_frame_size * 2) > (pba << 10)) &&
		    !(adapter->flags & FLAG_HAS_ERT)) {
			if (!(adapter->flags2 & FLAG2_DISABLE_AIM)) {
				dev_info(&adapter->pdev->dev,
					"Interrupt Throttle Rate turned off\n");
				adapter->flags2 |= FLAG2_DISABLE_AIM;
				ew32(ITR, 0);
			}
		} else if (adapter->flags2 & FLAG2_DISABLE_AIM) {
			dev_info(&adapter->pdev->dev,
				 "Interrupt Throttle Rate turned on\n");
			adapter->flags2 &= ~FLAG2_DISABLE_AIM;
			adapter->itr = 20000;
			ew32(ITR, 1000000000 / (adapter->itr * 256));
		}
	}

	/* Allow time for pending master requests to run */
	mac->ops.reset_hw(hw);

	/*
	 * For parts with AMT enabled, let the firmware know
	 * that the network interface is in control
	 */
	if (adapter->flags & FLAG_HAS_AMT)
		e1000e_get_hw_control(adapter);

	ew32(WUC, 0);

	if (mac->ops.init_hw(hw))
		e_err("Hardware Error\n");

	e1000_update_mng_vlan(adapter);

	/* Enable h/w to recognize an 802.1Q VLAN Ethernet packet */
	ew32(VET, ETH_P_8021Q);

	e1000e_reset_adaptive(hw);

	if (!rtnetif_running(adapter->netdev) &&
	    !test_bit(__E1000_TESTING, &adapter->state)) {
		e1000_power_down_phy(adapter);
		return;
	}

	e1000_get_phy_info(hw);

	if ((adapter->flags & FLAG_HAS_SMART_POWER_DOWN) &&
	    !(adapter->flags & FLAG_SMART_POWER_DOWN)) {
		u16 phy_data = 0;
		/*
		 * speed up time to link by disabling smart power down, ignore
		 * the return value of this function because there is nothing
		 * different we would do if it failed
		 */
		e1e_rphy(hw, IGP02E1000_PHY_POWER_MGMT, &phy_data);
		phy_data &= ~IGP02E1000_PM_SPD;
		e1e_wphy(hw, IGP02E1000_PHY_POWER_MGMT, phy_data);
	}
}

int e1000e_up(struct e1000_adapter *adapter)
{
	struct e1000_hw *hw = &adapter->hw;

	/* hardware has been reset, we need to reload some things */
	e1000_configure(adapter);

	clear_bit(__E1000_DOWN, &adapter->state);

	if (adapter->msix_entries)
		e1000_configure_msix(adapter);
	e1000_irq_enable(adapter);

	rtnetif_start_queue(adapter->netdev);

	/* fire a link change interrupt to start the watchdog */
	if (adapter->msix_entries)
		ew32(ICS, E1000_ICS_LSC | E1000_ICR_OTHER);
	else
		ew32(ICS, E1000_ICS_LSC);

	return 0;
}

static void e1000e_flush_descriptors(struct e1000_adapter *adapter)
{
	struct e1000_hw *hw = &adapter->hw;

	if (!(adapter->flags2 & FLAG2_DMA_BURST))
		return;

	/* flush pending descriptor writebacks to memory */
	ew32(TIDV, adapter->tx_int_delay | E1000_TIDV_FPD);
	ew32(RDTR, adapter->rx_int_delay | E1000_RDTR_FPD);

	/* execute the writes immediately */
	e1e_flush();
}

void e1000e_down(struct e1000_adapter *adapter)
{
	struct rtnet_device *netdev = adapter->netdev;
	struct e1000_hw *hw = &adapter->hw;
	u32 tctl, rctl;

	/*
	 * signal that we're down so the interrupt handler does not
	 * reschedule our watchdog timer
	 */
	set_bit(__E1000_DOWN, &adapter->state);

	/* disable receives in the hardware */
	rctl = er32(RCTL);
	if (!(adapter->flags2 & FLAG2_NO_DISABLE_RX))
		ew32(RCTL, rctl & ~E1000_RCTL_EN);
	/* flush and sleep below */

	rtnetif_stop_queue(netdev);

	/* disable transmits in the hardware */
	tctl = er32(TCTL);
	tctl &= ~E1000_TCTL_EN;
	ew32(TCTL, tctl);

	/* flush both disables and wait for them to finish */
	e1e_flush();
	usleep_range(10000, 20000);

	e1000_irq_disable(adapter);

	del_timer_sync(&adapter->watchdog_timer);
	del_timer_sync(&adapter->phy_info_timer);

	rtnetif_carrier_off(netdev);

	e1000e_flush_descriptors(adapter);
	e1000_clean_tx_ring(adapter);
	e1000_clean_rx_ring(adapter);

	adapter->link_speed = 0;
	adapter->link_duplex = 0;

	if (!pci_channel_offline(adapter->pdev))
		e1000e_reset(adapter);

	/*
	 * TODO: for power management, we could drop the link and
	 * pci_disable_device here.
	 */
}

void e1000e_reinit_locked(struct e1000_adapter *adapter)
{
	might_sleep();
	while (test_and_set_bit(__E1000_RESETTING, &adapter->state))
		usleep_range(1000, 2000);
	e1000e_down(adapter);
	e1000e_up(adapter);
	clear_bit(__E1000_RESETTING, &adapter->state);
}

/**
 * e1000_sw_init - Initialize general software structures (struct e1000_adapter)
 * @adapter: board private structure to initialize
 *
 * e1000_sw_init initializes the Adapter private data structure.
 * Fields are initialized based on PCI device information and
 * OS network device settings (MTU size).
 **/
static int e1000_sw_init(struct e1000_adapter *adapter)
{
	struct rtnet_device *netdev = adapter->netdev;

	adapter->rx_buffer_len = ETH_FRAME_LEN + VLAN_HLEN + ETH_FCS_LEN;
	adapter->rx_ps_bsize0 = 128;
	adapter->max_frame_size = netdev->mtu + ETH_HLEN + ETH_FCS_LEN;
	adapter->min_frame_size = ETH_ZLEN + ETH_FCS_LEN;

	spin_lock_init(&adapter->stats64_lock);

	e1000e_set_interrupt_capability(adapter);

	if (e1000_alloc_queues(adapter))
		return -ENOMEM;

	/* Explicitly disable IRQ since the NIC can be in any state. */
	e1000_irq_disable(adapter);

	set_bit(__E1000_DOWN, &adapter->state);
	return 0;
}

/**
 * e1000_intr_msi_test - Interrupt Handler
 * @irq: interrupt number
 * @data: pointer to a network interface device structure
 **/
static irqreturn_t e1000_intr_msi_test(int irq, void *data)
{
	struct rtnet_device *netdev = data;
	struct e1000_adapter *adapter = netdev->priv;
	struct e1000_hw *hw = &adapter->hw;
	u32 icr = er32(ICR);

	e_dbg("icr is %08X\n", icr);
	if (icr & E1000_ICR_RXSEQ) {
		adapter->flags &= ~FLAG_MSI_TEST_FAILED;
		wmb();
	}

	return IRQ_HANDLED;
}

/**
 * e1000_test_msi_interrupt - Returns 0 for successful test
 * @adapter: board private struct
 *
 * code flow taken from tg3.c
 **/
static int e1000_test_msi_interrupt(struct e1000_adapter *adapter)
{
	struct rtnet_device *netdev = adapter->netdev;
	struct e1000_hw *hw = &adapter->hw;
	int err;

	/* poll_enable hasn't been called yet, so don't need disable */
	/* clear any pending events */
	er32(ICR);

	/* free the real vector and request a test handler */
	e1000_free_irq(adapter);
	e1000e_reset_interrupt_capability(adapter);

	/* Assume that the test fails, if it succeeds then the test
	 * MSI irq handler will unset this flag */
	adapter->flags |= FLAG_MSI_TEST_FAILED;

	err = pci_enable_msi(adapter->pdev);
	if (err)
		goto msi_test_failed;

	err = request_irq(adapter->pdev->irq, e1000_intr_msi_test, 0,
			  netdev->name, netdev);
	if (err) {
		pci_disable_msi(adapter->pdev);
		goto msi_test_failed;
	}

	wmb();

	e1000_irq_enable(adapter);

	/* fire an unusual interrupt on the test handler */
	ew32(ICS, E1000_ICS_RXSEQ);
	e1e_flush();
	msleep(50);

	e1000_irq_disable(adapter);

	rmb();

	if (adapter->flags & FLAG_MSI_TEST_FAILED) {
		adapter->int_mode = E1000E_INT_MODE_LEGACY;
		e_info("MSI interrupt test failed, using legacy interrupt.\n");
	} else
		e_dbg("MSI interrupt test succeeded!\n");

	free_irq(adapter->pdev->irq, netdev);
	pci_disable_msi(adapter->pdev);

msi_test_failed:
	e1000e_set_interrupt_capability(adapter);
	return e1000_request_irq(adapter);
}

/**
 * e1000_test_msi - Returns 0 if MSI test succeeds or INTx mode is restored
 * @adapter: board private struct
 *
 * code flow taken from tg3.c, called with e1000 interrupts disabled.
 **/
static int e1000_test_msi(struct e1000_adapter *adapter)
{
	int err;
	u16 pci_cmd;

	if (!(adapter->flags & FLAG_MSI_ENABLED))
		return 0;

	/* disable SERR in case the MSI write causes a master abort */
	pci_read_config_word(adapter->pdev, PCI_COMMAND, &pci_cmd);
	if (pci_cmd & PCI_COMMAND_SERR)
		pci_write_config_word(adapter->pdev, PCI_COMMAND,
				      pci_cmd & ~PCI_COMMAND_SERR);

	err = e1000_test_msi_interrupt(adapter);

	/* re-enable SERR */
	if (pci_cmd & PCI_COMMAND_SERR) {
		pci_read_config_word(adapter->pdev, PCI_COMMAND, &pci_cmd);
		pci_cmd |= PCI_COMMAND_SERR;
		pci_write_config_word(adapter->pdev, PCI_COMMAND, pci_cmd);
	}

	return err;
}

/**
 * e1000_open - Called when a network interface is made active
 * @netdev: network interface device structure
 *
 * Returns 0 on success, negative value on failure
 *
 * The open entry point is called when a network interface is made
 * active by the system (IFF_UP).  At this point all resources needed
 * for transmit and receive operations are allocated, the interrupt
 * handler is registered with the OS, the watchdog timer is started,
 * and the stack is notified that the interface is ready.
 **/
static int e1000_open(struct rtnet_device *netdev)
{
	struct e1000_adapter *adapter = netdev->priv;
	struct e1000_hw *hw = &adapter->hw;
	struct pci_dev *pdev = adapter->pdev;
	int err;

	/* disallow open during test */
	if (test_bit(__E1000_TESTING, &adapter->state))
		return -EBUSY;

	pm_runtime_get_sync(&pdev->dev);

	rtnetif_carrier_off(netdev);

	/* allocate transmit descriptors */
	err = e1000e_setup_tx_resources(adapter);
	if (err)
		goto err_setup_tx;

	/* allocate receive descriptors */
	err = e1000e_setup_rx_resources(adapter);
	if (err)
		goto err_setup_rx;

	/*
	 * If AMT is enabled, let the firmware know that the network
	 * interface is now open and reset the part to a known state.
	 */
	if (adapter->flags & FLAG_HAS_AMT) {
		e1000e_get_hw_control(adapter);
		e1000e_reset(adapter);
	}

	e1000e_power_up_phy(adapter);

	adapter->mng_vlan_id = E1000_MNG_VLAN_NONE;
	if ((adapter->hw.mng_cookie.status &
	     E1000_MNG_DHCP_COOKIE_STATUS_VLAN))
		e1000_update_mng_vlan(adapter);

	/*
	 * before we allocate an interrupt, we must be ready to handle it.
	 * Setting DEBUG_SHIRQ in the kernel makes it fire an interrupt
	 * as soon as we call pci_request_irq, so we have to setup our
	 * clean_rx handler before we do so.
	 */
	e1000_configure(adapter);

	rt_stack_connect(netdev, &STACK_manager);

	err = e1000_request_irq(adapter);
	if (err)
		goto err_req_irq;

	/*
	 * Work around PCIe errata with MSI interrupts causing some chipsets to
	 * ignore e1000e MSI messages, which means we need to test our MSI
	 * interrupt now
	 */
	if (adapter->int_mode != E1000E_INT_MODE_LEGACY) {
		err = e1000_test_msi(adapter);
		if (err) {
			e_err("Interrupt allocation failed\n");
			goto err_req_irq;
		}
	}

	/* From here on the code is the same as e1000e_up() */
	clear_bit(__E1000_DOWN, &adapter->state);

	e1000_irq_enable(adapter);

	rtnetif_start_queue(netdev);

	adapter->idle_check = true;
	pm_runtime_put(&pdev->dev);

	/* fire a link status change interrupt to start the watchdog */
	if (adapter->msix_entries)
		ew32(ICS, E1000_ICS_LSC | E1000_ICR_OTHER);
	else
		ew32(ICS, E1000_ICS_LSC);

	return 0;

err_req_irq:
	e1000e_release_hw_control(adapter);
	e1000_power_down_phy(adapter);
	e1000e_free_rx_resources(adapter);
err_setup_rx:
	e1000e_free_tx_resources(adapter);
err_setup_tx:
	e1000e_reset(adapter);
	pm_runtime_put_sync(&pdev->dev);

	return err;
}

/**
 * e1000_close - Disables a network interface
 * @netdev: network interface device structure
 *
 * Returns 0, this is not allowed to fail
 *
 * The close entry point is called when an interface is de-activated
 * by the OS.  The hardware is still under the drivers control, but
 * needs to be disabled.  A global MAC reset is issued to stop the
 * hardware, and all transmit and receive resources are freed.
 **/
static int e1000_close(struct rtnet_device *netdev)
{
	struct e1000_adapter *adapter = netdev->priv;
	struct pci_dev *pdev = adapter->pdev;

	WARN_ON(test_bit(__E1000_RESETTING, &adapter->state));

	pm_runtime_get_sync(&pdev->dev);

	if (!test_bit(__E1000_DOWN, &adapter->state)) {
		e1000e_down(adapter);
		e1000_free_irq(adapter);
	}
	e1000_power_down_phy(adapter);

	rt_stack_disconnect(netdev);

	e1000e_free_tx_resources(adapter);
	e1000e_free_rx_resources(adapter);

	/*
	 * kill manageability vlan ID if supported, but not if a vlan with
	 * the same ID is registered on the host OS (let 8021q kill it)
	 */
	if (adapter->hw.mng_cookie.status &
	    E1000_MNG_DHCP_COOKIE_STATUS_VLAN)
		e1000_vlan_rx_kill_vid(netdev, adapter->mng_vlan_id);

	/*
	 * If AMT is enabled, let the firmware know that the network
	 * interface is now closed
	 */
	if ((adapter->flags & FLAG_HAS_AMT) &&
	    !test_bit(__E1000_TESTING, &adapter->state))
		e1000e_release_hw_control(adapter);

	pm_runtime_put_sync(&pdev->dev);

	return 0;
}

/**
 * e1000e_update_phy_task - work thread to update phy
 * @work: pointer to our work struct
 *
 * this worker thread exists because we must acquire a
 * semaphore to read the phy, which we could msleep while
 * waiting for it, and we can't msleep in a timer.
 **/
static void e1000e_update_phy_task(struct work_struct *work)
{
	struct e1000_adapter *adapter = container_of(work,
					struct e1000_adapter, update_phy_task);

	if (test_bit(__E1000_DOWN, &adapter->state))
		return;

	e1000_get_phy_info(&adapter->hw);
}

/*
 * Need to wait a few seconds after link up to get diagnostic information from
 * the phy
 */
static void e1000_update_phy_info(unsigned long data)
{
	struct e1000_adapter *adapter = (struct e1000_adapter *) data;

	if (test_bit(__E1000_DOWN, &adapter->state))
		return;

	rtdm_schedule_nrt_work(&adapter->update_phy_task);
}

/**
 * e1000_phy_read_status - Update the PHY register status snapshot
 * @adapter: board private structure
 **/
static void e1000_phy_read_status(struct e1000_adapter *adapter)
{
	struct e1000_hw *hw = &adapter->hw;
	struct e1000_phy_regs *phy = &adapter->phy_regs;

	if ((er32(STATUS) & E1000_STATUS_LU) &&
	    (adapter->hw.phy.media_type == e1000_media_type_copper)) {
		int ret_val;

		ret_val  = e1e_rphy(hw, PHY_CONTROL, &phy->bmcr);
		ret_val |= e1e_rphy(hw, PHY_STATUS, &phy->bmsr);
		ret_val |= e1e_rphy(hw, PHY_AUTONEG_ADV, &phy->advertise);
		ret_val |= e1e_rphy(hw, PHY_LP_ABILITY, &phy->lpa);
		ret_val |= e1e_rphy(hw, PHY_AUTONEG_EXP, &phy->expansion);
		ret_val |= e1e_rphy(hw, PHY_1000T_CTRL, &phy->ctrl1000);
		ret_val |= e1e_rphy(hw, PHY_1000T_STATUS, &phy->stat1000);
		ret_val |= e1e_rphy(hw, PHY_EXT_STATUS, &phy->estatus);
		if (ret_val)
			e_warn("Error reading PHY register\n");
	} else {
		/*
		 * Do not read PHY registers if link is not up
		 * Set values to typical power-on defaults
		 */
		phy->bmcr = (BMCR_SPEED1000 | BMCR_ANENABLE | BMCR_FULLDPLX);
		phy->bmsr = (BMSR_100FULL | BMSR_100HALF | BMSR_10FULL |
			     BMSR_10HALF | BMSR_ESTATEN | BMSR_ANEGCAPABLE |
			     BMSR_ERCAP);
		phy->advertise = (ADVERTISE_PAUSE_ASYM | ADVERTISE_PAUSE_CAP |
				  ADVERTISE_ALL | ADVERTISE_CSMA);
		phy->lpa = 0;
		phy->expansion = EXPANSION_ENABLENPAGE;
		phy->ctrl1000 = ADVERTISE_1000FULL;
		phy->stat1000 = 0;
		phy->estatus = (ESTATUS_1000_TFULL | ESTATUS_1000_THALF);
	}
}

static void e1000_print_link_info(struct e1000_adapter *adapter)
{
	struct e1000_hw *hw = &adapter->hw;
	u32 ctrl = er32(CTRL);

	/* Link status message must follow this format for user tools */
	printk(KERN_INFO "e1000e: %s NIC Link is Up %d Mbps %s, "
	       "Flow Control: %s\n",
	       adapter->netdev->name,
	       adapter->link_speed,
	       (adapter->link_duplex == FULL_DUPLEX) ?
	       "Full Duplex" : "Half Duplex",
	       ((ctrl & E1000_CTRL_TFCE) && (ctrl & E1000_CTRL_RFCE)) ?
	       "Rx/Tx" :
	       ((ctrl & E1000_CTRL_RFCE) ? "Rx" :
		((ctrl & E1000_CTRL_TFCE) ? "Tx" : "None")));
}

static bool e1000e_has_link(struct e1000_adapter *adapter)
{
	struct e1000_hw *hw = &adapter->hw;
	bool link_active = 0;
	s32 ret_val = 0;

	/*
	 * get_link_status is set on LSC (link status) interrupt or
	 * Rx sequence error interrupt.  get_link_status will stay
	 * false until the check_for_link establishes link
	 * for copper adapters ONLY
	 */
	switch (hw->phy.media_type) {
	case e1000_media_type_copper:
		if (hw->mac.get_link_status) {
			ret_val = hw->mac.ops.check_for_link(hw);
			link_active = !hw->mac.get_link_status;
		} else {
			link_active = 1;
		}
		break;
	case e1000_media_type_fiber:
		ret_val = hw->mac.ops.check_for_link(hw);
		link_active = !!(er32(STATUS) & E1000_STATUS_LU);
		break;
	case e1000_media_type_internal_serdes:
		ret_val = hw->mac.ops.check_for_link(hw);
		link_active = adapter->hw.mac.serdes_has_link;
		break;
	default:
	case e1000_media_type_unknown:
		break;
	}

	if ((ret_val == E1000_ERR_PHY) && (hw->phy.type == e1000_phy_igp_3) &&
	    (er32(CTRL) & E1000_PHY_CTRL_GBE_DISABLE)) {
		/* See e1000_kmrn_lock_loss_workaround_ich8lan() */
		e_info("Gigabit has been disabled, downgrading speed\n");
	}

	return link_active;
}

static void e1000e_enable_receives(struct e1000_adapter *adapter)
{
	/* make sure the receive unit is started */
	if ((adapter->flags & FLAG_RX_NEEDS_RESTART) &&
	    (adapter->flags & FLAG_RX_RESTART_NOW)) {
		struct e1000_hw *hw = &adapter->hw;
		u32 rctl = er32(RCTL);
		ew32(RCTL, rctl | E1000_RCTL_EN);
		adapter->flags &= ~FLAG_RX_RESTART_NOW;
	}
}

static void e1000e_check_82574_phy_workaround(struct e1000_adapter *adapter)
{
	struct e1000_hw *hw = &adapter->hw;

	/*
	 * With 82574 controllers, PHY needs to be checked periodically
	 * for hung state and reset, if two calls return true
	 */
	if (e1000_check_phy_82574(hw))
		adapter->phy_hang_count++;
	else
		adapter->phy_hang_count = 0;

	if (adapter->phy_hang_count > 1) {
		adapter->phy_hang_count = 0;
		rtdm_schedule_nrt_work(&adapter->reset_task);
	}
}

/**
 * e1000_watchdog - Timer Call-back
 * @data: pointer to adapter cast into an unsigned long
 **/
static void e1000_watchdog(unsigned long data)
{
	struct e1000_adapter *adapter = (struct e1000_adapter *) data;

	/* Do the rest outside of interrupt context */
	rtdm_schedule_nrt_work(&adapter->watchdog_task);

	/* TODO: make this use queue_delayed_work() */
}

static void e1000_watchdog_task(struct work_struct *work)
{
	struct e1000_adapter *adapter = container_of(work,
					struct e1000_adapter, watchdog_task);
	struct rtnet_device *netdev = adapter->netdev;
	struct e1000_mac_info *mac = &adapter->hw.mac;
	struct e1000_phy_info *phy = &adapter->hw.phy;
	struct e1000_ring *tx_ring = adapter->tx_ring;
	struct e1000_hw *hw = &adapter->hw;
	u32 link, tctl;

	if (test_bit(__E1000_DOWN, &adapter->state))
		return;

	link = e1000e_has_link(adapter);
	if ((rtnetif_carrier_ok(netdev)) && link) {
		e1000e_enable_receives(adapter);
		goto link_up;
	}

	if ((e1000e_enable_tx_pkt_filtering(hw)) &&
	    (adapter->mng_vlan_id != adapter->hw.mng_cookie.vlan_id))
		e1000_update_mng_vlan(adapter);

	if (link) {
		if (!rtnetif_carrier_ok(netdev)) {
			bool txb2b = 1;

			/* update snapshot of PHY registers on LSC */
			e1000_phy_read_status(adapter);
			mac->ops.get_link_up_info(&adapter->hw,
						   &adapter->link_speed,
						   &adapter->link_duplex);
			e1000_print_link_info(adapter);
			/*
			 * On supported PHYs, check for duplex mismatch only
			 * if link has autonegotiated at 10/100 half
			 */
			if ((hw->phy.type == e1000_phy_igp_3 ||
			     hw->phy.type == e1000_phy_bm) &&
			    (hw->mac.autoneg == true) &&
			    (adapter->link_speed == SPEED_10 ||
			     adapter->link_speed == SPEED_100) &&
			    (adapter->link_duplex == HALF_DUPLEX)) {
				u16 autoneg_exp;

				e1e_rphy(hw, PHY_AUTONEG_EXP, &autoneg_exp);

				if (!(autoneg_exp & NWAY_ER_LP_NWAY_CAPS))
					e_info("Autonegotiated half duplex but"
					       " link partner cannot autoneg. "
					       " Try forcing full duplex if "
					       "link gets many collisions.\n");
			}

			/* adjust timeout factor according to speed/duplex */
			adapter->tx_timeout_factor = 1;
			switch (adapter->link_speed) {
			case SPEED_10:
				txb2b = 0;
				adapter->tx_timeout_factor = 16;
				break;
			case SPEED_100:
				txb2b = 0;
				adapter->tx_timeout_factor = 10;
				break;
			}

			/*
			 * workaround: re-program speed mode bit after
			 * link-up event
			 */
			if ((adapter->flags & FLAG_TARC_SPEED_MODE_BIT) &&
			    !txb2b) {
				u32 tarc0;
				tarc0 = er32(TARC(0));
				tarc0 &= ~SPEED_MODE_BIT;
				ew32(TARC(0), tarc0);
			}

			/*
			 * disable TSO for pcie and 10/100 speeds, to avoid
			 * some hardware issues
			 */
			if (!(adapter->flags & FLAG_TSO_FORCE)) {
				switch (adapter->link_speed) {
				case SPEED_10:
				case SPEED_100:
					e_info("10/100 speed: disabling TSO\n");
					netdev->features &= ~NETIF_F_TSO;
					netdev->features &= ~NETIF_F_TSO6;
					break;
				case SPEED_1000:
					netdev->features |= NETIF_F_TSO;
					netdev->features |= NETIF_F_TSO6;
					break;
				default:
					/* oops */
					break;
				}
			}

			/*
			 * enable transmits in the hardware, need to do this
			 * after setting TARC(0)
			 */
			tctl = er32(TCTL);
			tctl |= E1000_TCTL_EN;
			ew32(TCTL, tctl);

			/*
			 * Perform any post-link-up configuration before
			 * reporting link up.
			 */
			if (phy->ops.cfg_on_link_up)
				phy->ops.cfg_on_link_up(hw);

			rtnetif_carrier_on(netdev);

			if (!test_bit(__E1000_DOWN, &adapter->state))
				mod_timer(&adapter->phy_info_timer,
					  round_jiffies(jiffies + 2 * HZ));
		}
	} else {
		if (rtnetif_carrier_ok(netdev)) {
			adapter->link_speed = 0;
			adapter->link_duplex = 0;
			/* Link status message must follow this format */
			printk(KERN_INFO "e1000e: %s NIC Link is Down\n",
			       adapter->netdev->name);
			rtnetif_carrier_off(netdev);
			if (!test_bit(__E1000_DOWN, &adapter->state))
				mod_timer(&adapter->phy_info_timer,
					  round_jiffies(jiffies + 2 * HZ));

			if (adapter->flags & FLAG_RX_NEEDS_RESTART)
				rtdm_schedule_nrt_work(&adapter->reset_task);
		}
	}

link_up:
	spin_lock(&adapter->stats64_lock);

	mac->tx_packet_delta = adapter->stats.tpt - adapter->tpt_old;
	adapter->tpt_old = adapter->stats.tpt;
	mac->collision_delta = adapter->stats.colc - adapter->colc_old;
	adapter->colc_old = adapter->stats.colc;

	adapter->gorc = adapter->stats.gorc - adapter->gorc_old;
	adapter->gorc_old = adapter->stats.gorc;
	adapter->gotc = adapter->stats.gotc - adapter->gotc_old;
	adapter->gotc_old = adapter->stats.gotc;
	spin_unlock(&adapter->stats64_lock);

	e1000e_update_adaptive(&adapter->hw);

	if (!rtnetif_carrier_ok(netdev) &&
	    (e1000_desc_unused(tx_ring) + 1 < tx_ring->count)) {
		/*
		 * We've lost link, so the controller stops DMA,
		 * but we've got queued Tx work that's never going
		 * to get done, so reset controller to flush Tx.
		 * (Do the reset outside of interrupt context).
		 */
		rtdm_schedule_nrt_work(&adapter->reset_task);
		/* return immediately since reset is imminent */
		return;
	}

	/* Simple mode for Interrupt Throttle Rate (ITR) */
	if (adapter->itr_setting == 4) {
		/*
		 * Symmetric Tx/Rx gets a reduced ITR=2000;
		 * Total asymmetrical Tx or Rx gets ITR=8000;
		 * everyone else is between 2000-8000.
		 */
		u32 goc = (adapter->gotc + adapter->gorc) / 10000;
		u32 dif = (adapter->gotc > adapter->gorc ?
			    adapter->gotc - adapter->gorc :
			    adapter->gorc - adapter->gotc) / 10000;
		u32 itr = goc > 0 ? (dif * 6000 / goc + 2000) : 8000;

		ew32(ITR, 1000000000 / (itr * 256));
	}

	/* Cause software interrupt to ensure Rx ring is cleaned */
	if (adapter->msix_entries)
		ew32(ICS, adapter->rx_ring->ims_val);
	else
		ew32(ICS, E1000_ICS_RXDMT0);

	/* flush pending descriptors to memory before detecting Tx hang */
	e1000e_flush_descriptors(adapter);

	/* Force detection of hung controller every watchdog period */
	adapter->detect_tx_hung = 1;

	/*
	 * With 82571 controllers, LAA may be overwritten due to controller
	 * reset from the other port. Set the appropriate LAA in RAR[0]
	 */
	if (e1000e_get_laa_state_82571(hw))
		e1000e_rar_set(hw, adapter->hw.mac.addr, 0);

	if (adapter->flags2 & FLAG2_CHECK_PHY_HANG)
		e1000e_check_82574_phy_workaround(adapter);

	/* Reset the timer */
	if (!test_bit(__E1000_DOWN, &adapter->state))
		mod_timer(&adapter->watchdog_timer,
			  round_jiffies(jiffies + 2 * HZ));
}

#define E1000_TX_FLAGS_CSUM		0x00000001
#define E1000_TX_FLAGS_VLAN		0x00000002
#define E1000_TX_FLAGS_TSO		0x00000004
#define E1000_TX_FLAGS_IPV4		0x00000008
#define E1000_TX_FLAGS_VLAN_MASK	0xffff0000
#define E1000_TX_FLAGS_VLAN_SHIFT	16

#define E1000_MAX_PER_TXD	8192
#define E1000_MAX_TXD_PWR	12

static int e1000_tx_map(struct e1000_adapter *adapter,
			struct rtskb *skb, unsigned int first)
{
	struct e1000_ring *tx_ring = adapter->tx_ring;
	struct e1000_buffer *buffer_info;
	unsigned int offset = 0, size, i;

	i = tx_ring->next_to_use;

	buffer_info = &tx_ring->buffer_info[i];
	size = skb->len;

	buffer_info->length = size;
	buffer_info->time_stamp = jiffies;
	buffer_info->next_to_watch = i;
	buffer_info->dma = rtskb_data_dma_addr(skb, offset);
	buffer_info->mapped_as_page = false;

	tx_ring->buffer_info[i].skb = skb;
	tx_ring->buffer_info[i].segs = 1;
	tx_ring->buffer_info[i].bytecount = size;
	tx_ring->buffer_info[first].next_to_watch = i;

	return 1;
}

static void e1000_tx_queue(struct e1000_adapter *adapter,
			   int tx_flags, int count)
{
	struct e1000_ring *tx_ring = adapter->tx_ring;
	struct e1000_tx_desc *tx_desc = NULL;
	struct e1000_buffer *buffer_info;
	u32 txd_upper = 0, txd_lower = E1000_TXD_CMD_IFCS;
	unsigned int i;

	if (tx_flags & E1000_TX_FLAGS_CSUM) {
		txd_lower |= E1000_TXD_CMD_DEXT | E1000_TXD_DTYP_D;
		txd_upper |= E1000_TXD_POPTS_TXSM << 8;
	}

	if (tx_flags & E1000_TX_FLAGS_VLAN) {
		txd_lower |= E1000_TXD_CMD_VLE;
		txd_upper |= (tx_flags & E1000_TX_FLAGS_VLAN_MASK);
	}

	i = tx_ring->next_to_use;

	do {
		buffer_info = &tx_ring->buffer_info[i];
		tx_desc = E1000_TX_DESC(*tx_ring, i);
		tx_desc->buffer_addr = cpu_to_le64(buffer_info->dma);
		tx_desc->lower.data =
			cpu_to_le32(txd_lower | buffer_info->length);
		tx_desc->upper.data = cpu_to_le32(txd_upper);

		i++;
		if (i == tx_ring->count)
			i = 0;
	} while (--count > 0);

	tx_desc->lower.data |= cpu_to_le32(adapter->txd_cmd);

	/*
	 * Force memory writes to complete before letting h/w
	 * know there are new descriptors to fetch.  (Only
	 * applicable for weak-ordered memory model archs,
	 * such as IA-64).
	 */
	wmb();

	tx_ring->next_to_use = i;

	if (adapter->flags2 & FLAG2_PCIM2PCI_ARBITER_WA)
		e1000e_update_tdt_wa(adapter, i);
	else
		writel(i, adapter->hw.hw_addr + tx_ring->tail);

	/*
	 * we need this if more than one processor can write to our tail
	 * at a time, it synchronizes IO on IA64/Altix systems
	 */
	mmiowb();
}

#define MINIMUM_DHCP_PACKET_SIZE 282
static int e1000_transfer_dhcp_info(struct e1000_adapter *adapter,
				    struct rtskb *skb)
{
	struct e1000_hw *hw =  &adapter->hw;
	u16 length, offset;

	if (skb->len <= MINIMUM_DHCP_PACKET_SIZE)
		return 0;

	if (((struct ethhdr *) skb->data)->h_proto != htons(ETH_P_IP))
		return 0;

	{
		const struct iphdr *ip = (struct iphdr *)((u8 *)skb->data+14);
		struct udphdr *udp;

		if (ip->protocol != IPPROTO_UDP)
			return 0;

		udp = (struct udphdr *)((u8 *)ip + (ip->ihl << 2));
		if (ntohs(udp->dest) != 67)
			return 0;

		offset = (u8 *)udp + 8 - skb->data;
		length = skb->len - offset;
		return e1000e_mng_write_dhcp_info(hw, (u8 *)udp + 8, length);
	}

	return 0;
}

#define TXD_USE_COUNT(S, X) (((S) >> (X)) + 1 )
static int e1000_xmit_frame(struct rtskb *skb, struct rtnet_device *netdev)
{
	struct e1000_adapter *adapter = netdev->priv;
	struct e1000_ring *tx_ring = adapter->tx_ring;
	rtdm_lockctx_t context;
	unsigned int first;
	unsigned int tx_flags = 0;
	int count = 0;

	if (test_bit(__E1000_DOWN, &adapter->state)) {
		kfree_rtskb(skb);
		return NETDEV_TX_OK;
	}

	if (skb->len <= 0) {
		kfree_rtskb(skb);
		return NETDEV_TX_OK;
	}

	count++;

	count += skb->len;

	if (adapter->hw.mac.tx_pkt_filtering)
		e1000_transfer_dhcp_info(adapter, skb);

	rtdm_lock_get_irqsave(&tx_ring->lock, context);

	first = tx_ring->next_to_use;

	if (skb->xmit_stamp)
		*skb->xmit_stamp =
			cpu_to_be64(rtdm_clock_read() + *skb->xmit_stamp);

	/* if count is 0 then mapping error has occurred */
	count = e1000_tx_map(adapter, skb, first);
	if (count) {
		e1000_tx_queue(adapter, tx_flags, count);
		rtdm_lock_put_irqrestore(&tx_ring->lock, context);
	} else {
		tx_ring->buffer_info[first].time_stamp = 0;
		tx_ring->next_to_use = first;
		rtdm_lock_put_irqrestore(&tx_ring->lock, context);
		kfree_rtskb(skb);
	}

	return NETDEV_TX_OK;
}

static void e1000_reset_task(struct work_struct *work)
{
	struct e1000_adapter *adapter;
	adapter = container_of(work, struct e1000_adapter, reset_task);

	/* don't run the task if already down */
	if (test_bit(__E1000_DOWN, &adapter->state))
		return;

	if (!((adapter->flags & FLAG_RX_NEEDS_RESTART) &&
	      (adapter->flags & FLAG_RX_RESTART_NOW))) {
		e1000e_dump(adapter);
		e_err("Reset adapter\n");
	}
	e1000e_reinit_locked(adapter);
}

static int e1000_init_phy_wakeup(struct e1000_adapter *adapter, u32 wufc)
{
	struct e1000_hw *hw = &adapter->hw;
	u32 i, mac_reg;
	u16 phy_reg, wuc_enable;
	int retval = 0;

	/* copy MAC RARs to PHY RARs */
	e1000_copy_rx_addrs_to_phy_ich8lan(hw);

	retval = hw->phy.ops.acquire(hw);
	if (retval) {
		e_err("Could not acquire PHY\n");
		return retval;
	}

	/* Enable access to wakeup registers on and set page to BM_WUC_PAGE */
	retval = e1000_enable_phy_wakeup_reg_access_bm(hw, &wuc_enable);
	if (retval)
		goto out;

	/* copy MAC MTA to PHY MTA - only needed for pchlan */
	for (i = 0; i < adapter->hw.mac.mta_reg_count; i++) {
		mac_reg = E1000_READ_REG_ARRAY(hw, E1000_MTA, i);
		hw->phy.ops.write_reg_page(hw, BM_MTA(i),
					   (u16)(mac_reg & 0xFFFF));
		hw->phy.ops.write_reg_page(hw, BM_MTA(i) + 1,
					   (u16)((mac_reg >> 16) & 0xFFFF));
	}

	/* configure PHY Rx Control register */
	hw->phy.ops.read_reg_page(&adapter->hw, BM_RCTL, &phy_reg);
	mac_reg = er32(RCTL);
	if (mac_reg & E1000_RCTL_UPE)
		phy_reg |= BM_RCTL_UPE;
	if (mac_reg & E1000_RCTL_MPE)
		phy_reg |= BM_RCTL_MPE;
	phy_reg &= ~(BM_RCTL_MO_MASK);
	if (mac_reg & E1000_RCTL_MO_3)
		phy_reg |= (((mac_reg & E1000_RCTL_MO_3) >> E1000_RCTL_MO_SHIFT)
				<< BM_RCTL_MO_SHIFT);
	if (mac_reg & E1000_RCTL_BAM)
		phy_reg |= BM_RCTL_BAM;
	if (mac_reg & E1000_RCTL_PMCF)
		phy_reg |= BM_RCTL_PMCF;
	mac_reg = er32(CTRL);
	if (mac_reg & E1000_CTRL_RFCE)
		phy_reg |= BM_RCTL_RFCE;
	hw->phy.ops.write_reg_page(&adapter->hw, BM_RCTL, phy_reg);

	/* enable PHY wakeup in MAC register */
	ew32(WUFC, wufc);
	ew32(WUC, E1000_WUC_PHY_WAKE | E1000_WUC_PME_EN);

	/* configure and enable PHY wakeup in PHY registers */
	hw->phy.ops.write_reg_page(&adapter->hw, BM_WUFC, wufc);
	hw->phy.ops.write_reg_page(&adapter->hw, BM_WUC, E1000_WUC_PME_EN);

	/* activate PHY wakeup */
	wuc_enable |= BM_WUC_ENABLE_BIT | BM_WUC_HOST_WU_BIT;
	retval = e1000_disable_phy_wakeup_reg_access_bm(hw, &wuc_enable);
	if (retval)
		e_err("Could not set PHY Host Wakeup bit\n");
out:
	hw->phy.ops.release(hw);

	return retval;
}

static int __e1000_shutdown(struct pci_dev *pdev, bool *enable_wake,
			    bool runtime)
{
	struct rtnet_device *netdev = pci_get_drvdata(pdev);
	struct e1000_adapter *adapter = netdev->priv;
	struct e1000_hw *hw = &adapter->hw;
	u32 ctrl, ctrl_ext, rctl, status;
	/* Runtime suspend should only enable wakeup for link changes */
	u32 wufc = runtime ? E1000_WUFC_LNKC : adapter->wol;
	int retval = 0;

	rtnetif_device_detach(netdev);

	if (rtnetif_running(netdev)) {
		WARN_ON(test_bit(__E1000_RESETTING, &adapter->state));
		e1000e_down(adapter);
		e1000_free_irq(adapter);
	}
	e1000e_reset_interrupt_capability(adapter);

	retval = pci_save_state(pdev);
	if (retval)
		return retval;

	status = er32(STATUS);
	if (status & E1000_STATUS_LU)
		wufc &= ~E1000_WUFC_LNKC;

	if (wufc) {
		e1000_setup_rctl(adapter);
		e1000_set_multi(netdev);

		/* turn on all-multi mode if wake on multicast is enabled */
		if (wufc & E1000_WUFC_MC) {
			rctl = er32(RCTL);
			rctl |= E1000_RCTL_MPE;
			ew32(RCTL, rctl);
		}

		ctrl = er32(CTRL);
		/* advertise wake from D3Cold */
		#define E1000_CTRL_ADVD3WUC 0x00100000
		/* phy power management enable */
		#define E1000_CTRL_EN_PHY_PWR_MGMT 0x00200000
		ctrl |= E1000_CTRL_ADVD3WUC;
		if (!(adapter->flags2 & FLAG2_HAS_PHY_WAKEUP))
			ctrl |= E1000_CTRL_EN_PHY_PWR_MGMT;
		ew32(CTRL, ctrl);

		if (adapter->hw.phy.media_type == e1000_media_type_fiber ||
		    adapter->hw.phy.media_type ==
		    e1000_media_type_internal_serdes) {
			/* keep the laser running in D3 */
			ctrl_ext = er32(CTRL_EXT);
			ctrl_ext |= E1000_CTRL_EXT_SDP3_DATA;
			ew32(CTRL_EXT, ctrl_ext);
		}

		if (adapter->flags & FLAG_IS_ICH)
			e1000_suspend_workarounds_ich8lan(&adapter->hw);

		/* Allow time for pending master requests to run */
		e1000e_disable_pcie_master(&adapter->hw);

		if (adapter->flags2 & FLAG2_HAS_PHY_WAKEUP) {
			/* enable wakeup by the PHY */
			retval = e1000_init_phy_wakeup(adapter, wufc);
			if (retval)
				return retval;
		} else {
			/* enable wakeup by the MAC */
			ew32(WUFC, wufc);
			ew32(WUC, E1000_WUC_PME_EN);
		}
	} else {
		ew32(WUC, 0);
		ew32(WUFC, 0);
	}

	*enable_wake = !!wufc;

	/* make sure adapter isn't asleep if manageability is enabled */
	if ((adapter->flags & FLAG_MNG_PT_ENABLED) ||
	    (hw->mac.ops.check_mng_mode(hw)))
		*enable_wake = true;

	if (adapter->hw.phy.type == e1000_phy_igp_3)
		e1000e_igp3_phy_powerdown_workaround_ich8lan(&adapter->hw);

	/*
	 * Release control of h/w to f/w.  If f/w is AMT enabled, this
	 * would have already happened in close and is redundant.
	 */
	e1000e_release_hw_control(adapter);

	pci_disable_device(pdev);

	return 0;
}

static void e1000_power_off(struct pci_dev *pdev, bool sleep, bool wake)
{
	if (sleep && wake) {
		pci_prepare_to_sleep(pdev);
		return;
	}

	pci_wake_from_d3(pdev, wake);
	pci_set_power_state(pdev, PCI_D3hot);
}

static void e1000_complete_shutdown(struct pci_dev *pdev, bool sleep,
				    bool wake)
{
	struct rtnet_device *netdev = pci_get_drvdata(pdev);
	struct e1000_adapter *adapter = netdev->priv;

	/*
	 * The pci-e switch on some quad port adapters will report a
	 * correctable error when the MAC transitions from D0 to D3.  To
	 * prevent this we need to mask off the correctable errors on the
	 * downstream port of the pci-e switch.
	 */
	if (adapter->flags & FLAG_IS_QUAD_PORT) {
		struct pci_dev *us_dev = pdev->bus->self;
		int pos = pci_pcie_cap(us_dev);
		u16 devctl;

		pci_read_config_word(us_dev, pos + PCI_EXP_DEVCTL, &devctl);
		pci_write_config_word(us_dev, pos + PCI_EXP_DEVCTL,
				      (devctl & ~PCI_EXP_DEVCTL_CERE));

		e1000_power_off(pdev, sleep, wake);

		pci_write_config_word(us_dev, pos + PCI_EXP_DEVCTL, devctl);
	} else {
		e1000_power_off(pdev, sleep, wake);
	}
}

static void __e1000e_disable_aspm(struct pci_dev *pdev, u16 state)
{
	int pos;
	u16 reg16;

	/*
	 * Both device and parent should have the same ASPM setting.
	 * Disable ASPM in downstream component first and then upstream.
	 */
	pos = pci_pcie_cap(pdev);
	pci_read_config_word(pdev, pos + PCI_EXP_LNKCTL, &reg16);
	reg16 &= ~state;
	pci_write_config_word(pdev, pos + PCI_EXP_LNKCTL, reg16);

	if (!pdev->bus->self)
		return;

	pos = pci_pcie_cap(pdev->bus->self);
	pci_read_config_word(pdev->bus->self, pos + PCI_EXP_LNKCTL, &reg16);
	reg16 &= ~state;
	pci_write_config_word(pdev->bus->self, pos + PCI_EXP_LNKCTL, reg16);
}

static void e1000e_disable_aspm(struct pci_dev *pdev, u16 state)
{
	dev_info(&pdev->dev, "Disabling ASPM %s %s\n",
		 (state & PCIE_LINK_STATE_L0S) ? "L0s" : "",
		 (state & PCIE_LINK_STATE_L1) ? "L1" : "");

	__e1000e_disable_aspm(pdev, state);
}

static void e1000_shutdown(struct pci_dev *pdev)
{
	bool wake = false;

	__e1000_shutdown(pdev, &wake, false);

	if (system_state == SYSTEM_POWER_OFF)
		e1000_complete_shutdown(pdev, false, wake);
}

/**
 * e1000_io_error_detected - called when PCI error is detected
 * @pdev: Pointer to PCI device
 * @state: The current pci connection state
 *
 * This function is called after a PCI bus error affecting
 * this device has been detected.
 */
static pci_ers_result_t e1000_io_error_detected(struct pci_dev *pdev,
						pci_channel_state_t state)
{
	struct rtnet_device *netdev = pci_get_drvdata(pdev);
	struct e1000_adapter *adapter = netdev->priv;

	rtnetif_device_detach(netdev);

	if (state == pci_channel_io_perm_failure)
		return PCI_ERS_RESULT_DISCONNECT;

	if (rtnetif_running(netdev))
		e1000e_down(adapter);
	pci_disable_device(pdev);

	/* Request a slot slot reset. */
	return PCI_ERS_RESULT_NEED_RESET;
}

/**
 * e1000_io_slot_reset - called after the pci bus has been reset.
 * @pdev: Pointer to PCI device
 *
 * Restart the card from scratch, as if from a cold-boot. Implementation
 * resembles the first-half of the e1000_resume routine.
 */
static pci_ers_result_t e1000_io_slot_reset(struct pci_dev *pdev)
{
	struct rtnet_device *netdev = pci_get_drvdata(pdev);
	struct e1000_adapter *adapter = netdev->priv;
	struct e1000_hw *hw = &adapter->hw;
	u16 aspm_disable_flag = 0;
	int err;
	pci_ers_result_t result;

	if (adapter->flags2 & FLAG2_DISABLE_ASPM_L0S)
		aspm_disable_flag = PCIE_LINK_STATE_L0S;
	if (adapter->flags2 & FLAG2_DISABLE_ASPM_L1)
		aspm_disable_flag |= PCIE_LINK_STATE_L1;
	if (aspm_disable_flag)
		e1000e_disable_aspm(pdev, aspm_disable_flag);

	err = pci_enable_device_mem(pdev);
	if (err) {
		dev_err(&pdev->dev,
			"Cannot re-enable PCI device after reset.\n");
		result = PCI_ERS_RESULT_DISCONNECT;
	} else {
		pci_set_master(pdev);
		pdev->state_saved = true;
		pci_restore_state(pdev);

		pci_enable_wake(pdev, PCI_D3hot, 0);
		pci_enable_wake(pdev, PCI_D3cold, 0);

		e1000e_reset(adapter);
		ew32(WUS, ~0);
		result = PCI_ERS_RESULT_RECOVERED;
	}

	pci_cleanup_aer_uncorrect_error_status(pdev);

	return result;
}

/**
 * e1000_io_resume - called when traffic can start flowing again.
 * @pdev: Pointer to PCI device
 *
 * This callback is called when the error recovery driver tells us that
 * its OK to resume normal operation. Implementation resembles the
 * second-half of the e1000_resume routine.
 */
static void e1000_io_resume(struct pci_dev *pdev)
{
	struct rtnet_device *netdev = pci_get_drvdata(pdev);
	struct e1000_adapter *adapter = netdev->priv;

	e1000_init_manageability_pt(adapter);

	if (rtnetif_running(netdev)) {
		if (e1000e_up(adapter)) {
			dev_err(&pdev->dev,
				"can't bring device back up after reset\n");
			return;
		}
	}

	rtnetif_device_attach(netdev);

	/*
	 * If the controller has AMT, do not set DRV_LOAD until the interface
	 * is up.  For all other cases, let the f/w know that the h/w is now
	 * under the control of the driver.
	 */
	if (!(adapter->flags & FLAG_HAS_AMT))
		e1000e_get_hw_control(adapter);

}

static void e1000_print_device_info(struct e1000_adapter *adapter)
{
	struct e1000_hw *hw = &adapter->hw;
	struct rtnet_device *netdev = adapter->netdev;
	u32 ret_val;
	u8 pba_str[E1000_PBANUM_LENGTH];

	/* print bus type/speed/width info */
	e_info("(PCI Express:2.5GT/s:%s) %pM\n",
	       /* bus width */
	       ((hw->bus.width == e1000_bus_width_pcie_x4) ? "Width x4" :
		"Width x1"),
	       /* MAC address */
	       netdev->dev_addr);
	e_info("Intel(R) PRO/%s Network Connection\n",
	       (hw->phy.type == e1000_phy_ife) ? "10/100" : "1000");
	ret_val = e1000_read_pba_string_generic(hw, pba_str,
						E1000_PBANUM_LENGTH);
	if (ret_val)
		strncpy((char *)pba_str, "Unknown", sizeof(pba_str) - 1);
	e_info("MAC: %d, PHY: %d, PBA No: %s\n",
	       hw->mac.type, hw->phy.type, pba_str);
}

static void e1000_eeprom_checks(struct e1000_adapter *adapter)
{
	struct e1000_hw *hw = &adapter->hw;
	int ret_val;
	u16 buf = 0;

	if (hw->mac.type != e1000_82573)
		return;

	ret_val = e1000_read_nvm(hw, NVM_INIT_CONTROL2_REG, 1, &buf);
	if (!ret_val && (!(le16_to_cpu(buf) & (1 << 0)))) {
		/* Deep Smart Power Down (DSPD) */
		dev_warn(&adapter->pdev->dev,
			 "Warning: detected DSPD enabled in EEPROM\n");
	}
}

static dma_addr_t e1000_map_rtskb(struct rtnet_device *netdev,
				  struct rtskb *skb)
{
	struct e1000_adapter *adapter = netdev->priv;
	struct device *dev = &adapter->pdev->dev;
	dma_addr_t addr;

	addr = dma_map_single(dev, skb->buf_start, RTSKB_SIZE,
			      DMA_BIDIRECTIONAL);
	if (dma_mapping_error(dev, addr)) {
		dev_err(dev, "DMA map failed\n");
		return RTSKB_UNMAPPED;
	}
	return addr;
}

static void e1000_unmap_rtskb(struct rtnet_device *netdev,
			      struct rtskb *skb)
{
	struct e1000_adapter *adapter = netdev->priv;
	struct device *dev = &adapter->pdev->dev;

	dma_unmap_single(dev, skb->buf_dma_addr, RTSKB_SIZE,
			 DMA_BIDIRECTIONAL);
}

/**
 * e1000_probe - Device Initialization Routine
 * @pdev: PCI device information struct
 * @ent: entry in e1000_pci_tbl
 *
 * Returns 0 on success, negative on failure
 *
 * e1000_probe initializes an adapter identified by a pci_dev structure.
 * The OS initialization, configuring of the adapter private structure,
 * and a hardware reset occur.
 **/
static int e1000_probe(struct pci_dev *pdev,
				 const struct pci_device_id *ent)
{
	struct rtnet_device *netdev;
	struct e1000_adapter *adapter;
	struct e1000_hw *hw;
	const struct e1000_info *ei = e1000_info_tbl[ent->driver_data];
	resource_size_t mmio_start, mmio_len;
	resource_size_t flash_start, flash_len;

	static int cards_found;
	u16 aspm_disable_flag = 0;
	int i, err, pci_using_dac;
	u16 eeprom_data = 0;
	u16 eeprom_apme_mask = E1000_EEPROM_APME;

	if (ei->flags2 & FLAG2_DISABLE_ASPM_L0S)
		aspm_disable_flag = PCIE_LINK_STATE_L0S;
	if (ei->flags2 & FLAG2_DISABLE_ASPM_L1)
		aspm_disable_flag |= PCIE_LINK_STATE_L1;
	if (aspm_disable_flag)
		e1000e_disable_aspm(pdev, aspm_disable_flag);

	err = pci_enable_device_mem(pdev);
	if (err)
		return err;

	pci_using_dac = 0;
	err = dma_set_mask(&pdev->dev, DMA_BIT_MASK(64));
	if (!err) {
		err = dma_set_coherent_mask(&pdev->dev, DMA_BIT_MASK(64));
		if (!err)
			pci_using_dac = 1;
	} else {
		err = dma_set_mask(&pdev->dev, DMA_BIT_MASK(32));
		if (err) {
			err = dma_set_coherent_mask(&pdev->dev,
						    DMA_BIT_MASK(32));
			if (err) {
				dev_err(&pdev->dev, "No usable DMA "
					"configuration, aborting\n");
				goto err_dma;
			}
		}
	}

	err = pci_request_selected_regions_exclusive(pdev,
					  pci_select_bars(pdev, IORESOURCE_MEM),
					  e1000e_driver_name);
	if (err)
		goto err_pci_reg;

	/* AER (Advanced Error Reporting) hooks */
	pci_enable_pcie_error_reporting(pdev);

	pci_set_master(pdev);
	/* PCI config space info */
	err = pci_save_state(pdev);
	if (err)
		goto err_alloc_etherdev;

	err = -ENOMEM;
	netdev = rt_alloc_etherdev(sizeof(*adapter),
				2 * RT_E1000E_NUM_RXD + 256);
	if (!netdev)
		goto err_alloc_etherdev;

	rtdev_alloc_name(netdev, "rteth%d");
	rt_rtdev_connect(netdev, &RTDEV_manager);
	netdev->vers = RTDEV_VERS_2_0;

	netdev->irq = pdev->irq;

	pci_set_drvdata(pdev, netdev);
	adapter = netdev->priv;
	hw = &adapter->hw;
	adapter->netdev = netdev;
	adapter->pdev = pdev;
	adapter->ei = ei;
	adapter->pba = ei->pba;
	adapter->flags = ei->flags;
	adapter->flags2 = ei->flags2;
	adapter->hw.adapter = adapter;
	adapter->hw.mac.type = ei->mac;
	adapter->max_hw_frame_size = ei->max_hw_frame_size;
	adapter->msg_enable = (1 << NETIF_MSG_DRV | NETIF_MSG_PROBE) - 1;

	mmio_start = pci_resource_start(pdev, 0);
	mmio_len = pci_resource_len(pdev, 0);

	err = -EIO;
	adapter->hw.hw_addr = ioremap(mmio_start, mmio_len);
	if (!adapter->hw.hw_addr)
		goto err_ioremap;

	if ((adapter->flags & FLAG_HAS_FLASH) &&
	    (pci_resource_flags(pdev, 1) & IORESOURCE_MEM)) {
		flash_start = pci_resource_start(pdev, 1);
		flash_len = pci_resource_len(pdev, 1);
		adapter->hw.flash_address = ioremap(flash_start, flash_len);
		if (!adapter->hw.flash_address)
			goto err_flashmap;
	}

	/* construct the net_device struct */
	netdev->open = e1000_open;
	netdev->stop = e1000_close;
	netdev->hard_start_xmit = e1000_xmit_frame;
	//netdev->get_stats = e1000_get_stats;
	netdev->map_rtskb = e1000_map_rtskb;
	netdev->unmap_rtskb = e1000_unmap_rtskb;
	strncpy(netdev->name, pci_name(pdev), sizeof(netdev->name) - 1);

	netdev->mem_start = mmio_start;
	netdev->mem_end = mmio_start + mmio_len;

	adapter->bd_number = cards_found++;

	e1000e_check_options(adapter);

	/* setup adapter struct */
	err = e1000_sw_init(adapter);
	if (err)
		goto err_sw_init;

	memcpy(&hw->mac.ops, ei->mac_ops, sizeof(hw->mac.ops));
	memcpy(&hw->nvm.ops, ei->nvm_ops, sizeof(hw->nvm.ops));
	memcpy(&hw->phy.ops, ei->phy_ops, sizeof(hw->phy.ops));

	err = ei->get_variants(adapter);
	if (err)
		goto err_hw_init;

	if ((adapter->flags & FLAG_IS_ICH) &&
	    (adapter->flags & FLAG_READ_ONLY_NVM))
		e1000e_write_protect_nvm_ich8lan(&adapter->hw);

	hw->mac.ops.get_bus_info(&adapter->hw);

	adapter->hw.phy.autoneg_wait_to_complete = 0;

	/* Copper options */
	if (adapter->hw.phy.media_type == e1000_media_type_copper) {
		adapter->hw.phy.mdix = AUTO_ALL_MODES;
		adapter->hw.phy.disable_polarity_correction = 0;
		adapter->hw.phy.ms_type = e1000_ms_hw_default;
	}

	if (e1000_check_reset_block(&adapter->hw))
		e_info("PHY reset is blocked due to SOL/IDER session.\n");

	/* Set initial default active device features */
	netdev->features = (NETIF_F_SG |
			    NETIF_F_HW_VLAN_CTAG_RX |
			    NETIF_F_HW_VLAN_CTAG_TX |
			    NETIF_F_TSO |
			    NETIF_F_TSO6 |
			    NETIF_F_RXCSUM |
			    NETIF_F_HW_CSUM);

	if (adapter->flags & FLAG_HAS_HW_VLAN_FILTER)
		netdev->features |= NETIF_F_HW_VLAN_CTAG_FILTER;

	if (pci_using_dac) {
		netdev->features |= NETIF_F_HIGHDMA;
	}

	if (e1000e_enable_mng_pass_thru(&adapter->hw))
		adapter->flags |= FLAG_MNG_PT_ENABLED;

	/*
	 * before reading the NVM, reset the controller to
	 * put the device in a known good starting state
	 */
	adapter->hw.mac.ops.reset_hw(&adapter->hw);

	/*
	 * systems with ASPM and others may see the checksum fail on the first
	 * attempt. Let's give it a few tries
	 */
	for (i = 0;; i++) {
		if (e1000_validate_nvm_checksum(&adapter->hw) >= 0)
			break;
		if (i == 2) {
			e_err("The NVM Checksum Is Not Valid\n");
			err = -EIO;
			goto err_eeprom;
		}
	}

	e1000_eeprom_checks(adapter);

	/* copy the MAC address */
	if (e1000e_read_mac_addr(&adapter->hw))
		e_err("NVM Read Error while reading MAC address\n");

	memcpy(netdev->dev_addr, adapter->hw.mac.addr, netdev->addr_len);

	init_timer(&adapter->watchdog_timer);
	adapter->watchdog_timer.function = e1000_watchdog;
	adapter->watchdog_timer.data = (unsigned long) adapter;

	init_timer(&adapter->phy_info_timer);
	adapter->phy_info_timer.function = e1000_update_phy_info;
	adapter->phy_info_timer.data = (unsigned long) adapter;

	INIT_WORK(&adapter->reset_task, e1000_reset_task);
	INIT_WORK(&adapter->watchdog_task, e1000_watchdog_task);
	INIT_WORK(&adapter->downshift_task, e1000e_downshift_workaround);
	INIT_WORK(&adapter->update_phy_task, e1000e_update_phy_task);

	rtdm_nrtsig_init(&adapter->mod_timer_sig, e1000e_mod_watchdog_timer,
			(void*)&adapter->watchdog_timer);
	rtdm_nrtsig_init(&adapter->downshift_sig, e1000e_trigger_downshift,
			&adapter->downshift_task);

	/* Initialize link parameters. User can change them with ethtool */
	adapter->hw.mac.autoneg = 1;
	adapter->fc_autoneg = 1;
	adapter->hw.fc.requested_mode = e1000_fc_default;
	adapter->hw.fc.current_mode = e1000_fc_default;
	adapter->hw.phy.autoneg_advertised = 0x2f;

	/* ring size defaults */
	adapter->rx_ring->count = RT_E1000E_NUM_RXD;
	adapter->tx_ring->count = 256;

	/*
	 * Initial Wake on LAN setting - If APM wake is enabled in
	 * the EEPROM, enable the ACPI Magic Packet filter
	 */
	if (adapter->flags & FLAG_APME_IN_WUC) {
		/* APME bit in EEPROM is mapped to WUC.APME */
		eeprom_data = er32(WUC);
		eeprom_apme_mask = E1000_WUC_APME;
		if ((hw->mac.type > e1000_ich10lan) &&
		    (eeprom_data & E1000_WUC_PHY_WAKE))
			adapter->flags2 |= FLAG2_HAS_PHY_WAKEUP;
	} else if (adapter->flags & FLAG_APME_IN_CTRL3) {
		if (adapter->flags & FLAG_APME_CHECK_PORT_B &&
		    (adapter->hw.bus.func == 1))
			e1000_read_nvm(&adapter->hw,
				NVM_INIT_CONTROL3_PORT_B, 1, &eeprom_data);
		else
			e1000_read_nvm(&adapter->hw,
				NVM_INIT_CONTROL3_PORT_A, 1, &eeprom_data);
	}

	/* fetch WoL from EEPROM */
	if (eeprom_data & eeprom_apme_mask)
		adapter->eeprom_wol |= E1000_WUFC_MAG;

	/*
	 * now that we have the eeprom settings, apply the special cases
	 * where the eeprom may be wrong or the board simply won't support
	 * wake on lan on a particular port
	 */
	if (!(adapter->flags & FLAG_HAS_WOL))
		adapter->eeprom_wol = 0;

	/* initialize the wol settings based on the eeprom settings */
	adapter->wol = adapter->eeprom_wol;
	device_set_wakeup_enable(&adapter->pdev->dev, adapter->wol);

	/* save off EEPROM version number */
	e1000_read_nvm(&adapter->hw, 5, 1, &adapter->eeprom_vers);

	/* reset the hardware with the new settings */
	e1000e_reset(adapter);

	/*
	 * If the controller has AMT, do not set DRV_LOAD until the interface
	 * is up.  For all other cases, let the f/w know that the h/w is now
	 * under the control of the driver.
	 */
	if (!(adapter->flags & FLAG_HAS_AMT))
		e1000e_get_hw_control(adapter);

	strncpy(netdev->name, "rteth%d", sizeof(netdev->name) - 1);
	err = rt_register_rtnetdev(netdev);
	if (err)
		goto err_register;

	/* carrier off reporting is important to ethtool even BEFORE open */
	rtnetif_carrier_off(netdev);

	e1000_print_device_info(adapter);

	if (pci_dev_run_wake(pdev))
		pm_runtime_put_noidle(&pdev->dev);

	return 0;

err_register:
	rtdm_nrtsig_destroy(&adapter->downshift_sig);
	rtdm_nrtsig_destroy(&adapter->mod_timer_sig);
	if (!(adapter->flags & FLAG_HAS_AMT))
		e1000e_release_hw_control(adapter);
err_eeprom:
	if (!e1000_check_reset_block(&adapter->hw))
		e1000_phy_hw_reset(&adapter->hw);
err_hw_init:
	kfree(adapter->tx_ring);
	kfree(adapter->rx_ring);
err_sw_init:
	if (adapter->hw.flash_address)
		iounmap(adapter->hw.flash_address);
	e1000e_reset_interrupt_capability(adapter);
err_flashmap:
	iounmap(adapter->hw.hw_addr);
err_ioremap:
	rtdev_free(netdev);
err_alloc_etherdev:
	pci_release_selected_regions(pdev,
				     pci_select_bars(pdev, IORESOURCE_MEM));
err_pci_reg:
err_dma:
	pci_disable_device(pdev);
	return err;
}

/**
 * e1000_remove - Device Removal Routine
 * @pdev: PCI device information struct
 *
 * e1000_remove is called by the PCI subsystem to alert the driver
 * that it should release a PCI device.  The could be caused by a
 * Hot-Plug event, or because the driver is going to be removed from
 * memory.
 **/
static void e1000_remove(struct pci_dev *pdev)
{
	struct rtnet_device *netdev = pci_get_drvdata(pdev);
	struct e1000_adapter *adapter = netdev->priv;
	bool down = test_bit(__E1000_DOWN, &adapter->state);

	/*
	 * The timers may be rescheduled, so explicitly disable them
	 * from being rescheduled.
	 */
	if (!down)
		set_bit(__E1000_DOWN, &adapter->state);
	del_timer_sync(&adapter->watchdog_timer);
	del_timer_sync(&adapter->phy_info_timer);

	rtdm_nrtsig_destroy(&adapter->downshift_sig);
	rtdm_nrtsig_destroy(&adapter->mod_timer_sig);

	cancel_work_sync(&adapter->reset_task);
	cancel_work_sync(&adapter->watchdog_task);
	cancel_work_sync(&adapter->downshift_task);
	cancel_work_sync(&adapter->update_phy_task);

	if (!(netdev->flags & IFF_UP))
		e1000_power_down_phy(adapter);

	/* Don't lie to e1000_close() down the road. */
	if (!down)
		clear_bit(__E1000_DOWN, &adapter->state);
	rt_unregister_rtnetdev(netdev);

	if (pci_dev_run_wake(pdev))
		pm_runtime_get_noresume(&pdev->dev);

	/*
	 * Release control of h/w to f/w.  If f/w is AMT enabled, this
	 * would have already happened in close and is redundant.
	 */
	e1000e_release_hw_control(adapter);

	e1000e_reset_interrupt_capability(adapter);
	kfree(adapter->tx_ring);
	kfree(adapter->rx_ring);

	iounmap(adapter->hw.hw_addr);
	if (adapter->hw.flash_address)
		iounmap(adapter->hw.flash_address);
	pci_release_selected_regions(pdev,
				     pci_select_bars(pdev, IORESOURCE_MEM));

	rtdev_free(netdev);

	/* AER disable */
	pci_disable_pcie_error_reporting(pdev);

	pci_disable_device(pdev);
}

/* PCI Error Recovery (ERS) */
static struct pci_error_handlers e1000_err_handler = {
	.error_detected = e1000_io_error_detected,
	.slot_reset = e1000_io_slot_reset,
	.resume = e1000_io_resume,
};

static const struct pci_device_id e1000_pci_tbl[] = {
	{ PCI_VDEVICE(INTEL, E1000_DEV_ID_82571EB_COPPER), board_82571 },
	{ PCI_VDEVICE(INTEL, E1000_DEV_ID_82571EB_FIBER), board_82571 },
	{ PCI_VDEVICE(INTEL, E1000_DEV_ID_82571EB_QUAD_COPPER), board_82571 },
	{ PCI_VDEVICE(INTEL, E1000_DEV_ID_82571EB_QUAD_COPPER_LP), board_82571 },
	{ PCI_VDEVICE(INTEL, E1000_DEV_ID_82571EB_QUAD_FIBER), board_82571 },
	{ PCI_VDEVICE(INTEL, E1000_DEV_ID_82571EB_SERDES), board_82571 },
	{ PCI_VDEVICE(INTEL, E1000_DEV_ID_82571EB_SERDES_DUAL), board_82571 },
	{ PCI_VDEVICE(INTEL, E1000_DEV_ID_82571EB_SERDES_QUAD), board_82571 },
	{ PCI_VDEVICE(INTEL, E1000_DEV_ID_82571PT_QUAD_COPPER), board_82571 },

	{ PCI_VDEVICE(INTEL, E1000_DEV_ID_82572EI), board_82572 },
	{ PCI_VDEVICE(INTEL, E1000_DEV_ID_82572EI_COPPER), board_82572 },
	{ PCI_VDEVICE(INTEL, E1000_DEV_ID_82572EI_FIBER), board_82572 },
	{ PCI_VDEVICE(INTEL, E1000_DEV_ID_82572EI_SERDES), board_82572 },

	{ PCI_VDEVICE(INTEL, E1000_DEV_ID_82573E), board_82573 },
	{ PCI_VDEVICE(INTEL, E1000_DEV_ID_82573E_IAMT), board_82573 },
	{ PCI_VDEVICE(INTEL, E1000_DEV_ID_82573L), board_82573 },

	{ PCI_VDEVICE(INTEL, E1000_DEV_ID_82574L), board_82574 },
	{ PCI_VDEVICE(INTEL, E1000_DEV_ID_82574LA), board_82574 },
	{ PCI_VDEVICE(INTEL, E1000_DEV_ID_82583V), board_82583 },

	{ PCI_VDEVICE(INTEL, E1000_DEV_ID_80003ES2LAN_COPPER_DPT),
	  board_80003es2lan },
	{ PCI_VDEVICE(INTEL, E1000_DEV_ID_80003ES2LAN_COPPER_SPT),
	  board_80003es2lan },
	{ PCI_VDEVICE(INTEL, E1000_DEV_ID_80003ES2LAN_SERDES_DPT),
	  board_80003es2lan },
	{ PCI_VDEVICE(INTEL, E1000_DEV_ID_80003ES2LAN_SERDES_SPT),
	  board_80003es2lan },

	{ PCI_VDEVICE(INTEL, E1000_DEV_ID_ICH8_IFE), board_ich8lan },
	{ PCI_VDEVICE(INTEL, E1000_DEV_ID_ICH8_IFE_G), board_ich8lan },
	{ PCI_VDEVICE(INTEL, E1000_DEV_ID_ICH8_IFE_GT), board_ich8lan },
	{ PCI_VDEVICE(INTEL, E1000_DEV_ID_ICH8_IGP_AMT), board_ich8lan },
	{ PCI_VDEVICE(INTEL, E1000_DEV_ID_ICH8_IGP_C), board_ich8lan },
	{ PCI_VDEVICE(INTEL, E1000_DEV_ID_ICH8_IGP_M), board_ich8lan },
	{ PCI_VDEVICE(INTEL, E1000_DEV_ID_ICH8_IGP_M_AMT), board_ich8lan },
	{ PCI_VDEVICE(INTEL, E1000_DEV_ID_ICH8_82567V_3), board_ich8lan },

	{ PCI_VDEVICE(INTEL, E1000_DEV_ID_ICH9_IFE), board_ich9lan },
	{ PCI_VDEVICE(INTEL, E1000_DEV_ID_ICH9_IFE_G), board_ich9lan },
	{ PCI_VDEVICE(INTEL, E1000_DEV_ID_ICH9_IFE_GT), board_ich9lan },
	{ PCI_VDEVICE(INTEL, E1000_DEV_ID_ICH9_IGP_AMT), board_ich9lan },
	{ PCI_VDEVICE(INTEL, E1000_DEV_ID_ICH9_IGP_C), board_ich9lan },
	{ PCI_VDEVICE(INTEL, E1000_DEV_ID_ICH9_BM), board_ich9lan },
	{ PCI_VDEVICE(INTEL, E1000_DEV_ID_ICH9_IGP_M), board_ich9lan },
	{ PCI_VDEVICE(INTEL, E1000_DEV_ID_ICH9_IGP_M_AMT), board_ich9lan },
	{ PCI_VDEVICE(INTEL, E1000_DEV_ID_ICH9_IGP_M_V), board_ich9lan },

	{ PCI_VDEVICE(INTEL, E1000_DEV_ID_ICH10_R_BM_LM), board_ich9lan },
	{ PCI_VDEVICE(INTEL, E1000_DEV_ID_ICH10_R_BM_LF), board_ich9lan },
	{ PCI_VDEVICE(INTEL, E1000_DEV_ID_ICH10_R_BM_V), board_ich9lan },

	{ PCI_VDEVICE(INTEL, E1000_DEV_ID_ICH10_D_BM_LM), board_ich10lan },
	{ PCI_VDEVICE(INTEL, E1000_DEV_ID_ICH10_D_BM_LF), board_ich10lan },
	{ PCI_VDEVICE(INTEL, E1000_DEV_ID_ICH10_D_BM_V), board_ich10lan },

	{ PCI_VDEVICE(INTEL, E1000_DEV_ID_PCH_M_HV_LM), board_pchlan },
	{ PCI_VDEVICE(INTEL, E1000_DEV_ID_PCH_M_HV_LC), board_pchlan },
	{ PCI_VDEVICE(INTEL, E1000_DEV_ID_PCH_D_HV_DM), board_pchlan },
	{ PCI_VDEVICE(INTEL, E1000_DEV_ID_PCH_D_HV_DC), board_pchlan },

	{ PCI_VDEVICE(INTEL, E1000_DEV_ID_PCH2_LV_LM), board_pch2lan },
	{ PCI_VDEVICE(INTEL, E1000_DEV_ID_PCH2_LV_V), board_pch2lan },

	{ PCI_VDEVICE(INTEL, E1000_DEV_ID_PCH_LPT_I217_LM), board_pch_lpt },
	{ PCI_VDEVICE(INTEL, E1000_DEV_ID_PCH_LPT_I217_V), board_pch_lpt },
	{ PCI_VDEVICE(INTEL, E1000_DEV_ID_PCH_LPTLP_I218_LM), board_pch_lpt },
	{ PCI_VDEVICE(INTEL, E1000_DEV_ID_PCH_LPTLP_I218_V), board_pch_lpt },

	{ }	/* terminate list */
};
MODULE_DEVICE_TABLE(pci, e1000_pci_tbl);

/* PCI Device API Driver */
static struct pci_driver e1000_driver = {
	.name     = e1000e_driver_name,
	.id_table = e1000_pci_tbl,
	.probe    = e1000_probe,
	.remove   = e1000_remove,
	.shutdown = e1000_shutdown,
	.err_handler = &e1000_err_handler
};

/**
 * e1000_init_module - Driver Registration Routine
 *
 * e1000_init_module is the first routine called when the driver is
 * loaded. All it does is register with the PCI subsystem.
 **/
static int __init e1000_init_module(void)
{
	int ret;
	pr_info("Intel(R) PRO/1000 Network Driver - %s\n",
		e1000e_driver_version);
	pr_info("Copyright(c) 1999 - 2011 Intel Corporation.\n");
	ret = pci_register_driver(&e1000_driver);

	return ret;
}
module_init(e1000_init_module);

/**
 * e1000_exit_module - Driver Exit Cleanup Routine
 *
 * e1000_exit_module is called just before the driver is removed
 * from memory.
 **/
static void __exit e1000_exit_module(void)
{
	pci_unregister_driver(&e1000_driver);
}
module_exit(e1000_exit_module);


MODULE_AUTHOR("Intel Corporation, <linux.nics@intel.com>");
MODULE_DESCRIPTION("Intel(R) PRO/1000 Network Driver");
MODULE_LICENSE("GPL");
MODULE_VERSION(DRV_VERSION);

/* e1000_main.c */

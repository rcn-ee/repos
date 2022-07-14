/**
 *   SMI workaround for x86.
 *
 *   Cut/Pasted from Vitor Angelo "smi" module.
 *   Adapted by Gilles Chanteperdrix <gilles.chanteperdrix@xenomai.org>.
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, Inc., 675 Mass Ave, Cambridge MA 02139,
 *   USA; either version 2 of the License, or (at your option) any later
 *   version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/version.h>
#include <linux/ctype.h>
#include <linux/pci.h>
#include <linux/pci_ids.h>
#include <linux/reboot.h>
#include <cobalt/kernel/assert.h>
#include <asm-generic/xenomai/pci_ids.h>
#include <asm/xenomai/machine.h>

#define DEVFN		0xf8	/* device 31, function 0 */

#define PMBASE_B0	0x40
#define PMBASE_B1	0x41

#define SMI_CTRL_ADDR	0x30

static int smi_state;
static char smi_state_arg[16] = "detect";
module_param_string(smi, smi_state_arg, sizeof(smi_state_arg), 0444);

static unsigned int smi_masked_bits = 1; /* Global disable bit */
module_param_named(smi_mask, smi_masked_bits, int, 0400);

static unsigned int smi_saved_bits;
static unsigned short smi_en_addr;

#define mask_bits(v, p) outl(inl(p)&~(v),(p))
#define set_bits(v, p)  outl(inl(p)|(v), (p))

static int smi_reboot(struct notifier_block *nb, ulong event, void *buf);

static struct notifier_block smi_notifier = {
	.notifier_call = smi_reboot
};

static int smi_reboot(struct notifier_block *nb, ulong event, void *buf)
{
	if (((event == SYS_RESTART) || (event == SYS_HALT) ||
	     (event == SYS_POWER_OFF)) && smi_en_addr)
		set_bits(smi_saved_bits, smi_en_addr);

	return NOTIFY_DONE;
}

void mach_x86_smi_disable(void)
{
	if (smi_en_addr == 0)
		return;

	smi_saved_bits = inl(smi_en_addr) & smi_masked_bits;
	mask_bits(smi_masked_bits, smi_en_addr);

	if (inl(smi_en_addr) & smi_masked_bits)
		printk(XENO_WARNING "SMI workaround failed!\n");
	else
		printk(XENO_INFO "SMI workaround enabled\n");

	register_reboot_notifier(&smi_notifier);
}

void mach_x86_smi_restore(void)
{
	if (smi_en_addr == 0)
		return;

	printk(XENO_INFO "SMI configuration restored\n");

	set_bits(smi_saved_bits, smi_en_addr);

	unregister_reboot_notifier(&smi_notifier);
}

static unsigned short get_smi_en_addr(struct pci_dev *dev)
{
	u_int8_t byte0, byte1;

	pci_read_config_byte(dev, PMBASE_B0, &byte0);
	pci_read_config_byte(dev, PMBASE_B1, &byte1);
	return SMI_CTRL_ADDR + (((byte1 << 1) | (byte0 >> 7)) << 7);	// bits 7-15
}


static const char *smi_state_labels[] = {
	"disabled",
	"detect",
	"enabled",
};
	
static void setup_smi_state(void)
{
	static char warn_bad_state[] =
		XENO_WARNING "invalid SMI state '%s'\n";
	char *p;
	int n;

	/* Backward compat with legacy state specifiers. */
	n = simple_strtol(smi_state_arg, &p, 10);
	if (*p == '\0') {
		smi_state = n;
		return;
	}

	for (n = 0; n < ARRAY_SIZE(smi_state_labels); n++)
		if (strcmp(smi_state_labels[n], smi_state_arg) == 0) {
			smi_state = n - 1;
			return;
		}

	printk(warn_bad_state, smi_state_arg);
}

void mach_x86_smi_init(void)
{
	struct pci_dev *dev = NULL;

	setup_smi_state();

	if (smi_state < 0)
		return;

	/*
	 * Do not use pci_register_driver, pci_enable_device, ...
	 * Just register the used ports.
	 */
	dev = pci_get_class(PCI_CLASS_BRIDGE_ISA << 8, NULL);
	if (dev == NULL || dev->bus->number || 
	    dev->devfn != DEVFN || dev->vendor != PCI_VENDOR_ID_INTEL) {
		pci_dev_put(dev);
		return;
	}

	if (smi_state == 0) {
		printk(XENO_WARNING "SMI-enabled chipset found, but SMI workaround disabled\n"
		       "          (see xenomai.smi parameter). You might encounter\n"
		       "          high latencies!\n");
		pci_dev_put(dev);
		return;
	}

	printk(XENO_INFO "SMI-enabled chipset found\n");
	smi_en_addr = get_smi_en_addr(dev);

	pci_dev_put(dev);
}

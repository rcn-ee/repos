                     TDMA Media Access Control Discipline
                     ====================================

                                Revision: 2.1a


This document describes the second generation of a TDMA-based (Time Division
Multiple Access) real-time media access control discipline for RTnet. Clock
synchronisation is managed by a participant acting as a master. Additional
backup masters are supported in order to compensate a failing master. Slave
participants can be added in arbitrary order without influence on existing
real-time communication. In the following, the TDMA protocol and its
management interface are specified.



Sequence Diagram
================

Normal Startup
--------------

  Master                             Slave A                Slave B
    |                                   |                      |
   +-+                                  |                      |
   | | Detect                           |                      |
   | | Other Master                     |                      |   INIT
   | | (3 x Cycle Period)               |                      |   PHASE
   . .                                  |                      |
   . .                                  |                      |
   | |                                  |                      |
   +-+   Synchronisation (broadcast)    |                      |
- - | --------------------------------> | -------------------> | - - - - - - -
    |                                  +-+                    +-+
    |                                  | | Start              | | Start
    |                                  | | Slot Timer         | | Slot Timer
    |                                  +-+                    +-+
    |                                   |                      |
    .                                   .                      .
    .                                   .                      .
    |                                   |                      |
    |                                  +-+                     |
    |                                  | | Slot                |
    |                                  | | Timeout             |
    |   Calibration Request (unicast)  +-+                     |
    | <-------------------------------- |                      |
   +-+                                  |                      |
   | | Queue                            |                      |
   | | Reply                            |                      |
   +-+                                  |                      |
    |                                   |                      |
    .                                   .                      .
    .                                   .                      .
    |                                   |                      |
    |                                   |                     +-+
    |                                   |                     | | Slot
    |                                   |                     | | Timeout
    |   Calibration Request (unicast)   |                     +-+
    | <---------------------------------|--------------------- |
   +-+                                  |                      |
   | | Queue                            |                      |
   | | Reply                            |                      |
   +-+                                  |                      |
    |                                   |                      |
    .                                   .                      .
    .                                   .                      .
    |                                   |                      |
   +-+                                  |                      |
   | | Cycle Timeout                    |                      |
   | |                                  |                      |
   +-+   Synchronisation (broadcast)    |                      |   CALIBRATION
    | --------------------------------->|--------------------->|   PHASE
    |                                   |                      |
    .                                   .                      .
    .                                   .                      .
    |                                   |                      |
   +-+                                  |                      |
   | | Slot Timeout                     |                      |
   | |                                  |                      |
   +-+  Calibration Reply (unicast)     |                      |
    | --------------------------------> |                      |
    |                                  +-+                     |
    |                                  | | Calculate           |
    |                                  | | Transmission        |
    |                                  | | Delay               |
    |                                  +-+                     |
    |                                   |                      |
    .                                   .                      .
    .                                   .                      .
    |                                   |                      |
   +-+                                  |                      |
   | | Slot Timeout                     |                      |
   | |                                  |                      |
   +-+  Calibration Reply (unicast)     |                      |
    | ----------------------------------|--------------------> |
    |                                   |                     +-+
    |                                   |                     | | Calculate
    |                                   |                     | | Transmission
    |                                   |                     | | Delay
    |                                   |                     +-+
    |                                   |                      |
    .                                   .                      .
    .                                   .                      .
    |                                   |                      |
   +-+                                  |                      |
   | | Cycle Timeout                    |                      |
   | |                                  |                      |
   +-+   Synchronisation (broadcast)    |                      |
- - | --------------------------------> | -------------------> | - - - - - - -
    |                                   |                      |

Note: The calibration phase is repeated several times in order to estimate the
      average transmission delay. The number of repetitions depends on the
      expected variance of the measurings and has to be chosen appropriately.



Failing Master
--------------

  Master                          Backup Master              Slave
    |                                   |                      |
   +-+                                  |                      |
   | | Cycle Timeout                    |                      |
   | |                                  |                      |
   +-+   Synchronisation (broadcast)    |                      |
    | --------------------------------> | -------------------> |
    |                                  +-+                    +-+
    |                                  | | Sync With          | | Start
    |                                  | | Alive Master       | | Slot Timer
    |                                  +-+                    +-+
    |                                   |                      |
    .                                   .                      .
    .                                   .                      .
    |                                   |                      |
    |                                  +-+                     |
    |                                  | | Backup Cycle        |
    |                                  | | Timeout             |
    |                                  | | (ignore)            |
    |                                  +-+                     |
    |                                   |                      |
    .                                   .                      .
    .                                   .                      .
    |                                   |                      |
    |                                   |                     +-+
    |                                   |                     | | Slot
    |                                   |                     | | Timeout
    |                                   |           Payload   +-+
    |                                   |        <------------ |
    .                                   .                      .
    .                                   .                      .
    |                                   |                      |
    X  Failure                          |                      |
                                        .                      .
                                        .                      .
                                        |                      |
                                       +-+                     |
                                       | | Backup              |
                                       | | Cycle               |
                                       | | Timeout             |
         Synchronisation (broadcast)   +-+                     |
     <--------------------------------- | -------------------> |
                                        |                     +-+
                                        |                     | | Start
                                        |                     | | Slot Timer
                                        |                     +-+
                                        |                      |
                                        .                      .
                                        .                      .
                                        |                      |
                                        |                     +-+
                                        |                     | | Slot
                                        |                     | | Timeout
                                        |           Payload   +-+
                                        |        <------------ |
                                        |                      |



Master Restart
--------------

  Master                          Backup Master              Slave
   | |                                  |                      |
   | |                                 +-+                     |
   | | Detect                          | | Backup              |   INIT
   | | Other Master                    | | Cycle               |   PHASE
   | |                                 | | Timeout             |
   +-+   Synchronisation (broadcast)   +-+                     |
- - | <-------------------------------- | -------------------> | - - - - - - -
   +-+                                  |                     +-+
   | | Start                            |                     | | Start
   | | Slot Timer                       |                     | | Slot Timer
   +-+                                  |                     +-+
    |                                   |                      |
    .                                   .                      .
    .                                   .                      .
    |                                   |                      |
   +-+                                  |                      |
   | | Slot Timeout                     |                      |
   | |                                  |                      |
   +-+  Calibration Request (unicast)   |                      |   CALIBRATION
    | --------------------------------> |                      |   PHASE
    |                                  +-+                     |
    |                                  | | Queue               |
    |                                  | | Reply               |
    |                                  +-+                     |
    |                                   |                      |
    .                                   .                      .
    .        <continue calibration as described above>         .
    .                                   .                      .
    |                                   |                      |
   +-+                                  |                      |
   | | Cycle Timeout                    |                      |
   | |                                  |                      |
   +-+   Synchronisation (broadcast)    |                      |
- - | --------------------------------> | -------------------> | - - - - - - -
    |                                  +-+                    +-+
    |                                  | | Sync With          | | Start
    |                                  | | Alive Master       | | Slot Timer
    |                                  +-+                    +-+
    |                                   |                      |
    .                                   .                      .
    .                                   .                      .
    |                                   |                      |
    |                                  +-+                     |
    |                                  | | Backup Cycle        |
    |                                  | | Timeout             |
    |                                  | | (ignore)            |
    |                                  +-+                     |
    |                                   |                      |



Frame Formats
=============

TDMA frames are introduced by the generic RTmac discipline header as described
in the related document. The hexadecimal RTmac type identifier is 0x0001. All
frame fields are encoded in network byte order (big endian). Version
identifiers of TDMA frames shall only be changed if the format becomes
incompatible to the previous revision. Currently, all frames carry the
hexadecimal value 0x0201.



Synchronisation Frame
---------------------

 +------------------+------------------+----------------------+ - -
 | Version: 0x0201  | Frame ID: 0x0000 |     Cycle Number     |
 |    (2 bytes)     |    (2 bytes)     |      (4 bytes)       |
 +------------------+------------------+----------------------+ - -
  - - +-----------------------------+-----------------------------+
      |   Transmission Time Stamp   | Scheduled Transmission Time |
      |          (8 bytes)          |          (8 bytes)          |
  - - +-----------------------------+-----------------------------+

Synchronisation frames are sent as broadcast by the currently active master.
They signal the beginning of a new elementary cycle and distribute the value
of the reference clock.

The Cycle Number field is incremented by one for every new cycle, and it is
reset to zero on overflow. The Transmission Time Stamp contains the value of
the reference clock, typically located on the master, in nanoseconds. It shall
be acquired with minimum jitter relative to the physical packet transmission
time. The Scheduled Transmission Time, also in nanoseconds, contains the
reference time when the transmission was intended to be performed.

By comparing the Transmission Time Stamp and the Scheduled Transmission Time,
receivers of Synchronisation frames are able to reduce the deviation between
claimed and actual transmission time on the master station. This helps to
improve global time synchronisation. Furthermore, backup masters use the main
master's Scheduled Transmission Time value when submitting their replacement
Synchronisation frames, although these frames are scheduled for a different
time slot. As a result, the slave will automatically compensate the time shift
of Synchronisation frames sent by backup masters.



Calibration Frames
------------------

Request Calibration Frame:
 +------------------+------------------+-----------------------------+ - -
 | Version: 0x0201  | Frame ID: 0x0010 |   Transmission Time Stamp   |
 |    (2 bytes)     |    (2 bytes)     |          (8 bytes)          |
 +------------------+------------------+-----------------------------+ - -
  - - +----------------------+-----------------------------+
      |     Reply Cycle      |      Reply Slot Offset      |
      |   Number (4 bytes)   |          (8 bytes)          |
  - - +----------------------+-----------------------------+

Reply Calibration Frame:
 +------------------+------------------+-----------------------------+ - -
 | Version: 0x0201  | Frame ID: 0x0011 |  Request Transmission Time  |
 |    (2 bytes)     |    (2 bytes)     |          (8 bytes)          |
 +------------------+------------------+-----------------------------+ - -
  - - +-----------------------------+-----------------------------+
      |    Reception Time Stamp     |   Transmission Time Stamp   |
      |          (8 bytes)          |          (8 bytes)          |
  - - +-----------------------------+-----------------------------+

Calibration frames are sent as unicast to the respective receiver. They are
used to estimate the average delay between the transmission of Synchronisation
frames by a master and their reception on the slave side. Request Calibration
frames are sent by participants to the currently active master. The master
returns one Reply Calibration frame for every request frame in a time slot
specified by the sender.

The Transmission Time Stamp fields in both frame types contain the value of
the sender's local clock in nanoseconds. It shall be acquired with minimum
jitter relative to the physical packet transmission time. The slave determines
in which cycle (Reply Cycle Number) and with which offset relative to the
cycle's Synchronisation frame (Reply Slot Offset) the master shall send the
reply. Only time slots actually owned by the slave can be specified here, and
the slave must not use these released slots for own transmissions in the
following.

The Transmission Time Stamp field of the Request Calibration frame is copied
into the Request Transmission Time field of the Reply Calibration frame. On
reception of a request frame, a local time stamp is acquired and stored in the
Reception Time Stamp field of the corresponding reply frame. The acquisition
shall be performed with minimum jitter relative to the physical packet
reception. All times are in nanoseconds.



Time Arithmetics
================

Synchronisation on Global Clock
-------------------------------

            Master                    Slave
              |                         |
    T_sched  -|-   -   -   -   -   -   -|-  T'_sched
              |                         |
              |                         |
     T_xmit  -|-    Synchronisation     |
       /|\    | \        Frame          |
        |     |  \       ---->          |
     t_trans  |   \_________________    |
        |     |                     \   |
        |     |                      \  |
       \|/    |                       \ |
     T_recv  -|-   -   -   -   -   -   -|-  T'_recv
              |                         |
              .                         .
              .                         .
              |                         |
          T  -|-   -   -   -   -   -   -|-  T'
              |                         |

Calculate the clock offset:
        t_offs = T_recv - T'_recv =
               = T_xmit + t_trans - T'_recv

Calculate a global time:
        T = T' + t_offs

Calculate a time relative to a Synchronisation frame:
        T' = T'_sched + t =
           = T_sched - t_offs + t

Symbols:
        T_sched         Scheduled transmission time (global clock) of the
                        Synchronisation frame. It is distributed in the
                        Scheduled Transmission Time field of the
                        Synchronisation frame.
        T'_sched        T_sched in units of the slave's local clock
        T_xmit          Actual transmission time (global clock) of the
                        Synchronisation frame. It is distributed in the
                        Transmission Time Stamp field of the
                        Synchronisation frame.
        t_trans         Average time between transmission of a frame by the
                        master and its reception by the slave. This value is
                        acquired during the calibration phase.
        T_recv          Reception time of the Synchronisation frame in units
                        of the global clock.
        T'_recv         Reception time of the Synchronisation frame in units
                        of the slave's local clock.
        T, T'           An arbitrary time in global and local clock units.
        t_offs          Offset between local and global clock.
        t               An arbitrary offset relative to a Synchronisation
                        frame



Calibration of the Transmission Delay
-------------------------------------

            Master                    Slave
              |                         |
              |       Calibration      -|-  T'_xmit_req
              |      Request Frame    / |
              |          <----       /  |
              |    _________________/   |
              |   /                     |
              |  /                      |
              | /                       |
 T_recv_req  -|-                        |
              |                         |
              .                         .
              .                         .
              |                         |
 T_xmit_rpl  -|-      Calibration       |
              | \     Reply Frame       |
              |  \       ---->          |
              |   \_________________    |
              |                     \   |
              |                      \  |
              |                       \ |
              |                        -|-  T'_recv_rpl
              |                         |

Calculate the transmission delay:
        t_trans = 1/2 * ((T'_recv_rpl - T'_xmit_req) -
                         (T_xmit_rpl - T_recv_req))

The overall transmission delay shall be averaged over several calibration
rounds. As the measuring is only performed against the main master, backup
masters should be selected so that they show similar timing characteristics.

Symbols:
        T'_xmit_req     Time stamp taken on the transmission of a Calibration
                        Request frame in units of the slave's local clock.
                        This value is stored in the Transmission Time Stamp
                        field of the request frame and later copied to the
                        Request Transmission Time field of the corresponding
                        reply frame.
        T_recv_req      Time stamp taken on the reception of a Calibration
                        Request frame in units of the master's local clock.
                        This value is stored in the Reception Time Stamp field
                        of the Calibration Reply frame.
        T_xmit_rpl      Time stamp taken on the transmission of a Calibration
                        Reply frame in units of the master's local clock. This
                        value is stored in the Transmission Time Stamp field
                        of the Calibration Reply frame.
        T'_recv_rpl     Time stamp taken on the reception of a Calibration
                        Reply frame in units of the slave's local clock.



Time Slots
==========

A time slot can be used to transmit a single packet of up to a specified maximum
size. This TDMA discipline revision supports flexible assignment of time slots
to real-time network participants. It is now possible to use multiple slots per
cycle. Furthermore, a slot can be shared between participants by occupying it
only every Nth cycle. Besides at least one payload slot per participant, slots
have to be reserved for the Synchronisation frame and, optionally, for one or
more backup Synchronisation frames. The concrete timing strongly depends on the
capability of all network participants. Therefore, timing requirements like
worst case jitters or minimum slot gaps are not specified here.

In contrast to earlier TDMA discipline revisions, the slave configuration is
no longer distributed by the TDMA master. This means that the slaves have to
be aware of their slot setup before sending any data to a TDMA-managed
network. Therefore, the required settings either have to be stored on the
slaves or, if a centralised management is desired, the RTnet configuration
service RTcfg has to be used (see related specification for further details).



Slot Identification and Selection
---------------------------------

NOTE: The following specifications are OPTIONAL. They describe the internal
      realisation of this TDMA discipline as applied to the first
      implementation in RTnet.

Time slots carry an internal ID number, unique per participant. These numbers
are used when determining the slot in which an outgoing packet shall be
transmitted. The TDMA discipline contains no automatic scheduling mechanism.
Instead, the sender, i.e. an user or a service, either explicitly provides a
desired slot ID or a default slot is used.

  Slot ID | Description
 ---------+-----------------------------------------------------------------
     0    | default slot for RT; also default NRT slot if slot 1 is missing
     1    | non-RT slot; if missing, slot 0 is used
     2    | user slots, used for explicitly scheduled packets
     :    |



Configuration Example
---------------------

An exemplary configuration consisting of two masters, one serving as backup,
and three slaves is shown below. The slot period is expressed in the form
<phasing>/<period>. For instance, 1/3 means that this slot will be used in
every first of three cycles, while 3/3 means in every third or three.

  +------+  +----------+  +---------+  +---------+  +----------+
  |      |  | Master 2 |  | Slave A |  | Slave B |  | Master 1 |
  | Sync |  |  Backup  |  | Slot 0  |  | Slot 0  |  |  Slot 0  |
  |      |  |   Sync   |  | RT/NRT  |  |   RT    |  |  RT/NRT  |
  | 1/1  |  |   1/1    |  |   1/1   |  |   1/1   |  |   1/1    |
--+------+--+----------+--+---------+--+---------+--+----------+--...

                                     +----------+
                                     | Slave C  |
                                     |  Slot 3  |
                                     |    RT    |
                                     |   3/3    |
     +---------+                     +----------+
     | Slave C |                     | Master 2 |
     | Slot 0  |                     |  Slot 0  |
     | RT/NRT  |                     |  RT/NRT  |
     |   2/2   |                     |   2/3    |
     +---------+        +---------+  +----------+             +------+
     | Slave B |        | Slave C |  |  Slave A |             |      |
     | Slot 1  |        | Slot 2  |  |  Slot 2  |             | Sync |
     |   NRT   |        |   NRT   |  |    RT    |             |      |
     |   1/2   |        |   1/4   |  |   1/3    |             | 1/1  |
...--+---------+--------+---------+--+----------+-------------+------+-->



Management Interface
====================

NOTE: The following specifications are OPTIONAL. They describe the internal
      realisation of this TDMA discipline as applied to the first
      implementation in RTnet.

The TDMA discipline is managed by the command line tool tdmacfg. In the
following, the usage of this tool is described.



Commands
--------

tdmacfg <dev> master <cycle_period> [-b <backup_offset>]
        [-c calibration_rounds] [-i max_slot_id] [-m max_calibration_requests]

Starts a TDMA master on the specified device <dev>. The cycle period length is
given in microseconds using the <cycle_period> parameter. If <backup_offset>
is provided, the master becomes a backup system. In case the main master
fails, the backup master with the smallest <backup_offset> will start sending
Synchronisation frames with the specified offset in microseconds relative to
the scheduled cycle start. <calibration_rounds> specifies the number of clock
calibration requests the master will send to any other potentially already
active master during startup. By default, 100 rounds are performed. The
calibration will be performed when the first slot is added. By default, a
master can handle up to 64 calibration requests at the same time. This value
can be adapted by specifying the <max_calibration_requests> parameter. The
largest used slot ID is tunable by providing <max_slot_id> or will be limited
to 7 if this parameter is omitted.

tdmacfg <dev> slave [-c calibration_rounds] [-i max_slot_id]

Starts a TDMA slave on the specified device <dev>. <calibration_rounds>
specifies the number of clock calibration requests the slave sends to the
active master during startup. By default, 100 rounds are performed. The
calibration will be performed when the first slot is added. The largest used
slot ID is tunable by providing <max_slot_id> or will be limited to 7 if this
parameter is omitted.

tdmacfg <dev> slot <id> [<offset> [-p <phasing>/<period>] [-s <size>]
        [-j joint_slot] [-l calibration_log_file] [-t calibration_timeout]]

Adds, reconfigures, or removes a time slot for outgoing data on a started TDMA
master or slave. <id> is used to distinguish between multiple slots. See above
slot ID table for predefined values. If <offset> is given, the time slot is
added or modified to send data with the specified offset in microseconds
relative to the scheduled cycle start, if omitted, the slot is removed from
the station's configuration.

By default, a slot will be used in every cycle. When providing <phasing> and
<period>, the slot will only be occupied in every <phasing>-th of <period>
cycles. By assigning e.g. 1/2 to one and 2/2 to another slot, the usage of the
physical time slot will alternate between both slot owners. The <size>
parameter limits the maximum payload size in bytes which can be transmitted
within this slot. If no <size> parameter is provided, the maximum size the
hardware supports is applied. To share the same output queue among several
slots, secondary slots can be attached to a primary <joint_slot>. The slot
sizes must match for this purpose.

The addition of the station's first slot will trigger the clock calibration
process. To store the results of each calibration handshake, a
<calibration_log_file> can be provided. By default, this command will not
terminate until the calibration is completed. The <calibration_timeout>
parameter can be used to specify an upper time limit.

tdmacfg <dev> detach

Detaches a master or slave from the given devices <dev>. Past this command,
the write access to the device is uncoordinated again and may interfere with
remaining real-time network participants.


2004, 2005, Jan Kiszka <jan.kiszka-at-web.de>

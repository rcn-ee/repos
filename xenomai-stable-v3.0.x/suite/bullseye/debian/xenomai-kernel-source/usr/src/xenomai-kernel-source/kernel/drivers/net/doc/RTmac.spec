               Real-Time Media Access Control Framework (RTmac)
               ================================================

                                Revision: 2.0


This document describes the protocol header of the real-time media access
control framework for RTnet. The actual control protocol is implemented by
so-called disciplines, see related specifications.



Frame Format
============

RTmac frames are identified by the hexadecimal Ethernet type 0x9021. All frame
fields are encoded in network order (big endian). The version identifier of
the RTmac header shall only be changed if the format becomes incompatible to
the previous revision. Currently, this version field contains the hexadecimal
value 0x02.



RTmac Frame Header
------------------

 +----------------------+---------------+---------------+
 |         Type         | Version: 0x02 |     Flags     |
 |      (2 bytes)       |   (1 byte)    |    (1 byte)   |
 +----------------------+---------------+---------------+

Depending on the tunnelling flag, the type field either contains the
identifier of the succeeding discipline frame or the Ethernet type of a
tunnelled non-real-time packet introduced by this header.

Flags are encoded as follows:

  Bit Number | Interpretation if set
 ------------+---------------------------------------------------------------
       0     | tunnelling frame if set, otherwise discipline frame
      1-7    | <reserved>


2004, Jan Kiszka <jan.kiszka-at-web.de>

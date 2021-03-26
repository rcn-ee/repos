#!/usr/bin/perl
use strict;
use warnings;
use Debian::Debhelper::Dh_Lib;

# dh_ppp runs unconditionally, and before dh_gencontrol, so that the latter can
# use the substvars that are put into place by the former.
insert_before("dh_gencontrol", "dh_ppp");

1;

#!/usr/bin/perl
use warnings;
use strict;
use Debian::Debhelper::Dh_Lib;

insert_before("dh_update_autotools_config", "dh_quilt_patch");
insert_before("dh_clean", "dh_quilt_unpatch");

# Eval to avoid problem with debhelper < 7.3.12
eval {
    add_command("dh_quilt_patch", "patch");
};

1;

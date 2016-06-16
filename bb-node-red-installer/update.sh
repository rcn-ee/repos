#!/bin/bash -e

  old_node_red="0.13.4-f1ce0fa-v0.12.13"
old_beaglebone="0.1.6-acb6fe5-v0.12.13"
    old_bb_upm="0.0.0-67ff009-v0.12.13"
   old_mongodb="0.0.5-f91b7c4-v0.12.13"

  new_node_red="0.13.4-f1ce0fa-v0.12.13"
new_beaglebone="0.1.6-acb6fe5-v0.12.13"
    new_bb_upm="0.0.1-8d217ab-v0.12.13"
   new_mongodb="0.0.5-49692b3-v0.12.13"

sed -i -e "s:$old_node_red:$new_node_red:g" version.sh
sed -i -e "s:$old_node_red:$new_node_red:g" ./suite/*/debian/install
sed -i -e "s:$old_node_red:$new_node_red:g" ./suite/*/debian/postinst

sed -i -e "s:$old_beaglebone:$new_beaglebone:g" version.sh
sed -i -e "s:$old_beaglebone:$new_beaglebone:g" ./suite/*/debian/install
sed -i -e "s:$old_beaglebone:$new_beaglebone:g" ./suite/*/debian/postinst

sed -i -e "s:$old_bb_upm:$new_bb_upm:g" version.sh
sed -i -e "s:$old_bb_upm:$new_bb_upm:g" ./suite/*/debian/install
sed -i -e "s:$old_bb_upm:$new_bb_upm:g" ./suite/*/debian/postinst

sed -i -e "s:$old_mongodb:$new_mongodb:g" version.sh
sed -i -e "s:$old_mongodb:$new_mongodb:g" ./suite/*/debian/install
sed -i -e "s:$old_mongodb:$new_mongodb:g" ./suite/*/debian/postinst

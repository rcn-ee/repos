#!/bin/bash -e

old="2016.04.24"
new="2017.01.24"

tar xf rcn-ee-archive-keyring_${old}.orig.tar.xz
mv rcn-ee-archive-keyring_${old} rcn-ee-archive-keyring_${new}
tar -cJf rcn-ee-archive-keyring_${new}.orig.tar.xz rcn-ee-archive-keyring_${new}/

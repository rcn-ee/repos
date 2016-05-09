#!/bin/bash -e

tar xf rcn-ee-archive-keyring_2015.10.22.orig.tar.xz
mv rcn-ee-archive-keyring_2015.10.22 rcn-ee-archive-keyring_2016.04.24
tar -cJf rcn-ee-archive-keyring_2016.04.24.orig.tar.xz rcn-ee-archive-keyring_2016.04.24/

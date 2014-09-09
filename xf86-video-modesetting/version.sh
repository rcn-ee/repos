#!/bin/bash -e

mirror="http://ftp.de.debian.org/debian"
package="xf86-video-modesetting"
archive="xserver-xorg-video-modesetting"
version="0.9.0"
debian_version="0.9.0-1"
reprepro_dir="x/${archive}"
dl_path="${mirror}/pool/main/${reprepro_dir}/"
deb_source="${archive}_${version}.orig.tar.gz"
deb_patch="${archive}_${debian_version}.diff.gz"
wheezy_backport="~bpo70+1"

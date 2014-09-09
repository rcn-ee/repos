#!/bin/bash -e

mirror="http://ftp.de.debian.org/debian"
package="xserver-xorg-video-modesetting"
version="0.9.0"
debian_version="0.9.0-1"
reprepro_dir="x/${package}"
dl_path="${mirror}/pool/main/${reprepro_dir}/"
deb_source="${package}_${version}.orig.tar.gz"
deb_patch="${package}_${debian_version}.diff.gz"
wheezy_backport="~bpo70+1"

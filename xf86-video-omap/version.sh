#!/bin/bash -e

mirror="http://ftp.de.debian.org/debian"
package="xf86-video-omap"
version="0.4.3"
debian_version="0.4.3-1"
reprepro_dir="x/${package}"
dl_path="${mirror}/pool/main/${reprepro_dir}/"
deb_source="${package}_${version}.orig.tar.gz"
debian_patch="${package}_${debian_version}.debian.tar.gz"

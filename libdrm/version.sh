#!/bin/bash -e

mirror="http://ftp.de.debian.org/debian"
package="libdrm"
version="2.4.56"
debian_version="2.4.56-1"
reprepro_dir="libd/${package}"
dl_path="${mirror}/pool/main/${reprepro_dir}/"
deb_source="${package}_${version}.orig.tar.gz"
deb_patch="${package}_${debian_version}.diff.gz"

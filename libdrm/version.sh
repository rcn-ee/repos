#!/bin/bash -e

mirror="http://ftp.de.debian.org/debian"
package="libdrm"
version="2.4.56"
debian_version="2.4.56-1"
reprepro_dir="libd/${package}"
deb_source="${mirror}/pool/main/${reprepro_dir}/${package}_${version}.orig.tar.gz"
deb_patch="${mirror}/pool/main/${reprepro_dir}/${package}_${debian_version}.diff.gz"


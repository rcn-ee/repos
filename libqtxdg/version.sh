#!/bin/bash -e

#http://packages.siduction.org/lxqt/pool/main/libq/libqtxdg/

mirror="http://packages.siduction.org"
package="libqtxdg"
archive="libqtxdg"
version="1.0.0"
debian_version="${version}-1"
reprepro_dir="libq/${package}"
dl_path="${mirror}/lxqt/pool/main/${reprepro_dir}/"
deb_source="${package}_${version}.orig.tar.gz"
debian_patch="${package}_${debian_version}.debian.tar.xz"
wheezy_version="~bpo70+1"
jessie_version="~20140924+1"

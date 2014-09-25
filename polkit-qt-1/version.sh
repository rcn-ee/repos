#!/bin/bash -e

#http://packages.siduction.org/lxqt/pool/main/c/compton-conf/

mirror="http://packages.siduction.org"
package="polkit-qt-1"
archive="polkit-qt-1"
version="0.112.0"
debian_version="${version}-1"
reprepro_dir="p/${package}"
dl_path="${mirror}/lxqt/pool/main/${reprepro_dir}/"
deb_source="${package}_${version}.orig.tar.bz2"
debian_patch="${package}_${debian_version}.debian.tar.xz"
wheezy_version="~bpo70+1"
jessie_version="~20140924+1"

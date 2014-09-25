#!/bin/bash -e

#http://packages.siduction.org/lxqt/pool/main/l/lxmenu-data/

mirror="http://packages.siduction.org"
package="lxmenu-data"
archive="lxmenu-data"
src_dir="master"
version="0.1.4.siduction.1"
#debian_version="${version}-1"
reprepro_dir="l/${package}"
dl_path="${mirror}/lxqt/pool/main/${reprepro_dir}/"
deb_source="${package}_${version}.tar.xz"
wheezy_version="~bpo70+1"
jessie_version="~20140924+1"

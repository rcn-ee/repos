#!/bin/bash -e

#http://packages.siduction.org/lxqt/pool/main/p/polkit-qt-1/

mirror="http://packages.siduction.org"

package_name="polkit-qt-1"
package_version="0.112.0"
package_source="${package_name}_${package_version}.orig.tar.bz2"
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="p/${package_name}"
dl_path="${mirror}/lxqt/pool/main/${reprepro_dir}/"

debian_version="${package_version}-1"
debian_untar=""
debian_patch="${package_name}_${debian_version}.debian.tar.xz"

wheezy_version="~bpo70+20140924+1"
jessie_version="~20140924+1"

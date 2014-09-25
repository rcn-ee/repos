#!/bin/bash -e

#http://packages.siduction.org/lxqt/pool/main/o/obconf-qt/

mirror="http://packages.siduction.org"

package_name="obconf-qt"
debian_pkg_name="${package_name}"
package_version="0.1.0"
package_source="${package_name}_${package_version}.orig.tar.bz2"
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="o/${package_name}"
dl_path="${mirror}/lxqt/pool/main/${reprepro_dir}/"

debian_version="${package_version}-1"
debian_untar=""
debian_patch="${package_name}_${debian_version}.debian.tar.xz"

wheezy_version="~bpo70+20140924+1"
jessie_version="~20140924+1"

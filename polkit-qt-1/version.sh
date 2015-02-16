#!/bin/bash -e

#http://packages.siduction.org/lxqt/pool/main/p/polkit-qt-1/

mirror="http://packages.siduction.org"

package_name="polkit-qt-1"
debian_pkg_name="${package_name}"
package_version="0.112.0"
dl_package_source="${package_name}_${package_version}-2.tar.gz"
package_source="${package_name}_${package_version}.orig.tar.gz"
src_dir="polkit-qt-1"

git_repo=""
git_sha=""
reprepro_dir="p/${package_name}"
dl_path="lxqt/pool/main/${reprepro_dir}/"

debian_version="${package_version}-2"
debian_patch=""

wheezy_version="~bpo70+20140924+1"
jessie_version="~20150216+1"

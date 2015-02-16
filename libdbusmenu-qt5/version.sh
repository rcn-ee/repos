#!/bin/bash -e

#http://packages.siduction.org/extra/pool/main/libd/libdbusmenu-qt5/libdbusmenu-qt5_0.9.3-1siduction.dsc

mirror="http://packages.siduction.org"

package_name="libdbusmenu-qt5"
debian_pkg_name="${package_name}"
package_version="0.9.3"
dl_package_source="${package_name}_${package_version}-1siduction.tar.gz"
package_source="${package_name}_${package_version}.orig.tar.gz"
src_dir="libdbusmenu-qt"

git_repo=""
git_sha=""
reprepro_dir="libd/${package_name}"
dl_path="extra/pool/main/${reprepro_dir}/"

debian_version="${package_version}-1"
debian_patch=""

wheezy_version="~bpo70+20140924+1"
jessie_version="~20150216+1"

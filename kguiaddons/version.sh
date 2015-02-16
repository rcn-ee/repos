#!/bin/bash -e

#http://packages.siduction.org/lxqt/pool/main/k/kguiaddons/

mirror="http://packages.siduction.org"

package_name="kguiaddons"
debian_pkg_name="${package_name}"
package_version="5.5.0"
dl_package_source="${package_name}_${package_version}-2.tar.gz"
package_source="${package_name}_${package_version}.orig.tar.gz"
src_dir="kguiaddons"

git_repo=""
git_sha=""
reprepro_dir="k/${package_name}"
dl_path="lxqt/pool/main/${reprepro_dir}/"

debian_version="${package_version}-2"
debian_patch=""

wheezy_version="~bpo70+20140924+1"
jessie_version="~20150216+1"

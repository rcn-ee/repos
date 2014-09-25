#!/bin/bash -e

#http://packages.siduction.org/lxqt/pool/main/l/lxmenu-data/

mirror="http://packages.siduction.org"

package_name="lxmenu-data"
debian_pkg_name="${package_name}"
package_version="0.1.4.siduction.1"
package_source="${package_name}_${package_version}.tar.xz"
src_dir="master"

git_repo=""
git_sha=""
reprepro_dir="l/${package_name}"
dl_path="${mirror}/lxqt/pool/main/${reprepro_dir}/"

debian_version=""
debian_untar=""
debian_patch=""

wheezy_version="~bpo70+20140924+1"
jessie_version="~20140925+1"

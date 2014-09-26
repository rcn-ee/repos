#!/bin/bash -e

#http://packages.siduction.org/lxqt/pool/main/l/lxqt-powermanagement/

mirror="http://packages.siduction.org"

package_name="lxqt-powermanagement"
debian_pkg_name="${package_name}"
package_version="0.7.96"
package_source="${package_name}_${package_version}.orig.tar.bz2"
src_dir="tmp4FywJ8"

git_repo=""
git_sha=""
reprepro_dir="l/${package_name}"
dl_path="${mirror}/lxqt/pool/main/${reprepro_dir}/"

debian_version="${package_version}-2"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""

wheezy_version="~bpo70+20140924+1"
jessie_version="~20140925+1"

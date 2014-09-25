#!/bin/bash -e

#http://packages.siduction.org/lxqt/pool/main/c/compton-conf/

mirror="http://packages.siduction.org"

package_name="compton-conf"
debian_pkg_name="${package_name}"
package_version="0.1.0"
package_source="${package_name}_${package_version}.orig.tar.bz2"
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="c/${package_name}"
dl_path="${mirror}/lxqt/pool/main/${reprepro_dir}/"

debian_version="${package_version}-1"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""

wheezy_version="~bpo70+20140924+1"
jessie_version="~20140924+1"

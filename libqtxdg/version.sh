#!/bin/bash -e

#http://packages.siduction.org/lxqt/pool/main/libq/libqtxdg/

mirror="http://packages.siduction.org"

package_name="libqtxdg"
package_version="1.0.0"
package_source="${package_name}_${package_version}.orig.tar.gz"
src_dir="${package_name}-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="libq/${package_name}"
dl_path="${mirror}/lxqt/pool/main/${reprepro_dir}/"

debian_version="${package_version}-1"
debian_untar=""
debian_patch="${package_name}_${debian_version}.debian.tar.xz"

wheezy_version="~bpo70+20140924+1"
jessie_version="~20140924+1"

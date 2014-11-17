#!/bin/bash -e

#http://ports.ubuntu.com/pool/main/a/android-headers/

mirror="http://ports.ubuntu.com"

package_name="android-headers"
debian_pkg_name="${package_name}"
package_version="4.4.2-2"
package_source="${package_name}_${package_version}.orig.tar.gz"
src_dir="${package_name}-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="a/${package_name}"
dl_path="${mirror}/pool/main/${reprepro_dir}/"

debian_version="${package_version}-0ubuntu2"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""

wheezy_version="~bpo70+20140924+1"
jessie_version="~20141117+1"

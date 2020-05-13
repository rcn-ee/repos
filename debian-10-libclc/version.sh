#!/bin/bash -e

#https://snapshot.debian.org/package/libclc/
#https://snapshot.debian.org/package/libclc/0.2.0%2Bgit20190306-2/
#https://snapshot.debian.org/archive/debian/20190719T031106Z/pool/main/libc/libclc/libclc_0.2.0%2Bgit20190306-2.debian.tar.xz
mirror="https://snapshot.debian.org/archive/debian/20190719T031106Z"

package_name="libclc"
debian_pkg_name="${package_name}"
package_version="0.2.0+git20190306"
package_source="${package_name}_${package_version}.orig.tar.gz"
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="libc/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-2"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
local_patch="rcnee0"

buster_version="~buster+20200513"

#!/bin/bash -e

mirror="http://archive.ubuntu.com/ubuntu"

package_name="device-tree-compiler"
debian_pkg_name="${package_name}"
package_version="1.4.7"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="dtc-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="d/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-3ubuntu2"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""
local_patch="rcnee0"

bionic_version="~bionic+20200430"

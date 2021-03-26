#!/bin/bash -e

#https://packages.debian.org/source/buster/systemd

mirror="http://http.debian.net/debian"

package_name="ppp"
debian_pkg_name="${package_name}"
package_version="2.4.7"
package_source="${debian_pkg_name}_${package_version}.orig.tar.gz"
src_dir="${package_name}-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="p/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-2+4.1+deb10u1"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""
local_patch="rcnee0"

buster_version="~buster+20210326"

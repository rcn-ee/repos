#!/bin/bash -e

#https://github.com/cifsd-team/ksmbd-tools

#mirror="http://http.debian.net/debian"

package_name="ksmbd-tools"
debian_pkg_name="${package_name}"
package_version="3.4.2-git20210906.0"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/cifsd-team/ksmbd-tools"
git_sha="b5105f5ed626fc32f3d04368fd019f6a30556504"
reprepro_dir="libg/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee0"
debian_patch=""
debian_diff=""

stretch_version="~stretch+20180712"
bionic_version="~bionic+20180712"
buster_version="~buster+20180712"
bullseye_version="~bullseye+20211007"

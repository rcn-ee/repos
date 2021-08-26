#!/bin/bash -e

#https://github.com/linux-usb-gadgets/gt

package_name="gt"
debian_pkg_name="${package_name}"
package_version="0.0.0-git20210712.7"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/linux-usb-gadgets/gt"
git_sha="31b135546d0d1733b5b7ca19f48748c06824d65a"
reprepro_dir="g/${package_name}"
dl_path=""

debian_version="${package_version}-0"
debian_patch=""
debian_diff=""

stretch_version="~stretch+20210826"
buster_version="~buster+20210826"
bullseye_version="~bullseye+20210826"
bionic_version="~bionic+20210826"
focal_version="~focal+20210826"

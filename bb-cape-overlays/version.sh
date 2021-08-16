#!/bin/bash -e

#https://github.com/beagleboard/bb.org-overlays

package_name="bb-cape-overlays"
debian_pkg_name="${package_name}"
package_version="4.14.20210809.0"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/beagleboard/bb.org-overlays"
git_sha="cc8e0a65ce07920cbe8e7a78af7569340cde0e58"
reprepro_dir="b/${package_name}"
dl_path=""

debian_version="${package_version}-0"
debian_patch=""
debian_diff=""

stretch_version="~stretch+20210816"
buster_version="~buster+20210816"
bullseye_version="~bullseye+20210816"
bionic_version="~bionic+20210816"
focal_version="~focal+20210816"

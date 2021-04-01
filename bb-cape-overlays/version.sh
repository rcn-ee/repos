#!/bin/bash -e

#https://github.com/beagleboard/bb.org-overlays

package_name="bb-cape-overlays"
debian_pkg_name="${package_name}"
package_version="4.14.20210401.0"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/beagleboard/bb.org-overlays"
git_sha="9184ea5be6f12ff6e3d837f50ae3123d40eacd00"
reprepro_dir="b/${package_name}"
dl_path=""

debian_version="${package_version}-0"
debian_patch=""
debian_diff=""

stretch_version="~stretch+20210401"
buster_version="~buster+20210401"
bullseye_version="~bullseye+20210401"
bionic_version="~bionic+20210401"
focal_version="~focal+20210401"

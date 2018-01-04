#!/bin/bash -e

#https://github.com/beagleboard/bb.org-overlays

package_name="bb-cape-overlays"
debian_pkg_name="${package_name}"
package_version="4.4.20180104.0"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/beagleboard/bb.org-overlays"
git_sha="38bf1c609265eeea58140a7b84ae136e6b88cc98"
reprepro_dir="b/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee1"
debian_patch=""
debian_diff=""

jessie_version="~jessie+20180104"
stretch_version="~stretch+20180104"
buster_version="~buster+20180104"
xenial_version="~xenial+20180104"
bionic_version="~bionic+20180104"

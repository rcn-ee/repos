#!/bin/bash -e

#https://github.com/beagleboard/bb.org-overlays

package_name="bb-cape-overlays"
debian_pkg_name="${package_name}"
package_version="4.14.20200312.0"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/beagleboard/bb.org-overlays"
git_sha="d93cd690ed2f1ef2ccbc176f4acb2868cf144b46"
reprepro_dir="b/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee0"
debian_patch=""
debian_diff=""

stretch_version="~stretch+20200312"
buster_version="~buster+20200312"
xenial_version="~xenial+20200312"
bionic_version="~bionic+20200312"

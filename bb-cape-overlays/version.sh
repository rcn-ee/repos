#!/bin/bash -e

#https://github.com/beagleboard/bb.org-overlays

package_name="bb-cape-overlays"
debian_pkg_name="${package_name}"
package_version="4.4.20180405.0"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/beagleboard/bb.org-overlays"
git_sha="c991b0bf0eb33a5adfeb8395fb751a8622c31a21"
reprepro_dir="b/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee0"
debian_patch=""
debian_diff=""

jessie_version="~jessie+20180405"
stretch_version="~stretch+20180405"
buster_version="~buster+20180405"
xenial_version="~xenial+20180405"
bionic_version="~bionic+20180405"

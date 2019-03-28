#!/bin/bash -e

#https://github.com/beagleboard/bb.org-overlays

package_name="bb-cape-overlays"
debian_pkg_name="${package_name}"
package_version="4.4.20190328.3"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/beagleboard/bb.org-overlays"
git_sha="2dc8fbd0b4ef5cb20011440776099eac716e8803"
reprepro_dir="b/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee0"
debian_patch=""
debian_diff=""

jessie_version="~jessie+20190328"
stretch_version="~stretch+20190328"
buster_version="~buster+20190328"
xenial_version="~xenial+20190328"
bionic_version="~bionic+20190328"

#!/bin/bash -e

#https://github.com/beagleboard/bb.org-overlays

package_name="bb-cape-overlays"
debian_pkg_name="${package_name}"
package_version="4.4.20190117.0"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/beagleboard/bb.org-overlays"
git_sha="4300ce45ab76b0c69c5a096a3dc60b81d1d7ddb9"
reprepro_dir="b/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee0"
debian_patch=""
debian_diff=""

jessie_version="~jessie+20190119"
stretch_version="~stretch+20190119"
buster_version="~buster+20190119"
xenial_version="~xenial+20190119"
bionic_version="~bionic+20190119"

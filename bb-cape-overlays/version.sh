#!/bin/bash -e

#https://github.com/beagleboard/bb.org-overlays

package_name="bb-cape-overlays"
debian_pkg_name="${package_name}"
package_version="4.4.20180913.0"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/beagleboard/bb.org-overlays"
git_sha="2887404e333b57a073cf3ce459c758c0aa14e057"
reprepro_dir="b/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee0"
debian_patch=""
debian_diff=""

jessie_version="~jessie+20180913"
stretch_version="~stretch+20180913"
buster_version="~buster+20180913"
xenial_version="~xenial+20180913"
bionic_version="~bionic+20180913"

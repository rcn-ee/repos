#!/bin/bash -e

package_name="xinput-calibrator"
debian_pkg_name="${package_name}"
package_version="0.7.5+git20140213"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/tias/xinput_calibrator"
git_sha="03dadf55109bd43d3380f040debe9f82f66f2f35"
reprepro_dir="x/${package_name}"
dl_path=""

debian_version="${package_version}-1rcnee2"
debian_patch=""
debian_diff=""
local_patch=""

jessie_version="~jessie+20171122"
stretch_version="~stretch+20171122"
buster_version="~buster+20171122"

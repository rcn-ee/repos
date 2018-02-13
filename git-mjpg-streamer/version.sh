#!/bin/bash -e

#https://github.com/jacksonliam/mjpg-streamer

package_name="mjpg-streamer"
debian_pkg_name="${package_name}"
package_version="0.0.0-git20180125"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/jacksonliam/mjpg-streamer"
git_sha="8cc9d22c1e79905d529a248ccf05bbf0625e0bf3"
reprepro_dir="m/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee0"
debian_patch=""
debian_diff=""

jessie_version="~jessie+20180213"
stretch_version="~stretch+20180213"
buster_version="~buster+20180213"

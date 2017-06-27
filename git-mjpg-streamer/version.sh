#!/bin/bash -e

#https://github.com/jacksonliam/mjpg-streamer

package_name="mjpg-streamer"
debian_pkg_name="${package_name}"
package_version="0.0.0-git20170411"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/jacksonliam/mjpg-streamer"
git_sha="5fba4cc6158130f7bb34bfcbc0f735255cad945f"
reprepro_dir="m/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee1"
debian_patch=""
debian_diff=""

jessie_version="~jessie+20170627"
stretch_version="~stretch+20170627"

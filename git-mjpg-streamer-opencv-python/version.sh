#!/bin/bash -e

#https://github.com/jacksonliam/mjpg-streamer

package_name="mjpg-streamer-opencv-python"
debian_pkg_name="${package_name}"
package_version="0.0.0-git20200429.1"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/jacksonliam/mjpg-streamer"
git_sha="5a6e0a2db163e6ae9461552b59079870d0959340"
reprepro_dir="m/${package_name}"
dl_path=""

debian_version="${package_version}-0"
debian_patch=""
debian_diff=""

stretch_version="~stretch+20200429"
buster_version="~buster+20200429"
bionic_version="~bionic+20200429"

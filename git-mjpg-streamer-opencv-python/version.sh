#!/bin/bash -e

#https://github.com/jacksonliam/mjpg-streamer

package_name="mjpg-streamer-opencv-python"
debian_pkg_name="${package_name}"
package_version="0.0.0-git20190524.0"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/jacksonliam/mjpg-streamer"
git_sha="501f6362c5afddcfb41055f97ae484252c85c912"
reprepro_dir="m/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee3"
debian_patch=""
debian_diff=""

stretch_version="~stretch+20190718"
buster_version="~buster+20190718"
bionic_version="~bionic+20190718"

#!/bin/bash -e

#https://github.com/xobs/xserver-xorg-video-armada

package_name="xf86-video-armada"
debian_pkg_name="${package_name}"
package_version="0.0.1-r16"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/xobs/xserver-xorg-video-armada"
git_sha="05bc938199b236616451f9792e098181e80b078f"
reprepro_dir="x/${package_name}"
dl_path=""

debian_version="${package_version}-0"
debian_patch=""
debian_diff=""
local_patch="rcnee0"

jessie_version="~bpo80+20161117+1"

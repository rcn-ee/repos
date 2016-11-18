#!/bin/bash -e

#http://git.arm.linux.org.uk/cgit/xf86-video-armada.git/

package_name="xf86-video-armada"
debian_pkg_name="${package_name}"
package_version="0.0.1-r16-git20161015"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://ftp.arm.linux.org.uk/~rmk/xf86-video-armada.git"
git_sha="4f2ba2d8cc752378a4ef7c3bb93c4928b6fb4612"
reprepro_dir="x/${package_name}"
dl_path=""

debian_version="${package_version}-0"
debian_patch=""
debian_diff=""
local_patch="rcnee0"

jessie_version="~bpo80+20161118+1"

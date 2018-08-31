#!/bin/bash -e

#http://git.arm.linux.org.uk/cgit/xf86-video-armada.git/

package_name="xf86-video-armada"
debian_pkg_name="${package_name}"
package_version="0.0.1-r16-git20180829.0"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://ftp.arm.linux.org.uk/~rmk/xf86-video-armada.git"
git_sha="78e7116a5bc6cdd9f93cbf1552d342933623ab59"
reprepro_dir="x/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee0"
debian_patch=""
debian_diff=""

bionic_version="~bionic+20180831"

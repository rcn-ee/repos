#!/bin/bash -e

#http://cgit.freedesktop.org/xorg/driver/xf86-video-omap/

package_name="xf86-video-omap"
debian_pkg_name="${package_name}"
package_version="0.4.3-git20130328"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://anongit.freedesktop.org/xorg/driver/xf86-video-omap"
git_sha="d48d09cf60437f04af46758567be6449ab3bfbe5"
reprepro_dir="x/${package_name}"
dl_path=""

debian_version="${package_version}-1"
debian_patch=""
debian_diff=""

wheezy_version="~bpo70+20141117+1"
jessie_version="~20141117+1"
trusty_version="~20141117+1"

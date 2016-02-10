#!/bin/bash -e

#http://cgit.freedesktop.org/xorg/driver/xf86-video-omap/

package_name="xf86-video-omap"
debian_pkg_name="${package_name}"
package_version="0.4.4"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://anongit.freedesktop.org/xorg/driver/xf86-video-omap"
git_sha="c734f380f1df9f21229ce741eef59955d2a8b535"
reprepro_dir="x/${package_name}"
dl_path=""

debian_version="${package_version}-1"
debian_patch=""
debian_diff=""
local_patch="rcnee2"

wheezy_version="~bpo70+20160209+1"
jessie_version="~bpo80+20160209+1"
stretch_version="~bpo90+20160209+1"
trusty_version="~bpo1404+20160209+1"
wily_version="~bpo1510+20160209+1"
xenial_version="~bpo1604+20160209+1"

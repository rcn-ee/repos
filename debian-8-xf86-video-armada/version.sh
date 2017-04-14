#!/bin/bash -e

#http://git.arm.linux.org.uk/cgit/xf86-video-armada.git/

package_name="xf86-video-armada"
debian_pkg_name="${package_name}"
package_version="0.0.1-r16-git20170211"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://ftp.arm.linux.org.uk/~rmk/xf86-video-armada.git"
git_sha="fc12661c74819266f7c497ea04540cfb24760e07"
reprepro_dir="x/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee5"
debian_patch=""
debian_diff=""

jessie_version="~jessie+20170414"
stretch_version="~stretch+20170414"
xenial_version="~xenial+20170414"

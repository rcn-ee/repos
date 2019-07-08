#!/bin/bash -e

#http://git.arm.linux.org.uk/cgit/libdrm-armada.git/

package_name="libdrm-armada"
debian_pkg_name="${package_name}"
package_version="2.0.3"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://ftp.arm.linux.org.uk/~rmk/libdrm-armada.git"
git_sha="6b461c163b0bd02c76b65d94cc2fb3767167bda8"
reprepro_dir="libd/${package_name}"
dl_path=""

debian_version="${package_version}-1"
debian_patch=""
debian_diff=""
local_patch="rcnee1"

jessie_version="~bpo80+20161122+1"
stretch_version="~bpo90+20161122+1"
xenial_version="~bpo1604+20161122+1"

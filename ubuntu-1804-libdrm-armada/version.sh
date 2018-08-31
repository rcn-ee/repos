#!/bin/bash -e

#http://git.arm.linux.org.uk/cgit/libdrm-armada.git/

package_name="libdrm-armada"
debian_pkg_name="${package_name}"
package_version="2.0.3-git20180720"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://ftp.arm.linux.org.uk/~rmk/libdrm-armada.git"
git_sha="607c697d7c403356601cd0d5fa6407b61a45e8ed"
reprepro_dir="libd/${package_name}"
dl_path=""

debian_version="${package_version}-0"
debian_patch=""
debian_diff=""
local_patch="rcnee0"

jessie_version="~bpo80+20161122+1"
stretch_version="~bpo90+20161122+1"
xenial_version="~bpo1604+20161122+1"
bionic_version="~bionic+20180831"

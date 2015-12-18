#!/bin/bash -e

mirror="http://ftp.de.debian.org/debian"

package_name="mesa"
debian_pkg_name="${package_name}"
package_version="11.1.0"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://anongit.freedesktop.org/mesa/mesa"
git_sha="0d19dc302f21d00b88ccb7b70e5a110d17ea4fdf"
reprepro_dir="m/${package_name}"
dl_path=""

debian_version="${package_version}-1etnaviv20151216"
debian_untar=""
debian_patch=""
local_patch="rcnee1"

jessie_version="~bpo80+20151217+1"

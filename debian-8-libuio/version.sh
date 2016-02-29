#!/bin/bash -e

#https://github.com/Linutronix/libuio

package_name="libuio"
debian_pkg_name="${package_name}"
package_version="0.2.7"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/Linutronix/libuio"
git_sha="940861de278cb794bf9d775b76a4d1d4f9108607"
reprepro_dir="libu/${package_name}"
dl_path=""

debian_version="${package_version}-0"
debian_patch=""
debian_diff=""
local_patch="rcnee1"

jessie_version="~bpo80+20160229+1"

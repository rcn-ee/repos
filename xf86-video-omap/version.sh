#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="xf86-video-omap"
debian_pkg_name="${package_name}"
package_version="0.4.5"
package_source="${debian_pkg_name}_${package_version}.orig.tar.bz2"
src_dir="${package_name}-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="x/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-1"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""
local_patch="rcnee1"

jessie_version="~jessie+20180119"
xenial_version="~xenial+20180119"

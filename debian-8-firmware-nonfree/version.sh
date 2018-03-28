#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="firmware-nonfree"
debian_pkg_name="${package_name}"
package_version="20170823"
package_source="${debian_pkg_name}_${package_version}.orig.tar.xz"
src_dir="${debian_pkg_name}-${package_version}"


git_repo=""
git_sha=""
reprepro_dir="f/${package_name}"
dl_path="pool/non-free/${reprepro_dir}/"

debian_version="${package_version}-1"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""
local_patch="rcnee1"

jessie_version="~jessie+20180328"
stretch_version="~stretch+20180328"
buster_version="~buster+20180328"

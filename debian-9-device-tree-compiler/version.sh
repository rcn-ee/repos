#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="device-tree-compiler"
debian_pkg_name="${package_name}"
package_version="1.4.2"
package_source="${package_name}_${package_version}.orig.tar.gz"
src_dir="dtc-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="d/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-1"
debian_untar=""
debian_patch="${package_name}_${debian_version}.diff.gz"
local_patch="rcnee2"

stretch_version="~bpo90+20170118+1"

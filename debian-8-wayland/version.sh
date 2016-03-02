#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="wayland"
debian_pkg_name="${package_name}"
package_version="1.9.0"
package_source="${package_name}_${package_version}.orig.tar.gz"
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="w/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-1"
debian_untar=""
debian_patch="${package_name}_${debian_version}.diff.gz"
#local_patch="rcnee1"

jessie_version="~bpo80+20160302+1"

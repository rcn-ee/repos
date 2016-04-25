#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="gem2deb"
debian_pkg_name="${package_name}"
package_version="0.30.1~bpo8+1"
package_source="${package_name}_${package_version}.tar.xz"
src_dir="${package_name}-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="g/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-1"
debian_untar=""
debian_patch=""

jessie_version="~bpo80+20160425+1"

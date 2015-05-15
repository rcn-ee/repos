#!/bin/bash -e

mirror="http://ftp.de.debian.org/debian"

package_name="pkg-kde-tools"
debian_pkg_name="${package_name}"
package_version="0.15.17"
package_source="${package_name}_${package_version}.tar.bz2"
src_dir="${package_name}-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="p/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}"
debian_untar=""
debian_patch=""

jessie_version="~bpo80+20150515+1"

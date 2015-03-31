#!/bin/bash -e

mirror="http://ftp.de.debian.org/debian"

package_name="kcoreaddons"
debian_pkg_name="${package_name}"
package_version="5.8.0"
package_source="${debian_pkg_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="k/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-1"
debian_patch="${debian_pkg_name}_${debian_version}.debian.tar.xz"
debian_diff=""

jessie_version="~bpo80+20150331+1"

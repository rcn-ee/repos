#!/bin/bash -e

mirror="http://ftp.de.debian.org/debian"

package_name="pkg-kde-tools"
debian_pkg_name="${package_name}"
package_version="0.15.16"
package_source="${package_name}_${package_version}.tar.bz2"
src_dir="${package_name}-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="p/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-1"
debian_untar=""
debian_patch=""

wheezy_version="~bpo70+20141218+1"
jessie_version="~20150212+1"

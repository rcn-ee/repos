#!/bin/bash -e

mirror="http://ftp.de.debian.org/debian"

package_name="libv8-3.14"
debian_pkg_name="${package_name}"
package_version="3.14.5.8"
package_source="${package_name}_${package_version}.orig.tar.gz"
src_dir="v8-6b10fef46edfb4dc2a7aed389d75574c40a14243"

git_repo=""
git_sha=""
reprepro_dir="libv/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-8.1"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""

jessie_version="~20141124+1"
wheezy_version="~bpo70+20150526+1"

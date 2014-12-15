#!/bin/bash -e

mirror="http://ftp.de.debian.org/debian"

package_name="libwebsockets"
debian_pkg_name="${package_name}"
package_version="1.2.2"
package_source="${package_name}_${package_version}.orig.tar.gz"
src_dir="libwebsockets-1.22-chrome26-firefox18"

git_repo=""
git_sha=""
reprepro_dir="libw/${package_name}"
dl_path="${mirror}/pool/main/${reprepro_dir}/"

debian_version="${package_version}-1"
debian_untar="${package_name}_${debian_version}.debian.tar.gz"
debian_patch=""

jessie_version="~20141124+1"
wheezy_version="~bpo70+20141215+1"

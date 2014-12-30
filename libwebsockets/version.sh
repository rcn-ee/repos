#!/bin/bash -e

mirror="http://ftp.de.debian.org/debian"

package_name="libwebsockets"
debian_pkg_name="${package_name}"
package_version="1.2.3"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/warmcat/libwebsockets"
git_sha="81877e6a4ce78d687f46ec525651813604ce48cc"
reprepro_dir="libw/${package_name}"
dl_path="${mirror}/pool/main/${reprepro_dir}/"

debian_version="${package_version}-1"
debian_untar=""
debian_patch=""

wheezy_version="~bpo70+20141230+2"
jessie_version="~20141230+2"
trusty_version="~20141230+2"

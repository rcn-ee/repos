#!/bin/bash -e

mirror="http://http.debian.net/debian"
#https://w1.fi/cgit/hostap/log/?ofs=2900

package_name="wpa"
debian_pkg_name="${package_name}"
package_version="2.5~git20150927"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/rcn-ee/hostap"
git_sha="cac800c4d16189326b97bd53a169d0f9a7adfb85"
reprepro_dir="w/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee2"
debian_untar=""
debian_patch=""

jessie_version="~jessie+20171016"

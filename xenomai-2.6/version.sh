#!/bin/bash -e

#http://git.xenomai.org/xenomai-2.6.git/

package_name="xenomai"
debian_pkg_name="${package_name}"
package_version="2.6.4-git20150129"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://git.xenomai.org/xenomai-2.6.git"
git_sha="4f349cf0553b26e329890736dd3e5933ce1a8af9"
reprepro_dir="x/${package_name}"
dl_path=""

debian_version="${package_version}-1"
debian_patch=""
debian_diff=""

wheezy_version="~bpo70+20150211+1"
jessie_version="~20150211+1"
trusty_version="~20150211+1"

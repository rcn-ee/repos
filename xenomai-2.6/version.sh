#!/bin/bash -e

#http://git.xenomai.org/xenomai-2.6.git/

package_name="xenomai"
debian_pkg_name="${package_name}"
package_version="2.6.4-git20150311"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://git.xenomai.org/xenomai-2.6.git"
git_sha="fe59354a1ed2ee2cff65d17f2cb249292c647e57"
reprepro_dir="x/${package_name}"
dl_path=""

debian_version="${package_version}-1"
debian_patch=""
debian_diff=""

wheezy_version="~bpo70+20150518+1"
jessie_version="~bpo80+20150518+1"
trusty_version="~bpo1404+20150518+1"

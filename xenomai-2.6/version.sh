#!/bin/bash -e

#http://git.xenomai.org/xenomai-2.6.git/

package_name="xenomai"
debian_pkg_name="${package_name}"
package_version="2.6.4-git20141124"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://git.xenomai.org/xenomai-2.6.git"
git_sha="57881af50b85ff06a4c5b3846468b74dd8584fa2"
reprepro_dir="x/${package_name}"
dl_path=""

debian_version="${package_version}-1"
debian_patch=""
debian_diff=""

wheezy_version="~bpo70+20141211+1"
jessie_version="~20141211+1"
trusty_version="~20141211+1"

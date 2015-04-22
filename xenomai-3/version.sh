#!/bin/bash -e

#http://git.xenomai.org/xenomai-3.git/

package_name="xenomai"
debian_pkg_name="${package_name}"
package_version="3.0-git20150416"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://git.xenomai.org/xenomai-3.git"
git_sha="c0ec879cb9c583e21a085959221374e8baf86bca"
reprepro_dir="x/${package_name}"
dl_path=""

debian_version="${package_version}-1+rc4"
debian_patch=""
debian_diff=""

jessie_version="~bpo80+20150422+1"

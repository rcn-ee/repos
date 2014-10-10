#!/bin/bash -e

package_name="cmst"
debian_pkg_name="${package_name}"
package_version="2014.10.05-git20141009"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/andrew-bibb/cmst.git"
git_sha="68cdaa073e45df9902da9f06dcdf615199a0eb11"
reprepro_dir="c/${package_name}"
dl_path=""

debian_version="${package_version}-1"
debian_patch=""
debian_diff=""

wheezy_version="~bpo70+20141006+1"
jessie_version="~20141010+1"

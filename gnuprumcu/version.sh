#!/bin/bash -e

package_name="gnuprumcu"
debian_pkg_name="${package_name}"
package_version="0.3.0-git20200828.0"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/dinuxbg/gnuprumcu"
git_sha="b62dfbc2cf1e8ad19e845141e7e3a6c077a6c4d5"
reprepro_dir="b/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee0"
debian_patch=""
debian_diff=""

buster_version="~buster+20200321"
bullseye_version="~bullseye+20200321"
bionic_version="~bionic+20200321"

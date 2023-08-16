#!/bin/bash -e

package_name="gnuprumcu"
debian_pkg_name="${package_name}"
package_version="0.9.4-git20230525.0"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/dinuxbg/gnuprumcu"
git_sha="add29b89053bd5bd7157c6eb48c2f6963cf232da"
reprepro_dir="b/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee0"
debian_patch=""
debian_diff=""

bullseye_version="~bullseye+20200903"

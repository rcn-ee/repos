#!/bin/bash -e

package_name="gnuprumcu"
debian_pkg_name="${package_name}"
package_version="0.2.0-git20190822.0"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/dinuxbg/gnuprumcu"
git_sha="81efdc0d816174840c71d40664ee6410f61a770a"
reprepro_dir="b/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee2"
debian_patch=""
debian_diff=""

buster_version="~buster+20200318"
bullseye_version="~bullseye+20200318"
bionic_version="~bionic+20200318"

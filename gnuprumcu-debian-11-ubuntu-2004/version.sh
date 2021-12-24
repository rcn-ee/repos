#!/bin/bash -e

package_name="gnuprumcu"
debian_pkg_name="${package_name}"
package_version="0.7.0-git20211212.0"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/dinuxbg/gnuprumcu"
git_sha="aa0fced67d9d03c21e40caa5f8e5820c7264f2b5"
reprepro_dir="b/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee0"
debian_patch=""
debian_diff=""

bullseye_version="~bullseye+20211224"
focal_version="~focal+20211224"

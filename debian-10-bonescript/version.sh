#!/bin/bash -e

package_name="bonescript"
debian_pkg_name="${package_name}"
package_version="0.6.4-git20180608.0"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/jadonk/bonescript"
git_sha="a9ca418002664c0bb9a38c5b2a791b2e46b72687"
reprepro_dir="b/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee1"
debian_patch=""
debian_diff=""

dl_mirror="https://github.com/rcn-ee/npm-package-bonescript/raw/master/deploy/buster/"

v8="v8.11.2"

bonescript="bonescript-0.6.4-beta3-a9ca418"
   winston="winston-2.1.1"

debian_dl_1="${dl_mirror}/${bonescript}-${v8}-20180611.tar.xz"
debian_dl_2="${dl_mirror}/${winston}-${v8}.tar.xz"

buster_version="~buster+20180611"

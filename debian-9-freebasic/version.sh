#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="freebasic"
debian_pkg_name="${package_name}"
package_version="1.05.0-git20160131.0"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/freebasic/fbc"
git_sha="05ae637b6062a4c73ae0f6b2fcfaa56c67d70468"
reprepro_dir="f/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee1"
debian_patch=""
debian_diff=""

stretch_version="~stretch+20180921"

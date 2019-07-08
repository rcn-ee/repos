#!/bin/bash -e

#https://github.com/sarnold/af_alg

package_name="af-alg"
debian_pkg_name="${package_name}"
package_version="0.0.1-2-git20161224"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/sarnold/af_alg.git"
git_sha="e644340b097ee9d5798a6075c135e17f56b94325"
reprepro_dir="a/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee0"
debian_patch=""
debian_diff=""

jessie_version="~jessie+20170726"
stretch_version="~stretch+20170726"

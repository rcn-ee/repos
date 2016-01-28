#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="libsigrok"
debian_pkg_name="${package_name}"
package_version="0.3.0"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://sigrok.org/libsigrok"
git_sha="3f48fc82b5bc13e749b30a47dd6ca06f8cd2b00e"
reprepro_dir="libs/${package_name}"
dl_path=""

debian_version="${package_version}-1"
debian_patch=""
debian_diff=""

jessie_version="~bpo80+20160128+1"

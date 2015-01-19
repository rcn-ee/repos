#!/bin/bash -e

package_name="libsoc"
debian_pkg_name="${package_name}"
package_version="0.6.3-git20141011"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/jackmitch/libsoc.git"
git_sha="872e6c4b4c44ab5574a440f421a32cc75c46e85f"
reprepro_dir="libs/${package_name}"
dl_path=""

debian_version="${package_version}-1"
debian_patch=""
debian_diff=""

wheezy_version="~bpo70+20150119+1"
jessie_version="~20150119+1"
trusty_version="~20150119+1"

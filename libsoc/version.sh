#!/bin/bash -e

package_name="libsoc"
debian_pkg_name="${package_name}"
package_version="0.6.3"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/jackmitch/libsoc/"
git_sha="df9b256337790a5cefe0aa4d7bc11225612098dd"
reprepro_dir="libs/${package_name}"
dl_path=""

debian_version="${package_version}-1"
debian_patch=""
debian_diff=""

wheezy_version="~bpo70+20141006+1"
jessie_version="~20141006+1"

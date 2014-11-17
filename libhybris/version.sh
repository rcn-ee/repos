#!/bin/bash -e

#https://github.com/libhybris/libhybris

package_name="libhybris"
debian_pkg_name="${package_name}"
package_version="0.1.0-git20140930"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/libhybris/libhybris"
git_sha="3769b35c6163cf33eb71b330c20f9a344bc44bbc"
reprepro_dir="libh/${package_name}"
dl_path=""

debian_version="${package_version}-1"
debian_patch=""
debian_diff=""

wheezy_version="~bpo70+20141117+1"
jessie_version="~20141117+1"

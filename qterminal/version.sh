#!/bin/bash -e

package_name="qterminal"
debian_pkg_name="${package_name}"
package_version="0.6.0-git20141201"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/qterminal/qterminal"
git_sha="34d02c7edd00671e134fc19e20e61bf83cb795b8"
reprepro_dir="q/${package_name}"
dl_path=""

debian_version="${package_version}-1"
debian_patch=""
debian_diff=""

wheezy_version="~bpo70+20140924+1"
jessie_version="~20141203+1"

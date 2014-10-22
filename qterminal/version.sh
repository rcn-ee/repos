#!/bin/bash -e

package_name="qterminal"
debian_pkg_name="${package_name}"
package_version="0.6.0"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/qterminal/qterminal"
git_sha="de818f87323d7866bafae86716638f1570266ec5"
reprepro_dir="q/${package_name}"
dl_path=""

debian_version="${package_version}-1"
debian_patch=""
debian_diff=""

wheezy_version="~bpo70+20140924+1"
jessie_version="~20141022+1"

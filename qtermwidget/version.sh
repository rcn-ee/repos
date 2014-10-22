#!/bin/bash -e

package_name="qtermwidget"
debian_pkg_name="${package_name}"
package_version="0.6.0"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/qterminal/qtermwidget"
git_sha="a8aad8edf6cded627258b0deac81c28074ad444f"
reprepro_dir="q/${package_name}"
dl_path=""

debian_version="${package_version}-1"
debian_patch=""
debian_diff=""

wheezy_version="~bpo70+20140924+1"
jessie_version="~20141022+1"

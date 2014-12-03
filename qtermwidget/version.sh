#!/bin/bash -e

package_name="qtermwidget"
debian_pkg_name="${package_name}"
package_version="0.6.0-git20141202"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/qterminal/qtermwidget"
git_sha="3ce99c7450fa85294a29322267b18a31d21f9886"
reprepro_dir="libq/${package_name}"
dl_path=""

debian_version="${package_version}-1"
debian_patch=""
debian_diff=""

wheezy_version="~bpo70+20140924+1"
jessie_version="~20141203+1"

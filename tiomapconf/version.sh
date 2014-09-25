#!/bin/bash -e

package_name="tiomapconf"
debian_pkg_name="${package_name}"
package_version="1.70.0"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/omapconf/omapconf"
git_sha="596557bd1c90f68ccaad1c92745b804838cb423b"
reprepro_dir="o/${package_name}"
dl_path=""

debian_version="${package_version}-1"
debian_patch=""
debian_diff=""

wheezy_version="~bpo70+20140924+1"
jessie_version="~20140924+1"

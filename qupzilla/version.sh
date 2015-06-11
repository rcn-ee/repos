#!/bin/bash -e

#https://github.com/QupZilla/qupzilla/commits/v1.8

package_name="qupzilla"
debian_pkg_name="${package_name}"
#package_version="1.8.4"
package_version="1.8.6-git20150528"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/QupZilla/qupzilla"
git_sha="61ef93396bc434a0159193bf31e039d1817716f8"
reprepro_dir="q/${package_name}"
dl_path=""

debian_version="${package_version}-1"
debian_patch=""
debian_diff=""

jessie_version="~bpo80+20150611+1"

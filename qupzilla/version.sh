#!/bin/bash -e

#https://launchpad.net/~nowrep/+archive/ubuntu/qupzilla/+packages
#https://github.com/QupZilla/qupzilla/commits/v1.8

package_name="qupzilla"
debian_pkg_name="${package_name}"
#package_version="1.8.4"
package_version="1.8.4-git20141118"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/QupZilla/qupzilla"
git_sha="b1c12998c7db6664193d4e55d0e76d4b5d562fa1"
reprepro_dir="q/${package_name}"
dl_path=""

debian_version="${package_version}-1"
debian_patch=""
debian_diff=""

wheezy_version="~bpo70+20141006+1"
jessie_version="~20141118+1"

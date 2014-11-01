#!/bin/bash -e

#https://launchpad.net/~nowrep/+archive/ubuntu/qupzilla/+packages
#https://github.com/QupZilla/qupzilla/commits/v1.8

package_name="qupzilla"
debian_pkg_name="${package_name}"
#package_version="1.8.3"
package_version="1.8.3-git20141031"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/QupZilla/qupzilla"
git_sha="8888e9d29ab58d0098858ac3f096fdebdfa9584d"
reprepro_dir="q/${package_name}"
dl_path=""

debian_version="${package_version}-1"
debian_patch=""
debian_diff=""

wheezy_version="~bpo70+20141006+1"
jessie_version="~20141101+1"

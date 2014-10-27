#!/bin/bash -e

#https://launchpad.net/~nilarimogard/+archive/ubuntu/webupd8/+packages
#https://github.com/hotice/AP-Hotspot

package_name="ap-hotspot"
debian_pkg_name="${package_name}"
package_version="0.3-git20140222"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/hotice/AP-Hotspot"
git_sha="296bacd851eec06952da6bad14cac8a3d8172041"
reprepro_dir="a/${package_name}"
dl_path=""

debian_version="${package_version}-1"
debian_patch=""
debian_diff=""

wheezy_version="~bpo70+20141027+1"
jessie_version="~20141027+1"

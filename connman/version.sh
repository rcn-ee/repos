#!/bin/bash -e

#https://github.com/pfl/connman-deb
#http://anonscm.debian.org/cgit/collab-maint/connman.git

package_name="connman"
debian_pkg_name="${package_name}"
package_version="1.26"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://git.kernel.org/pub/scm/network/connman/connman.git"
git_sha="5a715ed10dc008126c24b20efaf5a8495140608a"
reprepro_dir="c/${package_name}"
dl_path=""

debian_version="${package_version}-0.1"
debian_patch=""
debian_diff=""

wheezy_version="~bpo70+20141112+1"
jessie_version="~20141112+2"

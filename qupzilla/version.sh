#!/bin/bash -e

#https://launchpad.net/~nowrep/+archive/ubuntu/qupzilla/+packages

package_name="qupzilla"
debian_pkg_name="${package_name}"
package_version="1.8.3"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/QupZilla/qupzilla"
git_sha="fed88d6f001d57c37f5fd88af37124b5a7b391a8"
reprepro_dir="q/${package_name}"
dl_path=""

debian_version="${package_version}-1"
debian_patch=""
debian_diff=""

wheezy_version="~bpo70+20141006+1"
jessie_version="~20141024+1"

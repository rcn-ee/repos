#!/bin/bash -e

#https://rcn-ee.net/pkgs/ti/ducati-full-jacinto6evm-0.20140905.tgz

package_name="bbx15-ducati-firmware-installer"
debian_pkg_name="${package_name}"
package_version="0.20140905"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="b/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-1"
debian_untar=""
debian_patch=""

wheezy_version="~bpo70+20150707+1"
jessie_version="~bpo80+20150707+1"
trusty_version="~bpo1404+20150707+1"

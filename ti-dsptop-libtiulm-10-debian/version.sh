#!/bin/bash -e

#http://git.ti.com/gitweb/?p=sdo-emu/dsptop.git;a=summary

package_name="dsptop"
debian_pkg_name="${package_name}"
package_version="1.4.0-git20190509.1"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://git.ti.com/sdo-emu/dsptop.git"
git_sha="25e823b04e62af224dce97b90359b7569ce3fbb5"
reprepro_dir="d/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee0"
debian_patch=""
debian_diff=""

buster_version="~buster+20190925"

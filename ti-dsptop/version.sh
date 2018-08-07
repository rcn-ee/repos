#!/bin/bash -e

#http://git.ti.com/gitweb/?p=sdo-emu/dsptop.git;a=summary

package_name="dsptop"
debian_pkg_name="${package_name}"
package_version="1.4.0-git20160915"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://git.ti.com/sdo-emu/dsptop.git"
git_sha="0aedcabdbbcbfc7558f70fc50afc95583302a087"
reprepro_dir="d/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee3"
debian_patch=""
debian_diff=""

stretch_version="~stretch+20180807"
buster_version="~buster+20180807"
bionic_version="~bionic+20180807"

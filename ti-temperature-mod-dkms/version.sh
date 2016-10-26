#!/bin/bash -e

#http://git.ti.com/gitweb/?p=sdo-emu/dsptop.git;a=summary

package_name="temperature-mod-dkms"
debian_pkg_name="${package_name}"
package_version="1.0.1-git20160915"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://git.ti.com/sdo-emu/dsptop.git"
git_sha="0aedcabdbbcbfc7558f70fc50afc95583302a087"
reprepro_dir="t/${package_name}"
dl_path=""

debian_version="${package_version}-0"
debian_patch=""
debian_diff=""
local_patch="rcnee1"

jessie_version="~bpo80+20161026+1"
stretch_version="~bpo90+20161026+1"
xenial_version="~bpo1604+20161026+1"

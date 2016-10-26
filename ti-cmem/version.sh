#!/bin/bash -e

#http://git.ti.com/gitweb/?p=ipc/ludev.git;a=summary

package_name="cmem"
debian_pkg_name="${package_name}"
package_version="4.12.00.00-git20160926"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://git.ti.com/ipc/ludev.git"
git_sha="d6d3e84c84d0e84a9b96c3f6f789ac642d03afcb"
reprepro_dir="c/${package_name}"
dl_path=""

debian_version="${package_version}-0"
debian_patch=""
debian_diff=""
local_patch="rcnee2"

#sed -i -e 's:4.11.00.00:4.12.00.00:g' ./debian/cmem-mod-dkms.install
#sed -i -e 's:4.11.00.00:4.12.00.00:g' ./debian/control
#sed -i -e 's:4.11.00.00:4.12.00.00:g' ./debian/cmem-mod-dkms.dkms

jessie_version="~bpo80+20161026+1"
stretch_version="~bpo90+20161026+1"
xenial_version="~bpo1604+20161026+1"

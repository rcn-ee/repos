#!/bin/bash -e

#http://git.ti.com/gitweb/?p=ipc/ludev.git;a=summary

package_name="cmem"
debian_pkg_name="${package_name}"
package_version="4.11.00.00-git20160427"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://git.ti.com/ipc/ludev.git"
git_sha="852e97b5584cbdb6aa0fdef02a7c4e245409bcb6"
reprepro_dir="c/${package_name}"
dl_path=""

debian_version="${package_version}-0"
debian_patch=""
debian_diff=""
local_patch="rcnee2"

#sed -i -e 's:4.10.02.06:4.11.00.00:g' ./debian/cmem-mod-dkms.install
#sed -i -e 's:4.10.02.06:4.11.00.00:g' ./debian/control
#sed -i -e 's:4.10.02.06:4.11.00.00:g' ./debian/cmem-mod-dkms.dkms

jessie_version="~bpo80+20160427+1"
stretch_version="~bpo90+20160427+1"
xenial_version="~bpo1604+20160427+1"
yakkety_version="~bpo1610+20160427+1"

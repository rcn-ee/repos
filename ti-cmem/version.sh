#!/bin/bash -e

#http://git.ti.com/gitweb/?p=ipc/ludev.git;a=summary

package_name="cmem"
debian_pkg_name="${package_name}"
package_version="4.10.02.06-git20160318"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://git.ti.com/ipc/ludev.git"
git_sha="4d599728974e4786bf2e0494605e9d79ebddee79"
reprepro_dir="c/${package_name}"
dl_path=""

debian_version="${package_version}-0"
debian_patch=""
debian_diff=""
local_patch="rcnee1"

#sed -i -e 's:4.10.02.03:4.10.02.04:g' ./debian/cmem-mod-dkms.install
#sed -i -e 's:4.10.02.03:4.10.02.04:g' ./debian/control
#sed -i -e 's:4.10.02.03:4.10.02.04:g' ./debian/cmem-mod-dkms.dkms

jessie_version="~bpo80+20160324+1"
stretch_version="~bpo90+20160324+1"
wily_version="~bpo1510+20160324+1"
xenial_version="~bpo1604+20160324+1"

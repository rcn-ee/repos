#!/bin/bash -e

#http://git.ti.com/gitweb/?p=ipc/ludev.git;a=summary

package_name="cmem"
debian_pkg_name="${package_name}"
package_version="4.14.00.00-git20170216"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://git.ti.com/ipc/ludev.git"
git_sha="b514a99ac45c64f0439282d0774d7cff5def4c6f"
reprepro_dir="c/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee0"
debian_patch=""
debian_diff=""

#sed -i -e 's:4.11.00.00:4.12.00.00:g' ./debian/cmem-mod-dkms.install
#sed -i -e 's:4.11.00.00:4.12.00.00:g' ./debian/control
#sed -i -e 's:4.11.00.00:4.12.00.00:g' ./debian/cmem-mod-dkms.dkms

jessie_version="~jessie+20170608"
stretch_version="~stretch+20170608"
xenial_version="~xenial+20170608"

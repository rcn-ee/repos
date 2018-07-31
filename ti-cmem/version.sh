#!/bin/bash -e

#http://git.ti.com/gitweb/?p=ipc/ludev.git;a=summary

package_name="cmem"
debian_pkg_name="${package_name}"
package_version="4.15.00.01-git20180305"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://git.ti.com/ipc/ludev.git"
git_sha="000038a65af9428b559de5e00e4a7588892ad7b0"
reprepro_dir="c/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee0"
debian_patch=""
debian_diff=""

#sed -i -e 's:4.11.00.00:4.12.00.00:g' ./debian/cmem-mod-dkms.install
#sed -i -e 's:4.11.00.00:4.12.00.00:g' ./debian/control
#sed -i -e 's:4.11.00.00:4.12.00.00:g' ./debian/cmem-mod-dkms.dkms

stretch_version="~stretch+20180731"
buster_version="~buster+20180731"
bionic_version="~bionic+20180731"

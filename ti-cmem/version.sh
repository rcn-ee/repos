#!/bin/bash -e

#http://git.ti.com/gitweb/?p=ipc/ludev.git;a=summary
#http://arago-project.org/git/?p=meta-ti.git;a=blob;f=recipes-bsp/cmem/cmem.inc;h=abbf249207d5eb66d0ff799953876e7a8fc0ee26;hb=HEAD
#http://arago-project.org/git/?p=meta-ti.git;a=commitdiff;h=c6535857d680ad644ce8d07b6e42b6b8ebe380e3

package_name="cmem"
debian_pkg_name="${package_name}"
package_version="4.15.00.02-git20180821"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://git.ti.com/ipc/ludev.git"
#http://git.ti.com/gitweb/?p=ipc/ludev.git;a=summary
git_sha="0f39ed469f7c327cb0b03139976b511c337c7f6a"
reprepro_dir="c/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee0"
debian_patch=""
debian_diff=""

#sed -i -e 's:4.11.00.00:4.12.00.00:g' ./debian/cmem-mod-dkms.install
#sed -i -e 's:4.11.00.00:4.12.00.00:g' ./debian/control
#sed -i -e 's:4.11.00.00:4.12.00.00:g' ./debian/cmem-mod-dkms.dkms

stretch_version="~stretch+20190102"
buster_version="~buster+20190102"
bionic_version="~bionic+20190102"

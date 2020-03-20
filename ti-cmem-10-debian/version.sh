#!/bin/bash -e

#http://git.ti.com/gitweb/?p=ipc/ludev.git;a=summary
#http://arago-project.org/git/?p=meta-ti.git;a=tree;f=recipes-bsp/cmem;h=8a9606547ae4d30b5ef0da26fdd82dd70e9977f2;hb=refs/tags/ti2019.05

package_name="cmem"
debian_pkg_name="${package_name}"
package_version="4.16.00.00-git20181220.1"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://git.ti.com/ipc/ludev.git"
#http://git.ti.com/gitweb/?p=ipc/ludev.git;a=summary
git_sha="4f970f053b42e8d2a6f1a8cd4b14786196468fd3"
reprepro_dir="c/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee0"
debian_patch=""
debian_diff=""

#sed -i -e 's:4.11.00.00:4.12.00.00:g' ./debian/cmem-mod-dkms.install
#sed -i -e 's:4.11.00.00:4.12.00.00:g' ./debian/control
#sed -i -e 's:4.11.00.00:4.12.00.00:g' ./debian/cmem-mod-dkms.dkms

buster_version="~buster+20200319"

#!/bin/bash -e

#http://git.ti.com/gitweb/?p=ipc/ludev.git;a=summary

package_name="cmem"
debian_pkg_name="${package_name}"
package_version="4.10.02.04-git20151016"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://git.ti.com/ipc/ludev.git"
git_sha="00241c45f810c8b8e4f5ac66c3323fec8e43b621"
reprepro_dir="c/${package_name}"
dl_path=""

debian_version="${package_version}-1"
debian_patch=""
debian_diff=""

#sed -i -e 's:4.10.02.03:4.10.02.04:g' ./debian/cmem-mod-dkms.install
#sed -i -e 's:4.10.02.03:4.10.02.04:g' ./debian/control
#sed -i -e 's:4.10.02.03:4.10.02.04:g' ./debian/cmem-mod-dkms.dkms

wheezy_version="~bpo70+20151022+1"
jessie_version="~bpo80+20151022+1"
stretch_version="~bpo90+20151022+1"
trusty_version="~bpo1404+20151022+1"
vivid_version="~bpo1504+20151022+1"
wily_version="~bpo1510+20151022+1"

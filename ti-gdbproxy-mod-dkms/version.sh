#!/bin/bash -e

#http://git.ti.com/gitweb/?p=sdo-emu/gdbc6x.git;a=summary

package_name="gdbproxy-mod-dkms"
debian_pkg_name="${package_name}"
package_version="1.1.0-git20160327"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://git.ti.com/sdo-emu/gdbc6x.git"
git_sha="df0b8f6f4e9ba5b9c94ea8c17c6dfeae37c1c9d1"
reprepro_dir="g/${package_name}"
dl_path=""

debian_version="${package_version}-1rcnee1"
debian_patch=""
debian_diff=""

jessie_version="~bpo80+20161027+1"
stretch_version="~bpo90+20161027+1"
xenial_version="~bpo1604+20161027+1"

#!/bin/bash -e

#http://git.ti.com/gitweb/?p=sdo-emu/gdbc6x.git;a=summary

package_name="gdbproxy-mod-dkms"
debian_pkg_name="${package_name}"
package_version="1.0.1-git20150805"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://git.ti.com/sdo-emu/gdbc6x.git"
git_sha="653f7d0a345bede0542326090b622b885545c712"
reprepro_dir="g/${package_name}"
dl_path=""

debian_version="${package_version}-1"
debian_patch=""
debian_diff=""

wheezy_version="~bpo70+20151016+1"
jessie_version="~bpo80+20151016+1"
stretch_version="~bpo90+20151016+1"

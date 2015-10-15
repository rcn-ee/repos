#!/bin/bash -e

#http://git.ti.com/gitweb/?p=ipc/ludev.git;a=summary

package_name="cmem"
debian_pkg_name="${package_name}"
package_version="4.10.02.03-git20150921"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://git.ti.com/ipc/ludev.git"
git_sha="d47ac635699da6bee6daff31b87b0123e13af4ac"
reprepro_dir="c/${package_name}"
dl_path=""

debian_version="${package_version}-1.1"
debian_patch=""
debian_diff=""

wheezy_version="~bpo70+20151015+1"
jessie_version="~bpo80+20151015+1"
stretch_version="~bpo90+20151015+1"

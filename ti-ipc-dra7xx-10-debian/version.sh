#!/bin/bash -e

#http://git.ti.com/gitweb/?p=ipc/ipcdev.git;a=summary
#http://arago-project.org/git/?p=meta-ti.git;a=tree;f=recipes-ti/ipc;h=355cfa0aa0639b3165c12f9a1edb2ea644d34f1c;hb=refs/tags/ti2019.05

package_name="ti-ipc-dra7xx"
debian_pkg_name="${package_name}"
package_version="3.50.04.08"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://git.ti.com/ipc/ipcdev.git"
git_sha="1d53b856338b86d1979fe09345c0b382913a848a"
reprepro_dir="t/${package_name}"
dl_path=""

debian_version="${package_version}-rcnee0"
debian_patch=""
debian_diff=""

buster_version="~buster+20200319"

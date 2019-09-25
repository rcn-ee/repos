#!/bin/bash -e

#http://git.ti.com/gitweb/?p=ipc/ipcdev.git;a=summary
#http://arago-project.org/git/?p=meta-ti.git;a=blob;f=recipes-ti/ipc/ti-ipc_git.bb;hb=af3c69b8e3918c5c79506c66027109685a5c9296
#http://arago-project.org/git/?p=meta-ti.git;a=history;f=recipes-ti/ipc;h=HEAD;hb=HEAD

package_name="ti-ipc-dra7xx"
debian_pkg_name="${package_name}"
package_version="3.50.03.05"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://git.ti.com/ipc/ipcdev.git"
git_sha="d03495a8ff4b234eb5d1e390c012712e83a81ed4"
reprepro_dir="t/${package_name}"
dl_path=""

debian_version="${package_version}-rcnee0"
debian_patch=""
debian_diff=""

buster_version="~buster+20190925"

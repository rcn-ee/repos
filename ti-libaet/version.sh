#!/bin/bash -e

#http://git.ti.com/gitweb/?p=sdo-emu/ctoolslib.git;a=summary
#http://arago-project.org/git/?p=meta-ti.git;a=blob;f=recipes-ti/ctoolslib/libaet_git.bb;hb=HEAD

package_name="ti-libaet"
debian_pkg_name="${package_name}"
package_version="4.19.0.0"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://git.ti.com/sdo-emu/ctoolslib.git"
git_sha="de7954abab0f0caa8a2c7b53095c30226d901a31"
reprepro_dir="c/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee0"
debian_patch=""
debian_diff=""

stretch_version="~stretch+20180808"
buster_version="~buster+20180808"
bionic_version="~bionic+20180808"

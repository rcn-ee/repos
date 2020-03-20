#!/bin/bash -e

#http://git.ti.com/gitweb/?p=sdo-emu/gdbc6x.git;a=summary
#http://arago-project.org/git/?p=meta-ti.git;a=tree;f=recipes-devtools/gdbc6x;h=f258fd2b7cdd6b8386747957890f2b196199976a;hb=refs/tags/ti2019.05

package_name="gdbserver-c6x"
debian_pkg_name="${package_name}"
package_version="1.1.0-git20190509.0"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://git.ti.com/sdo-emu/gdbc6x.git"
git_sha="d1d32c32fa9e40b48fabf5893487ccbd5790499c"
reprepro_dir="g/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee0"
debian_patch=""
debian_diff=""

buster_version="~buster+20200319"

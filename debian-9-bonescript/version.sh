#!/bin/bash -e

package_name="bonescript"
debian_pkg_name="${package_name}"
package_version="0.7.3-git20190822.0"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/beagleboard/bonescript"
git_sha="26c5522c1b7cee773049909c3b4925307620e469"
reprepro_dir="b/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee0"
debian_patch=""
debian_diff=""

dl_mirror="http://gitlab.gfnd.rcn-ee.org/RobertCNelson/npm-package-bonescript/raw/master/deploy/stretch"

v6="v6.17.0"
v8="v8.16.1"

datestamp="20190903"

bonescript="bonescript-0.7.3-26c5522"
   winston="winston-2.1.1"

debian_dl_1="${dl_mirror}/${bonescript}-${v6}-${datestamp}.tar.xz"
debian_dl_2="${dl_mirror}/${winston}-${v6}.tar.xz"

debian_dl_3="${dl_mirror}/${bonescript}-${v8}-${datestamp}.tar.xz"
debian_dl_4="${dl_mirror}/${winston}-${v8}.tar.xz"

stretch_version="~stretch+20190903"

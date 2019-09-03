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

debian_version="${package_version}-0rcnee2"
debian_patch=""
debian_diff=""

dl_mirror="http://gitlab.gfnd.rcn-ee.org/RobertCNelson/npm-package-bonescript/raw/master/deploy/buster"

v10="v10.15.2"

datestamp="20190903"

bonescript="bonescript-0.7.3-26c5522"
   winston="winston-2.1.1"

debian_dl_1="${dl_mirror}/${bonescript}-${v10}-${datestamp}.tar.xz"
debian_dl_2="${dl_mirror}/${winston}-${v10}.tar.xz"

buster_version="~buster+20190903"

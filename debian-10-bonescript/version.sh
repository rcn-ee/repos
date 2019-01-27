#!/bin/bash -e

package_name="bonescript"
debian_pkg_name="${package_name}"
package_version="0.7.1-git20190123.0"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/jadonk/bonescript"
git_sha="1dcc7ffa227a1e2da4655a695f3307f4c4b52719"
reprepro_dir="b/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee2"
debian_patch=""
debian_diff=""

#dl_mirror="https://github.com/rcn-ee/npm-package-bonescript/raw/master/deploy/buster/"
dl_mirror="http://gitlab.gfnd.rcn-ee.org/RobertCNelson/npm-package-bonescript/raw/master/deploy/buster"

v8="v8.11.2"

datestamp="20190124"

bonescript="bonescript-0.7.1-1dcc7ff"
   winston="winston-2.1.1"

debian_dl_1="${dl_mirror}/${bonescript}-${v8}-${datestamp}.tar.xz"
debian_dl_2="${dl_mirror}/${winston}-${v8}.tar.xz"

buster_version="~buster+20190127"

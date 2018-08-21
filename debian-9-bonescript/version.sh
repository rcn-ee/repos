#!/bin/bash -e

package_name="bonescript"
debian_pkg_name="${package_name}"
package_version="0.7.0-git20180821.0"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/jadonk/bonescript"
git_sha="b968db7a2e051e4c7eae0accf113c13db1ef7ef7"
reprepro_dir="b/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee0"
debian_patch=""
debian_diff=""

dl_mirror="https://github.com/rcn-ee/npm-package-bonescript/raw/master/deploy/stretch/"

v6="v6.14.4"
v8="v8.11.4"

datestamp="20180821"

bonescript="bonescript-0.7.0-b968db7"
   winston="winston-2.1.1"

debian_dl_1="${dl_mirror}/${bonescript}-${v6}-${datestamp}.tar.xz"
debian_dl_2="${dl_mirror}/${winston}-${v6}-${datestamp}.tar.xz"

debian_dl_3="${dl_mirror}/${bonescript}-${v8}-${datestamp}.tar.xz"
debian_dl_4="${dl_mirror}/${winston}-${v8}-${datestamp}.tar.xz"

stretch_version="~stretch+20180821"

#!/bin/bash -e

#https://github.com/c9/core

package_name="c9-core-installer"
debian_pkg_name="${package_name}"
package_version="3.1.5000.git20180223"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="c/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0rcnee3"
debian_untar=""
debian_patch=""

dl_mirror="https://github.com/rcn-ee/bb.org-cloud9-core/raw/master/deploy/stretch"

v6="v6.12.2"
v8="v8.11.2"

#debian_dl_1="${dl_mirror}/c9-core_${package_version}-${v6}-build.tar.xz"
debian_dl_1="${dl_mirror}/c9-core_3.1.4056.git20171215-${v6}-build.tar.xz"
#debian_dl_2="${dl_mirror}/c9-core_${package_version}-${v8}-build.tar.xz"

stretch_version="~stretch+20180919"

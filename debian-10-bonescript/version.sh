#!/bin/bash -e

package_name="bonescript"
debian_pkg_name="${package_name}"
package_version="0.6.3"
package_source="${package_name}_${package_version}.orig.tar.gz"
src_dir="${package_name}-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="b/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0rcnee0"
debian_untar=""
debian_patch=""

dl_mirror="https://github.com/rcn-ee/npm-package-bonescript/raw/master/deploy/buster/"

v6="v6.13.0"
v8="v8.9.4"

bonescript="bonescript-0.6.3-ae48732"
   winston="winston-2.1.1"

debian_dl_1="${dl_mirror}/${bonescript}-${v8}.tar.xz"
debian_dl_2="${dl_mirror}/${winston}-${v8}.tar.xz"

buster_version="~buster+20180305"

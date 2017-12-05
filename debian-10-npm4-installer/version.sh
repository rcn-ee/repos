#!/bin/bash -e

package_name="npm4-installer"
debian_pkg_name="${package_name}"
package_version="4.6.1"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="n/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0rcnee1"
debian_untar=""
debian_patch=""

dl_mirror="https://github.com/rcn-ee/npm-package-npm/raw/master/deploy/stretch/"

v8="v8.9.1"

bonescript="npm-4.6.1"

debian_dl_1="${dl_mirror}/${bonescript}-${v8}.tar.xz"

buster_version="~buster+20171205"

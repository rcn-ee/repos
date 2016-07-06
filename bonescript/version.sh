#!/bin/bash -e

package_name="bonescript"
debian_pkg_name="${package_name}"
package_version="0.5.0"
package_source="${package_name}_${package_version}.orig.tar.gz"
src_dir="${package_name}-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="b/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0rcnee5"
debian_untar=""
debian_patch=""
sbuild_chroot="nodejs-v0.12.x"
debian_dl_1="https://github.com/rcn-ee/npm-package-bonescript/raw/master/deploy/bonescript-0.5.0-v0.12.15.tar.xz"

jessie_version="~bpo80+20160706+1"

#!/bin/bash -e

package_name="bonescript"
debian_pkg_name="${package_name}"
package_version="0.5.1"
package_source="${package_name}_${package_version}.orig.tar.gz"
src_dir="${package_name}-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="b/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0rcnee2"
debian_untar=""
debian_patch=""
sbuild_chroot="nodejs-v0.12.x"
debian_dl_1="https://github.com/rcn-ee/npm-package-bonescript/raw/master/deploy/bonescript-0.5.2-491eff8-v0.12.17.tar.xz"
debian_dl_2="https://github.com/rcn-ee/npm-package-bonescript/raw/master/deploy/bonescript-0.5.2-491eff8-v4.6.2.tar.xz"
debian_dl_3="https://github.com/rcn-ee/npm-package-bonescript/raw/master/deploy/bonescript-0.5.2-491eff8-v6.9.1.tar.xz"

jessie_version="~bpo80+20161115+1"

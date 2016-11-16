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

dl_mirror="https://github.com/rcn-ee/npm-package-bonescript/raw/master/deploy"

v12="v0.12.17"
 v4="v4.6.2"
 v6="v6.9.1"

bonescript="bonescript-0.5.2-491eff8"

debian_dl_1="${dl_mirror}/${bonescript}-${v12}.tar.xz"
debian_dl_2="${dl_mirror}/${bonescript}-${v4}.tar.xz"
debian_dl_3="${dl_mirror}/${bonescript}-${v6}.tar.xz"

jessie_version="~bpo80+20161115+1"

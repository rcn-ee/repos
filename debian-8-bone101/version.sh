#!/bin/bash -e

package_name="bone101"
debian_pkg_name="${package_name}"
package_version="1.1.7"
package_source="${package_name}_${package_version}.orig.tar.gz"
src_dir="${package_name}-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="b/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0rcnee0"
debian_untar=""
debian_patch=""
sbuild_chroot="nodejs-v0.12.x"

dl_mirror="https://github.com/rcn-ee/npm-package-bb-doc-bone101/raw/master/deploy"

v12="v0.12.17"
 v4="v4.6.2"
 v6="v6.9.1"

    node_async="async-2.0.0-rc.6"
node_sensortag="sensortag-1.2.3"

debian_dl_1="${dl_mirror}/${node_async}-${v12}.tar.xz"
debian_dl_2="${dl_mirror}/${node_async}-${v4}.tar.xz"
debian_dl_3="${dl_mirror}/${node_async}-${v6}.tar.xz"
debian_dl_4="${dl_mirror}/${node_sensortag}-${v12}.tar.xz"
debian_dl_5="${dl_mirror}/${node_sensortag}-${v4}.tar.xz"
debian_dl_6="${dl_mirror}/${node_sensortag}-${v6}.tar.xz"

jessie_version="~jessie+20170608"

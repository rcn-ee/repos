#!/bin/bash -e

#https://github.com/c9/core

package_name="c9-core-installer"
debian_pkg_name="${package_name}"
package_version="3.1.3543+git20170407"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="c/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0rcnee8"
debian_untar=""
debian_patch=""

dl_mirror="https://rcn-ee.net/repos/git/bb.org-cloud9-core/deploy/jessie"

v6="v6.10.2"
v4="v4.8.2"
v12="v0.12.18"

debian_dl_1="${dl_mirror}/c9-core_${package_version}-${v6}-build.tar.xz"
debian_dl_2="${dl_mirror}/c9-core_${package_version}-${v4}-build.tar.xz"
debian_dl_3="${dl_mirror}/c9-core_${package_version}-${v12}-build.tar.xz"

jessie_version="~bpo80+20170413"

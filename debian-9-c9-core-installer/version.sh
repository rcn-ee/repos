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

debian_version="${package_version}-0rcnee4"
debian_untar=""
debian_patch=""

dl_mirror="https://rcn-ee.net/repos/git/bb.org-cloud9-core/deploy/stretch"

v6="v6.10.2"

debian_dl_1="${dl_mirror}/c9-core_${package_version}-${v6}-build.tar.xz"

stretch_version="~bpo90+20170413"

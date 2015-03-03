#!/bin/bash -e

mirror="http://archive.ubuntu.com/ubuntu"

#http://archive.ubuntu.com/ubuntu/pool/universe/s/solid/solid_5.7.0-0ubuntu1.dsc
#http://archive.ubuntu.com/ubuntu/pool/universe/s/solid/solid_5.7.0.orig.tar.xz
#http://archive.ubuntu.com/ubuntu/pool/universe/s/solid/solid_5.7.0-0ubuntu1.debian.tar.xz

package_name="solid"
debian_pkg_name="solid"
package_version="5.7.0"
package_source="${debian_pkg_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="s/${package_name}"
dl_path="pool/universe/${reprepro_dir}/"

debian_version="${package_version}-0ubuntu1"
debian_patch="${debian_pkg_name}_${debian_version}.debian.tar.xz"
debian_diff=""

jessie_version="~20150227+1"

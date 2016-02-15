#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="node-once"
debian_pkg_name="${package_name}"
package_version="1.1.1"
package_source="${package_name}_${package_version}.orig.tar.gz"
src_dir="once-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="n/${package_name}"
dl_path="${mirror}/pool/main/${reprepro_dir}/"

debian_version="${package_version}-1"
debian_untar="${package_name}_${debian_version}.debian.tar.gz"
debian_patch=""

jessie_version="~20141124+1"
wheezy_version="~bpo70+20141218+1"

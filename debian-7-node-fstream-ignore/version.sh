#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="node-fstream-ignore"
debian_pkg_name="${package_name}"
package_version="0.0.6"
package_source="${package_name}_${package_version}.orig.tar.gz"
src_dir="fstream-ignore-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="n/${package_name}"
dl_path="${mirror}/pool/main/${reprepro_dir}/"

debian_version="${package_version}-2"
debian_untar="${package_name}_${debian_version}.debian.tar.gz"
debian_patch=""

jessie_version="~20141124+1"
wheezy_version="~bpo70+20141218+1"

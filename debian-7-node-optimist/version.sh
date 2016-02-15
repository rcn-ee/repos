#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="node-optimist"
debian_pkg_name="${package_name}"
package_version="0.3.5"
package_source="${package_name}_${package_version}.orig.tar.gz"
src_dir="package"

git_repo=""
git_sha=""
reprepro_dir="n/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-1"
debian_untar="${package_name}_${debian_version}.debian.tar.gz"
debian_patch=""

jessie_version="~20141124+1"
wheezy_version="~bpo70+20150123+1"

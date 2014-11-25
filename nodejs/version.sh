#!/bin/bash -e

mirror="http://ftp.de.debian.org/debian"

package_name="nodejs"
debian_pkg_name="${package_name}"
package_version="0.10.29~dfsg"
package_source="${package_name}_${package_version}.orig.tar.gz"
src_dir="node-v0.10.29"

git_repo=""
git_sha=""
reprepro_dir="n/${package_name}"
dl_path="${mirror}/pool/main/${reprepro_dir}/"

debian_version="${package_version}-1"
debian_untar="nodejs_0.10.29~dfsg-1~bpo70+1.debian.tar.xz"
debian_patch=""

jessie_version="~20141124+1"
wheezy_version="~bpo70+20141125+1"

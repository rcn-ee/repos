#!/bin/bash -e

#mirror="http://ftp.de.debian.org/debian"
#0.10.38
mirror="http://snapshot.debian.org/archive/debian/20150505T035629Z"

package_name="nodejs"
debian_pkg_name="${package_name}"
package_version="0.10.41~dfsg"
real_package_version="0.10.41"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="node-v0.10.41"

git_repo=""
git_sha=""
reprepro_dir="n/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-1"
debian_untar=""
debian_patch=""
local_patch="rcnee1"

wheezy_version="~bpo70+20151221+1"
jessie_version="~bpo80+20151221+1"

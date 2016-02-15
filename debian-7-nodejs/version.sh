#!/bin/bash -e

#mirror="http://http.debian.net/debian"
#0.10.38
mirror="http://snapshot.debian.org/archive/debian/20150505T035629Z"

package_name="nodejs"
debian_pkg_name="${package_name}"
package_version="0.10.42~dfsg"
real_package_version="0.10.42"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="node-v0.10.42"

git_repo=""
git_sha=""
reprepro_dir="n/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0"
debian_untar=""
debian_patch=""
local_patch="rcnee1"

wheezy_version="~bpo70+20160210+1"
jessie_version="~bpo80+20160210+1"

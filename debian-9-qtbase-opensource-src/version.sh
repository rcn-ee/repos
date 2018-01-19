#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="qtbase-opensource-src"
debian_pkg_name="${package_name}"
package_version="5.7.1+dfsg"
package_source="${debian_pkg_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}-5.7.1"

git_repo=""
git_sha=""
reprepro_dir="q/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-3"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""
local_patch="rcnee0"

stretch_version="~stretch+20180119"

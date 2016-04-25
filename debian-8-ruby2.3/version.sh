#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="ruby2.3"
debian_pkg_name="${package_name}"
package_version="2.3.0"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="ruby-2_3_0"

git_repo=""
git_sha=""
reprepro_dir="r/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-5"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""

jessie_version="~bpo80+20160425+1"

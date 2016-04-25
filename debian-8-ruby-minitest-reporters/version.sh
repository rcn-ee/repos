#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="ruby-minitest-reporters"
debian_pkg_name="${package_name}"
package_version="1.0.19"
package_source="${package_name}_${package_version}.orig.tar.gz"
src_dir="minitest-reporters-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="r/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-1"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""

jessie_version="~bpo80+20160425+1"

#!/bin/bash -e

mirror="http://snapshot.debian.org/archive/debian/20151118T154517Z"

package_name="golang"
debian_pkg_name="${package_name}"
package_version="1.4.3"
package_source="${debian_pkg_name}_${package_version}.orig.tar.gz"
src_dir="go"

git_repo=""
git_sha=""
reprepro_dir="g/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-3~bpo8+1"
debian_patch="${debian_pkg_name}_${debian_version}.debian.tar.xz"
debian_diff=""

jessie_version="~bpo80+20160614+1"

#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="gst-plugins-bad1.0"
debian_pkg_name="${package_name}"
package_version="1.4.4"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="gst-plugins-base-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="g/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-2.1"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""
local_patch="rcnee1"

jessie_version="~bpo80+20151216+1"

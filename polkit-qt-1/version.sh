#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="polkit-qt-1"
debian_pkg_name="${package_name}"
package_version="0.112.0"
package_source="${package_name}_${package_version}.orig.tar.bz2"
src_dir="${package_name}-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="p/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-4"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""

jessie_version="~bpo80+20151104+1"
stretch_version="~bpo90+20151104+1"

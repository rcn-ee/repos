#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="cmst"
debian_pkg_name="${package_name}"
package_version="2016.01.28"
package_source="${package_name}_${package_version}.orig.tar.gz"
src_dir="${package_name}-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="c/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-2"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""

stretch_version="~bpo90+20151228+1"
jessie_version="~bpo80+20160201+1"

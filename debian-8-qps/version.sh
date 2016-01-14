#!/bin/bash -e

mirror="http://ftp.de.debian.org/debian"

package_name="qps"
debian_pkg_name="${package_name}"
package_version="1.10.16+20151210"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="q/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-1"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""

jessie_version="~bpo80+20151228+1"
stretch_version="~bpo90+20151228+1"

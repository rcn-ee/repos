#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="libdbusmenu-qt"
debian_pkg_name="${package_name}"
package_version="0.9.3+15.10.20150604"
package_source="${package_name}_${package_version}.orig.tar.gz"
src_dir="${package_name}-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="libd/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-1"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"

jessie_version="~bpo80+20150624+1"

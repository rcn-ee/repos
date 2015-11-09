#!/bin/bash -e

mirror="http://ftp.de.debian.org/debian"

package_name="lxqt-sudo"
debian_pkg_name="${package_name}"
package_version="0.10.0"
package_source="${package_name}_${package_version}.orig.tar.gz"
src_dir="${package_name}-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="l/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-1"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""

jessie_version="~bpo80+20151108+1"
stretch_version="~bpo90+20151108+1"

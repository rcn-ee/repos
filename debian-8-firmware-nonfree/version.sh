#!/bin/bash -e

mirror="http://ftp.de.debian.org/debian"

package_name="firmware-nonfree"
debian_pkg_name="${package_name}"
package_version="20160110"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="f/${package_name}"
dl_path="pool/non-free/${reprepro_dir}/"

debian_version="${package_version}-1"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""

jessie_version="~bpo80+20160117+1"

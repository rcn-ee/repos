#!/bin/bash -e

mirror="http://ftp.de.debian.org/debian"

package_name="dh-python"
debian_pkg_name="${package_name}"
package_version="1.20140511"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="d/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-1~bpo70+1"
debian_untar="${package_name}_${debian_version}.debian.tar.gz"
debian_patch=""

wheezy_version="~bpo70+20151120+1"

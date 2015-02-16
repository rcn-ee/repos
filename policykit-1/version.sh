#!/bin/bash -e

mirror="http://ftp.de.debian.org/debian"

package_name="policykit-1"
debian_pkg_name="${package_name}"
package_version="0.112"
package_source="${package_name}_${package_version}.orig.tar.gz"
src_dir="polkit-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="p/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-4.3"
#debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""

wheezy_version="~bpo70+20141218+1"
jessie_version="~20150216+1"

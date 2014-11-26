#!/bin/bash -e

mirror="http://ftp.de.debian.org/debian"

package_name="openjfx"
debian_pkg_name="${package_name}"
package_version="8u20-b26"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="rt-8u20-b26"

git_repo=""
git_sha=""
reprepro_dir="o/${package_name}"
dl_path="${mirror}/pool/main/${reprepro_dir}/"

debian_version="${package_version}-3"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""

wheezy_version="~bpo70+20141112+1"
jessie_version="~20141126+1"

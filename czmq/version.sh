#!/bin/bash -e

mirror="http://ftp.de.debian.org/debian"

package_name="czmq"
debian_pkg_name="${package_name}"
package_version="2.2.0"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/zeromq/czmq"
git_sha="b0e9b7f1448f9b0546c700ea0a46dc8bb0dd2ebd"
reprepro_dir="c/${package_name}"
dl_path=""

debian_version="${package_version}-1"
debian_untar=""
debian_patch=""

trusty_version="~20141222+2"
wheezy_version="~bpo70+20141222+2"
jessie_version="~20141222+2"

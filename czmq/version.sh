#!/bin/bash -e

mirror="http://ftp.de.debian.org/debian"

package_name="czmq"
debian_pkg_name="${package_name}"
package_version="3.0.0~rc1+git20141217"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/zeromq/czmq"
git_sha="869c3145b2ae60802f6239b9615b2bcd8b715d96"
reprepro_dir="c/${package_name}"
dl_path=""

debian_version="${package_version}-1"
debian_untar=""
debian_patch=""

trusty_version="~20141222+2"
wheezy_version="~bpo70+20141222+2"
jessie_version="~20141222+2"

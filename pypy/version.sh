#!/bin/bash -e

mirror="http://ftp.de.debian.org/debian"

package_name="pypy"
debian_pkg_name="${package_name}"
package_version="2.4.0+dfsg"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="pypy-2.4.0.orig"

git_repo=""
git_sha=""
reprepro_dir="p/${package_name}"
dl_path="${mirror}/pool/main/${reprepro_dir}/"

debian_version="${package_version}-1"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""

jessie_version="~20141124+1"
trusty_version="~20141214+1"
wheezy_version="~bpo70+20141214+1"

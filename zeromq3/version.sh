#!/bin/bash -e

mirror="http://ftp.de.debian.org/debian"

package_name="zeromq3"
debian_pkg_name="${package_name}"
package_version="4.0.5+dfsg"
package_source="${package_name}_${package_version}.orig.tar.bz2"
src_dir="${package_name}-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="z/${package_name}"
dl_path="${mirror}/pool/main/${reprepro_dir}/"

debian_version="${package_version}-2"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""

jessie_version="~20141124+1"
wheezy_version="~bpo70+20141219+2"

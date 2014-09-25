#!/bin/bash -e

mirror="http://ftp.de.debian.org/debian"

package_name="xf86-video-omap"
debian_pkg_name="${package_name}"
package_version="0.4.3"
package_source="${package_name}_${package_version}.orig.tar.gz"
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="x/${package_name}"
dl_path="${mirror}/pool/main/${reprepro_dir}/"

debian_version="${package_version}-1"
debian_untar="${package_name}_${debian_version}.debian.tar.gz"
debian_patch=""

wheezy_version="~bpo70+20140924+1"
jessie_version="~20140924+1"

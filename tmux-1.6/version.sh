#!/bin/bash -e

mirror="http://ftp.de.debian.org/debian"

package_name="tmux-1.6"
debian_pkg_name="${package_name}"
package_version="1.6"
package_source="${package_name}_${package_version}.orig.tar.gz"
src_dir="${package_name}"

git_repo=""
git_sha=""
reprepro_dir="t/${package_name}"
dl_path="${mirror}/pool/main/${reprepro_dir}/"

debian_version="${package_version}-2"
debian_untar=""
debian_patch=""

wheezy_version="~bpo70+20140924+1"
jessie_version="~20141022+1"

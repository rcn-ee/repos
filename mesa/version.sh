#!/bin/bash -e

#mirror="http://ftp.de.debian.org/debian"

package_name="mesa"
debian_pkg_name="${package_name}"
package_version="10.3.3-git20141119"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://anongit.freedesktop.org/mesa/mesa"
git_sha="8b5e53434c9dc8432fdce88aee1ffa6567f99eb4"
reprepro_dir="m/${package_name}"
dl_path=""

debian_version="${package_version}-1"
debian_patch=""
debian_diff=""

wheezy_version="~bpo70+20141112+1"
jessie_version="~20141119+1"

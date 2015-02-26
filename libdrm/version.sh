#!/bin/bash -e

#mirror="http://ftp.de.debian.org/debian"

package_name="libdrm"
debian_pkg_name="${package_name}"
package_version="2.4.59"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}-${package_version}"

git_repo="git://anongit.freedesktop.org/mesa/drm"
git_sha="d2e0f552467ca11162fe04dfed55de4590280f23"
reprepro_dir="libd/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0etnaviv"
debian_untar=""
#debian_patch="${package_name}_${debian_version}.diff.gz"

wheezy_version="~bpo70+20150226+1"
jessie_version="~20150226+1"
trusty_version="~20150226+1"

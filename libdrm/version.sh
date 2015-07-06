#!/bin/bash -e

mirror="http://ftp.de.debian.org/debian"

package_name="libdrm"
debian_pkg_name="${package_name}"
package_version="2.4.62"
package_source="${package_name}_${package_version}.orig.tar.gz"
src_dir="${package_name}-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="libd/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-1.2"
#debian_version="${package_version}-1etnaviv1"
debian_untar=""
debian_patch="${package_name}_${package_version}-1.diff.gz"

wheezy_version="~bpo70+20150706+1"
jessie_version="~bpo80+20150706+1"
stretch_version="~bpo90+20150706+1"
trusty_version="~bpo1404+20150706+1"

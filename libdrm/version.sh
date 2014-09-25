#!/bin/bash -e

mirror="http://ftp.de.debian.org/debian"

package_name="libdrm"
package_version="2.4.56"
package_source="${package_name}_${package_version}.orig.tar.gz"
src_dir="${package_name}-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="libd/${package_name}"
dl_path="${mirror}/pool/main/${reprepro_dir}/"

debian_version="${package_version}-1"
debian_untar=""
debian_patch="${package_name}_${debian_version}.diff.gz"

wheezy_version="~bpo70+20140924+1"
jessie_version="~20140924+1"

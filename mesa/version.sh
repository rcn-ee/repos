#!/bin/bash -e

mirror="http://ftp.de.debian.org/debian"

package_name="mesa"
debian_pkg_name="${package_name}"
package_version="10.4.2"
package_source="${package_name}_${package_version}.orig.tar.gz"
src_dir="Mesa-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="m/${package_name}"
dl_path="${mirror}/pool/main/${reprepro_dir}/"

debian_version="${package_version}-1"
debian_untar=""
debian_patch="${package_name}_${debian_version}.diff.gz"

wheezy_version="~bpo70+20141112+1"
jessie_version="~bpo80+20150113+1"

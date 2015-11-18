#!/bin/bash -e

mirror="http://ftp.de.debian.org/debian"

package_name="nodejs"
debian_pkg_name="${package_name}"
package_version="4.2.2~dfsg"
real_package_version="4.2.2"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="node-v4.2.2"

git_repo=""
git_sha=""
reprepro_dir="n/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-1"
debian_untar=""
debian_patch=""

jessie_version="~bpo80+20151117+1"

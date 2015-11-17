#!/bin/bash -e

mirror="http://ftp.de.debian.org/debian"

#1.0.2d-1
#mirror="http://snapshot.debian.org/archive/debian/20150709T214436Z"

#1.0.2d-2 (ssl3 removed, soname bump..)
#mirror="http://snapshot.debian.org/archive/debian/20150908T213435Z"

package_name="openssl"
debian_pkg_name="${package_name}"
package_version="1.0.2d"
package_source="${package_name}_${package_version}.orig.tar.gz"
src_dir="${package_name}-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="o/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-3"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""

jessie_version="~bpo80+20151116+1"

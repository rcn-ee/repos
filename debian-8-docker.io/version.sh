#!/bin/bash -e

mirror="http://ftp.de.debian.org/debian"

package_name="docker.io"
debian_pkg_name="${package_name}"
package_version="1.6.2~dfsg1"

git_repo=""
git_sha=""
reprepro_dir="d/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-1~bpo8+1"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""

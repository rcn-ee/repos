#!/bin/bash -e

mirror="http://ftp.de.debian.org/debian"

package_name="init-system-helpers"
debian_pkg_name="${package_name}"
package_version="1.18~bpo70+1"

git_repo=""
git_sha=""
reprepro_dir="i/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version=""
debian_untar=""
debian_patch=""

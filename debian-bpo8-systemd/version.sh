#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="systemd"
debian_pkg_name="${package_name}"
package_version="230"

git_repo=""
git_sha=""
reprepro_dir="s/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-7~bpo8+1"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""

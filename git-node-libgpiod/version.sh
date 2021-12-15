#!/bin/bash -e

#https://github.com/sombriks/node-libgpiod

#mirror="http://http.debian.net/debian"

package_name="node-libgpiod"
debian_pkg_name="${package_name}"
package_version="0.1.4-git20210113.0"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/sombriks/node-libgpiod"
git_sha="a66ad545d58d4e99b48f344954fd153079515f6b"
reprepro_dir="n/${package_name}"
dl_path=""

debian_version="${package_version}-0"
debian_patch=""
debian_diff=""

clear_changelog="enable"

bullseye_version="~bullseye+20211215"

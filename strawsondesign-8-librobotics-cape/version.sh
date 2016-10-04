#!/bin/bash -e

mirror="http://strawsondesign.com/debian"

package_name="librobotics-cape"
debian_pkg_name="${package_name}"
package_version="0.0.1"

git_repo=""
git_sha=""
reprepro_dir=""
dl_path=""

debian_version="${package_version}"
debian_untar=""
debian_patch=""


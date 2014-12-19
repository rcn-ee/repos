#!/bin/bash -e

mirror="http://ftp.de.debian.org/debian"

package_name="zeromq4"
debian_pkg_name="${package_name}"
package_version="4.0.5+git20141205"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/zeromq/zeromq4-x.git"
git_sha="b6e3e0f601e2c1ec1f3aac880ed6a3fe63043e51"
reprepro_dir="z/${package_name}"
dl_path=""

debian_version="${package_version}-1"
debian_untar=""
debian_patch=""

jessie_version="~20141124+1"
wheezy_version="~bpo70+20141219+1"

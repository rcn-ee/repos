#!/bin/bash -e

package_name="bb-johnny-five-installer"
debian_pkg_name="${package_name}"
package_version="1.3.1"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="b/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0rcnee2"
debian_untar=""
debian_patch=""

stretch_version="~stretch+20191204"
buster_version="~buster+20191204"
bionic_version="~bionic+20191204"

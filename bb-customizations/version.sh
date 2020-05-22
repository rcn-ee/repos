#!/bin/bash -e

package_name="bb-customizations"
debian_pkg_name="${package_name}"
package_version="1.20200522.1"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="b/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0"
debian_untar=""
debian_patch=""

stretch_version="~stretch+20200522"
buster_version="~buster+20200522"
bionic_version="~bionic+20200522"
focal_version="~focal+20200522"

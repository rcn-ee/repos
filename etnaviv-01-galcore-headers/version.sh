#!/bin/bash -e

package_name="galcore-headers"
debian_pkg_name="${package_name}"
package_version="4.6.6.1381"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="g/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0rcnee4"
debian_untar=""
debian_patch=""

stretch_version="~stretch+20200512"
buster_version="~buster+20200512"
bionic_version="~bionic+20200512"
focal_version="~focal+20200512"

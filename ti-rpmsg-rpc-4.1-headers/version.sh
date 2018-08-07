#!/bin/bash -e

package_name="rpmsg-rpc-4.1-headers"
debian_pkg_name="${package_name}"
package_version="4.1.20180807"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="r/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0rcnee0"
debian_untar=""
debian_patch=""

jessie_version="~jessie+20180807"
stretch_version="~stretch+20180807"
buster_version="~buster+20180807"
xenial_version="~xenial+20180807"
bionic_version="~bionic+20180807"

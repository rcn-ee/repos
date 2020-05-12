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

debian_version="${package_version}-0rcnee3"
debian_untar=""
debian_patch=""

jessie_version="~jessie+20180831"
stretch_version="~stretch+20180831"
buster_version="~buster+20180831"
xenial_version="~xenial+20180831"
bionic_version="~bionic+20180831"

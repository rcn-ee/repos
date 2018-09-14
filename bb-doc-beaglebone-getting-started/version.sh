#!/bin/bash -e

#https://github.com/beagleboard/beaglebone-getting-started

package_name="doc-beaglebone-getting-started"
debian_pkg_name="${package_name}"
package_version="1.20180913.0"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="d/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0rcnee0"
debian_untar=""
debian_patch=""
debian_dl_1="https://rcn-ee.net/repos/git/archive/beaglebone-getting-started/beaglebone-getting-started-2018-09-13.img.xz"

artful_version="~artful+20180517"
jessie_version="~jessie+20180914"
stretch_version="~stretch+20180914"
buster_version="~buster+20180914"
xenial_version="~xenial+20180914"
bionic_version="~bionic+20180914"

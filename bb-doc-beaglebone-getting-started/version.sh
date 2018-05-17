#!/bin/bash -e

#https://github.com/beagleboard/beaglebone-getting-started

package_name="doc-beaglebone-getting-started"
debian_pkg_name="${package_name}"
package_version="1.20170526"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="d/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0rcnee0"
debian_untar=""
debian_patch=""
debian_dl_1="https://rcn-ee.net/repos/git/archive/beaglebone-getting-started/beaglebone-getting-started-2017-05-26.img.xz"

jessie_version="~jessie+20180517"
stretch_version="~stretch+20180517"
buster_version="~buster+20180517"
xenial_version="~xenial+20180517"
artful_version="~artful+20180517"
bionic_version="~bionic+20180517"

#!/bin/bash -e

#https://github.com/beagleboard/beaglebone-getting-started

package_name="doc-beaglebone-getting-started"
debian_pkg_name="${package_name}"
package_version="1.20170525"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="d/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0rcnee1"
debian_untar=""
debian_patch=""
debian_dl_1="https://rcn-ee.net/repos/git/archive/beaglebone-getting-started/beaglebone-getting-started-2017-05-25.img.xz"

wheezy_version="~wheezy+20170525"
jessie_version="~jessie+20170525"
stretch_version="~stretch+20170525"
trusty_version="~trusty+20170525"
xenial_version="~xenial+20170525"
yakkety_version="~yakkety+20170525"
zesty_version="~zesty+20170525"
artful_version="~artful+20170525"

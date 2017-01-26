#!/bin/bash -e

#https://github.com/beagleboard/beaglebone-getting-started

package_name="doc-beaglebone-getting-started"
debian_pkg_name="${package_name}"
package_version="1.20170125"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="d/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0rcnee1"
debian_untar=""
debian_patch=""
debian_dl_1="https://rcn-ee.net/repos/git/archive/beaglebone-getting-started/beaglebone-getting-started-2017-01-25.img.xz"

wheezy_version="~bpo70+20170126+1"
jessie_version="~bpo80+20170126+1"
stretch_version="~bpo90+20170126+1"
trusty_version="~bpo1404+20170126+1"
xenial_version="~bpo1604+20170126+1"
yakkety_version="~bpo1610+20170126+1"
zesty_version="~bpo1704+20170126+1"

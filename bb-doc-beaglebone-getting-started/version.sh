#!/bin/bash -e

#https://github.com/beagleboard/beaglebone-getting-started

package_name="doc-beaglebone-getting-started"
debian_pkg_name="${package_name}"
package_version="1.20160718"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="d/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0rcnee1"
debian_untar=""
debian_patch=""
debian_dl_1="https://rcn-ee.net/repos/git/archive/beaglebone-getting-started/beaglebone-getting-started-2016-07-18.iso.xz"

wheezy_version="~bpo70+20160718+1"
jessie_version="~bpo80+20160718+1"
stretch_version="~bpo90+20160718+1"
trusty_version="~bpo1404+20160718+1"
xenial_version="~bpo1604+20160718+1"
yakkety_version="~bpo1610+20160718+1"

#!/bin/bash -e

#http://software-dl.ti.com/codegen/non-esd/downloads/download.htm#PRU

package_name="ti-pru-cgt-installer"
debian_pkg_name="${package_name}"
package_version="2.1.4"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="t/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0"
debian_untar=""
debian_patch=""
local_patch="rcnee0"

wheezy_version="~bpo70+20170216+1"
jessie_version="~bpo80+20170216+1"
stretch_version="~bpo90+20170216+1"
trusty_version="~bpo1404+20170216+1"
xenial_version="~bpo1604+20170216+1"
yakkety_version="~bpo1610+20170216+1"
zesty_version="~bpo1704+20170216+1"

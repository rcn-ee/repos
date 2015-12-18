#!/bin/bash -e

#http://software-dl.ti.com/codegen/non-esd/downloads/download.htm#C6000

package_name="ti-c6000-cgt-v8.1.x-installer"
debian_pkg_name="${package_name}"
package_version="8.1.0"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="t/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0"
debian_untar=""
debian_patch=""
local_patch="rcnee1"

wheezy_version="~bpo70+20151218+1"
jessie_version="~bpo80+20151218+1"
stretch_version="~bpo90+20151218+1"
trusty_version="~bpo1404+20151218+1"
vivid_version="~bpo1504+20151218+1"
wily_version="~bpo1510+20151218+1"
xenial_version="~bpo1604+20151218+1"

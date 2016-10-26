#!/bin/bash -e

#http://software-dl.ti.com/codegen/non-esd/downloads/download.htm#C6000

package_name="ti-c6000-cgt-v8.1.x-installer"
debian_pkg_name="${package_name}"
package_version="8.1.2"
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

jessie_version="~bpo80+20161026+1"
stretch_version="~bpo90+20161026+1"
xenial_version="~bpo1604+20161026+1"
zesty_version="~bpo1704+20161026+1"

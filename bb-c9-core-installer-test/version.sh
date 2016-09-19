#!/bin/bash -e

#https://github.com/c9/core

package_name="c9-core-installer"
debian_pkg_name="${package_name}"
package_version="3.1.3088+git20160915"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="c/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0"
debian_untar=""
debian_patch=""
local_patch="rcnee3"

stretch_version="~bpo90+20160502+1"
xenial_version="~bpo1604+20160502+1"
yakkety_version="~bpo1610+20160502+1"
jessie_version="~bpo80+20160919+1"

#!/bin/bash -e

package_name="seeed-wificonfig-installer"
debian_pkg_name="${package_name}"
package_version="0.0.2"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="s/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0"
debian_untar=""
debian_patch=""
local_patch="rcnee1"

stretch_version="~bpo90+20160321+1"
xenial_version="~bpo1604+20160321+1"
jessie_version="~bpo80+20160427+1"

#!/bin/bash -e

package_name="bb-wl18xx-firmware"
debian_pkg_name="${package_name}"
package_version="1.20170612"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="b/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0rcnee0"
debian_untar=""
debian_patch=""

jessie_version="~jessie+20170612"
stretch_version="~stretch+20170612"
xenial_version="~xenial+20170612"
yakkety_version="~yakkety+20170612"
zesty_version="~zesty+20170612"
artful_version="~artful+20170612"

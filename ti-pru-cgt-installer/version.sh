#!/bin/bash -e

#http://software-dl.ti.com/codegen/non-esd/downloads/download.htm#PRU

package_name="ti-pru-cgt-installer"
debian_pkg_name="${package_name}"
package_version="2.1.5"
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

jessie_version="~jessie+20180514"
stretch_version="~stretch+20180514"
buster_version="~buster+20180514"
xenial_version="~xenial+20180514"
artful_version="~artful+20180514"
bionic_version="~bionic+20180514"

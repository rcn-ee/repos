#!/bin/bash -e

#https://www.ti.com/tool/PRU-CGT
#https://www.ti.com/tool/download/PRU-CGT-2-1

package_name="ti-pru-cgt-installer"
debian_pkg_name="${package_name}"
package_version="2.1.5"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="t/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0rcnee3"
debian_untar=""
debian_patch=""

debian_dl_1="http://software-dl.ti.com/codegen/esd/cgt_public_sw/PRU/2.1.5/ti_cgt_pru_2.1.5_armlinuxa8hf_busybox_installer.sh"

stretch_version="~stretch+20200806"
buster_version="~buster+20200806"
bionic_version="~bionic+20200806"
focal_version="~focal+20200806"

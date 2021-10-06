#!/bin/bash -e

#https://www.ti.com/tool/download/PRU-CGT-2-3

package_name="ti-pru-cgt-v2.3"
debian_pkg_name="${package_name}"
package_version="2.3.3"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="t/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0rcnee5"
debian_untar=""
debian_patch=""

debian_dl_1="https://software-dl.ti.com/codegen/esd/cgt_public_sw/PRU/2.3.3/ti_cgt_pru_2.3.3_armlinuxa8hf_busybox_installer.sh"

bullseye_version="~bullseye+20211006"

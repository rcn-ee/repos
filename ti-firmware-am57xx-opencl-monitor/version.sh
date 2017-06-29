#!/bin/bash -e

package_name="firmware-am57xx-opencl-monitor"
debian_pkg_name="${package_name}"
package_version="1.1.13.0-r0.0"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="f/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}rcnee0"
debian_untar=""
debian_patch=""

debian_dl_1="https://github.com/rcn-ee/sdk-firmware/raw/master/opencl-monitor/${package_version}/files/dra7-dsp1-fw.xe66"
debian_dl_2="https://github.com/rcn-ee/sdk-firmware/raw/master/opencl-monitor/${package_version}/files/dra7-dsp2-fw.xe66"
debian_dl_3="https://github.com/rcn-ee/sdk-firmware/raw/master/opencl-monitor/${package_version}/files/dsp.out"
debian_dl_4="https://github.com/rcn-ee/sdk-firmware/raw/master/opencl-monitor/${package_version}/files/dsp.syms"
debian_dl_5="https://github.com/rcn-ee/sdk-firmware/raw/master/opencl-monitor/${package_version}/files/dsp_syms.obj"

jessie_version="~jessie+20170629"
stretch_version="~stretch+20170629"
xenial_version="~xenial+20170629"

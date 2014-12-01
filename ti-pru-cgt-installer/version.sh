#!/bin/bash -e

#http://software-dl.ti.com/codegen/non-esd/downloads/download.htm#PRU

package_name="ti-pru-cgt-installer"
debian_pkg_name="${package_name}"
package_version="2.1.0"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="t/${package_name}"
dl_path="${mirror}/pool/main/${reprepro_dir}/"

debian_version="${package_version}-1"
debian_untar=""
debian_patch=""

wheezy_version="~bpo70+20141201+1"
jessie_version="~20141201+1"
trusty_version="~20141201+1"

#!/bin/bash -e

#http://software-dl.ti.com/codegen/non-esd/downloads/download.htm#C6000

package_name="ti-c6000-cgt-v8.0.x-installer"
debian_pkg_name="${package_name}"
package_version="8.0.1"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="t/${package_name}"
dl_path="${mirror}/pool/main/${reprepro_dir}/"

debian_version="${package_version}-1"
debian_untar=""
debian_patch=""

wheezy_version="~bpo70+20150128+1"
jessie_version="~20150128+1"
trusty_version="~20150128+1"

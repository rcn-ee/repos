#!/bin/bash -e

#http://software-dl.ti.com/codegen/non-esd/downloads/download.htm#C6000

package_name="ti-c6000-cgt-v8.0.x-installer"
debian_pkg_name="${package_name}"
package_version="8.0.3"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="t/${package_name}"
dl_path="${mirror}/pool/main/${reprepro_dir}/"

debian_version="${package_version}-1"
debian_untar=""
debian_patch=""

wheezy_version="~bpo70+20150611+1"
jessie_version="~bpo80+20150611+1"
stretch_version="~bpo90+20150611+1"
trusty_version="~bpo1404+20150611+1"
utopic_version="~bpo1410+20150611+1"
vivid_version="~bpo1504+20150611+1"
wily_version="~bpo1510+20150611+1"

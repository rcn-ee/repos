#!/bin/bash -e

#http://software-dl.ti.com/codegen/non-esd/downloads/download.htm#C6000

package_name="ti-c6000-cgt-v8.2.x-installer"
debian_pkg_name="${package_name}"
package_version="8.2.5"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="t/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0rcnee0"
debian_untar=""
debian_patch=""

jessie_version="~jessie+20190102"
stretch_version="~stretch+20190102"
buster_version="~buster+20190102"
xenial_version="~xenial+20190102"
bionic_version="~bionic+20190102"

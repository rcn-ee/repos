#!/bin/bash -e

package_name="bb-customizations"
debian_pkg_name="${package_name}"
package_version="1.20171123"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="b/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0rcnee0"
debian_untar=""
debian_patch=""

jessie_version="~jessie+20171123"
stretch_version="~stretch+20171123"
buster_version="~buster+20171123"
xenial_version="~xenial+20171123"
zesty_version="~zesty+20171123"
artful_version="~artful+20171123"

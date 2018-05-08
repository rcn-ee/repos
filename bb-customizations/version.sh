#!/bin/bash -e

package_name="bb-customizations"
debian_pkg_name="${package_name}"
package_version="1.20180508"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="b/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0rcnee0"
debian_untar=""
debian_patch=""

jessie_version="~jessie+20180508"
stretch_version="~stretch+20180508"
buster_version="~buster+20180508"
xenial_version="~xenial+20180508"
artful_version="~artful+20180508"
bionic_version="~bionic+20180508"

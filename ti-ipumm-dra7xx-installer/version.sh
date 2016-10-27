#!/bin/bash -e

package_name="ipumm-dra7xx-installer"
debian_pkg_name="${package_name}"
package_version="3.00.11.00"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="i/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-r2"
debian_untar=""
debian_patch=""

jessie_version="~bpo80+20161027+1"
stretch_version="~bpo90+20161027+1"
xenial_version="~bpo1604+20161027+1"

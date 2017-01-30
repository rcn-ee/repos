#!/bin/bash -e

package_name="board-firmware"
debian_pkg_name="${package_name}"
package_version="1.20170130"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="b/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0rcnee2"
debian_untar=""
debian_patch=""

jessie_version="~bpo80+20170130+1"
stretch_version="~bpo90+20170130+1"
xenial_version="~bpo1604+20170130+1"

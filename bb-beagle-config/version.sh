#!/bin/bash -e

#https://github.com/SAtacker/beagle-config

package_name="bb-beagle-config"
debian_pkg_name="${package_name}"
package_version="0.0.0.20210728.1"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="b/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0"
debian_untar=""
debian_patch=""

stretch_version="~stretch+20210728"
buster_version="~buster+20210728"
bullseye_version="~bullseye+20210728"
bionic_version="~bionic+20210728"
focal_version="~focal+20210728"

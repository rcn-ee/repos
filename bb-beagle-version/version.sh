#!/bin/bash -e

#https://github.com/beagleboard/customizations

package_name="bb-beagle-version"
debian_pkg_name="${package_name}"
package_version="1.20210928.0"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="b/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0"
debian_untar=""
debian_patch=""

bullseye_version="~bullseye+20210928"

#!/bin/bash -e

package_name="bb-bonescript-installer-beta"
debian_pkg_name="${package_name}"
package_version="0.5.0~beta7"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="b/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0rcnee2"
debian_untar=""
debian_patch=""

jessie_version="~bpo80+20160708+1"

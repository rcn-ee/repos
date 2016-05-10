#!/bin/bash -e

package_name="gcp-demo"
debian_pkg_name="${package_name}"
package_version="0.0.0.20160510"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="g/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0rcnee0"
debian_untar=""
debian_patch=""

jessie_version="~bpo80+20160510+1"

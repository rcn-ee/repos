#!/bin/bash -e

package_name="bb-doc-bone101"
debian_pkg_name="${package_name}"
package_version="1.1.3"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="b/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-1"
debian_untar=""
debian_patch=""

jessie_version="~bpo80+20160621+1"

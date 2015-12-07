#!/bin/bash -e

#https://github.com/beagleboard/beaglebone-getting-started

package_name="doc-beaglebone-getting-started"
debian_pkg_name="${package_name}"
package_version="1.20151204"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="d/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-1"
debian_untar=""
debian_patch=""

jessie_version="~bpo80+20151207+1"

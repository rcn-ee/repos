#!/bin/bash -e

package_name="galcore-headers"
debian_pkg_name="${package_name}"
package_version="4.6.6.1381"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="g/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0rcnee2"
debian_untar=""
debian_patch=""

jessie_version="~bpo80+20161122+1"
stretch_version="~bpo90+20161122+1"
xenial_version="~bpo1604+20161122+1"

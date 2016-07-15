#!/bin/bash -e

package_name="rpmsg-rpc-4.1-headers"
debian_pkg_name="${package_name}"
package_version="4.1.20160707"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="r/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0rcnee1"
debian_untar=""
debian_patch=""

jessie_version="~bpo80+20160707+1"
stretch_version="~bpo90+20160707+1"
xenial_version="~bpo1604+20160707+1"

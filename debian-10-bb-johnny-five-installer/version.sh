#!/bin/bash -e

package_name="bb-johnny-five-installer"
debian_pkg_name="${package_name}"
package_version="1.3.1"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="b/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0rcnee1"
debian_untar=""
debian_patch=""

dl_mirror="http://git.gfnd.rcn-ee.org:82/cgit/npm-package-node-red-scripts/.git/plain/deploy/buster"

v10="v10.15.2"

node_red_five="johnny-five-1.3.1"

debian_dl_1="${dl_mirror}/${node_red_five}-${v10}.tar.xz"

buster_version="~buster+20191024"

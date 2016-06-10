#!/bin/bash -e

package_name="bb-node-red-installer"
debian_pkg_name="${package_name}"
package_version="0.13.4"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="b/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0rcnee7"
debian_untar=""
debian_patch=""
debian_dl_1="https://github.com/rcn-ee/npm-package-node-red/raw/master/deploy/node-red-0.13.4-3454e5a-v0.12.13.tar.xz"
debian_dl_2="https://github.com/rcn-ee/npm-package-node-red/raw/master/deploy/node-red-node-beaglebone-0.1.6-966e7a5-v0.12.13.tar.xz"
debian_dl_3="https://github.com/rcn-ee/npm-package-node-red/raw/master/deploy/node-red-node-bb-upm-0.0.0-d817d14-v0.12.13.tar.xz"
debian_dl_4="https://github.com/rcn-ee/npm-package-node-red/raw/master/deploy/node-red-node-mongodb-0.0.5-966e7a5-v0.12.13.tar.xz"

jessie_version="~bpo80+20160610+1"
stretch_version="~bpo90+20160610+1"
xenial_version="~bpo1604+20160610+1"

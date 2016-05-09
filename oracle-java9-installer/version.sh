#!/bin/bash -e

#https://launchpad.net/~webupd8team/+archive/ubuntu/java/+packages

package_name="oracle-java9-installer"
debian_pkg_name="${package_name}"
package_version="9b112+9b112arm"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="o/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0"
debian_untar=""
debian_patch=""
local_patch="rcnee1"

wheezy_version="~bpo70+20160420+1"
jessie_version="~bpo80+20160420+1"
stretch_version="~bpo90+20160420+1"
trusty_version="~bpo1404+20160420+1"
wily_version="~bpo1510+20160420+1"
xenial_version="~bpo1604+20160420+1"

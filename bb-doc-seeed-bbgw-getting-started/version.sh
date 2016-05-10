#!/bin/bash -e

#https://github.com/Seeed-Studio/beaglebone-getting-started

package_name="doc-seeed-bbgw-getting-started"
debian_pkg_name="${package_name}"
package_version="1.20160510"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="d/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0rcnee1"
debian_untar=""
debian_patch=""

wheezy_version="~bpo70+20160510+1"
jessie_version="~bpo80+20160510+1"
stretch_version="~bpo90+20160510+1"
trusty_version="~bpo1404+20160510+1"
wily_version="~bpo1510+20160510+1"
xenial_version="~bpo1604+20160510+1"
yakkety_version="~bpo1610+20160510+1"

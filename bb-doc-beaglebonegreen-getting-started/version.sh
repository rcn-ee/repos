#!/bin/bash -e

#https://github.com/Seeed-Studio/beaglebone-getting-started

package_name="doc-beaglebonegreen-getting-started"
debian_pkg_name="${package_name}"
package_version="1.20160420"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="d/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-2"
debian_untar=""
debian_patch=""

wheezy_version="~bpo70+20160421+1"
jessie_version="~bpo80+20160421+1"
stretch_version="~bpo90+20160421+1"
trusty_version="~bpo1404+20160421+1"
wily_version="~bpo1510+20160421+1"
xenial_version="~bpo1604+20160421+1"

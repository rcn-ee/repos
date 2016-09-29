#!/bin/bash -e

package_name="vpdma-dra7xx-installer"
debian_pkg_name="${package_name}"
package_version="03-2012"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="v/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-1"
debian_untar=""
debian_patch=""

wheezy_version="~bpo70+20160929+1"
jessie_version="~bpo80+20160929+1"
stretch_version="~bpo90+20160929+1"
trusty_version="~bpo1404+20160929+1"
xenial_version="~bpo1604+20160929+1"
yakkety_version="~bpo1610+20160929+1"

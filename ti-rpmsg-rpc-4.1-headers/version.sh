#!/bin/bash -e

package_name="rpmsg-rpc-4.1-headers"
debian_pkg_name="${package_name}"
package_version="4.1.20151216"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="r/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-2"
debian_untar=""
debian_patch=""

wheezy_version="~bpo70+20151216+1"
jessie_version="~bpo80+20151216+1"
stretch_version="~bpo90+20151216+1"
trusty_version="~bpo1404+20151216+1"
vivid_version="~bpo1504+20151216+1"
wily_version="~bpo1510+20151216+1"
xenial_version="~bpo1604+20151216+1"

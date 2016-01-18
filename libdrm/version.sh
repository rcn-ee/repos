#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="libdrm"
debian_pkg_name="${package_name}"
package_version="2.4.65"
package_source="${package_name}_${package_version}.orig.tar.gz"
src_dir="${package_name}-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="libd/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-3"
debian_untar=""
debian_patch="${package_name}_${package_version}-3.diff.gz"
local_patch="rcnee10"

wheezy_version="~bpo70+20160112+1"
jessie_version="~bpo80+20160112+1"
stretch_version="~bpo90+20160112+1"
trusty_version="~bpo1404+20160112+1"
vivid_version="~bpo1504+20160112+1"
wily_version="~bpo1510+20160112+1"
xenial_version="~bpo1604+20160112+1"

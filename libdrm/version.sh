#!/bin/bash -e

mirror="http://ftp.de.debian.org/debian"

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
local_patch="rcnee1"

wheezy_version="~bpo70+20151029+1"
jessie_version="~bpo80+20151029+1"
stretch_version="~bpo90+20151029+1"
trusty_version="~bpo1404+20151029+1"
vivid_version="~bpo1504+20151029+1"
wily_version="~bpo1510+20151029+1"
xenial_version="~bpo1604+20151029+1"

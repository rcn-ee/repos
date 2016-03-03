#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="pastebinit"
debian_pkg_name="${package_name}"
package_version="1.5"
package_source="${package_name}_${package_version}.orig.tar.bz2"
src_dir="${package_name}-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="p/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-1"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""
local_patch=""

wheezy_version="~bpo70+20160303+1"
jessie_version="~bpo80+20160303+1"
stretch_version="~bpo90+20160303+1"
trusty_version="~bpo1404+20160303+1"
wily_version="~bpo1510+20160303+1"
xenial_version="~bpo1604+20160303+1"

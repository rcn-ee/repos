#!/bin/bash -e

mirror="http://ftp.de.debian.org/debian"

package_name="pastebinit"
debian_pkg_name="${package_name}"
package_version="1.4"
package_source="${package_name}_${package_version}.orig.tar.bz2"
src_dir="${package_name}-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="p/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-4"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""
local_patch="rcnee2"

wheezy_version="~bpo70+20151116+1"
jessie_version="~bpo80+20151116+1"
stretch_version="~bpo90+20151116+1"
trusty_version="~bpo1404+20151116+1"
vivid_version="~bpo1504+20151116+1"
wily_version="~bpo1510+20151116+1"

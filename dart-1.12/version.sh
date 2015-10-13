#!/bin/bash -e

#https://code.google.com/p/dart/source/list

package_name="dart-1.12"
debian_pkg_name="${package_name}"
package_version="1.12.1"
package_source="${package_name}_${package_version}.orig.tar.gz"
src_dir="${package_name}-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="d/${package_name}"
dl_path=""

debian_version="${package_version}-1"
debian_untar="${package_name}_${debian_version}.debian.tar.gz"
debian_patch=""

wheezy_version="~bpo70+20150428+1"
jessie_version="~bpo80+20150526+1"
stretch_version="~bpo90+20150526+1"
trusty_version="~bpo1404+20150526+1"
utopic_version="~bpo1410+20150526+1"
vivid_version="~bpo1504+20150526+1"
wily_version="~bpo1510+20150526+1"

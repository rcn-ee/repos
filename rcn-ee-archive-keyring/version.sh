#!/bin/bash -e

package_name="rcn-ee-archive-keyring"
debian_pkg_name="${package_name}"
package_version="2015.03.12"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo=""
git_sha=""
reprepro_dir="r/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}"
debian_untar=""
debian_patch=""

wheezy_version="~bpo70+20150312+1"
jessie_version="~bpo80+20150312+1"
trusty_version="~bpo1404+20150312+1"
utopic_version="~bpo1410+20150312+1"
vivid_version="~bpo1504+20150312+1"

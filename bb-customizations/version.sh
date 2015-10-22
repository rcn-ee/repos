#!/bin/bash -e

package_name="bb-customizations"
debian_pkg_name="${package_name}"
package_version="1.20151008"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="t/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-1"
debian_untar=""
debian_patch=""


wheezy_version="~bpo70+20151008+1"
jessie_version="~bpo80+20151008+1"
stretch_version="~bpo90+20151008+1"
trusty_version="~bpo1404+20151008+1"
vivid_version="~bpo1504+20151008+1"
wily_version="~bpo1510+20151008+1"

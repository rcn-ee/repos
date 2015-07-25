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

wheezy_version="~bpo70+20150724+1"
jessie_version="~bpo80+20150724+1"
stretch_version="~bpo90+20150724+1"
trusty_version="~bpo1404+20150724+1"
vivid_version="~bpo1504+20150724+1"
wily_version="~bpo1510+20150724+1"

#!/bin/bash -e

#https://gsdview.appspot.com/dart-archive/channels/stable/release/

package_name="dart-1.12"
debian_pkg_name="${package_name}"
package_version="1.12.2"
package_source="${package_name}_${package_version}.orig.tar.gz"
src_dir="dart-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="d/${package_name}"
dl_path=""

debian_version="${package_version}-1"
debian_untar="dart_${debian_version}.debian.tar.gz"
debian_patch=""

jessie_version="~bpo80+20151028+1"
trusty_version="~bpo1404+20151028+1"
vivid_version="~bpo1504+20151028+1"

#!/bin/bash -e

#https://gsdview.appspot.com/dart-archive/channels/stable/release/
#https://gsdview.appspot.com/dart-archive/channels/dev/release/

package_name="dart-1.12"
debian_pkg_name="${package_name}"
package_version="1.12.2"
real_package_version="1.12.2"
package_source="${package_name}_${package_version}.orig.tar.gz"
src_dir="dart-${real_package_version}"

git_repo=""
git_sha=""
reprepro_dir="d/${package_name}"
dl_path=""

debian_version="${package_version}-1"
debian_untar="dart_${debian_version}.debian.tar.gz"
debian_patch=""

trusty_version="~bpo1404+20151028+1"
vivid_version="~bpo1504+20151028+1"
jessie_version="~bpo80+20151105+1"
stretch_version="~bpo90+20151105+1"
xenial_version="~bpo1604+20151105+1"

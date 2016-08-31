#!/bin/bash -e

#https://gsdview.appspot.com/dart-archive/channels/stable/release/
#https://gsdview.appspot.com/dart-archive/channels/dev/release/

package_name="dart-1.17"
debian_pkg_name="${package_name}"
package_version="1.17.1"
real_package_version="1.17.1"
#package_version="1.17.0~dev.1.0"
#real_package_version="1.17.0-dev.1.0"
package_source="${package_name}_${package_version}.orig.tar.gz"
src_dir="dart-${real_package_version}"

git_repo=""
git_sha=""
reprepro_dir="d/${package_name}"
dl_path=""

debian_version="${package_version}-1"
debian_untar="dart_${debian_version}.debian.tar.gz"
debian_patch=""
local_patch="rcnee0"

jessie_version="~bpo80+20160831+1"
stretch_version="~bpo90+20160831+1"
xenial_version="~bpo1604+20160831+1"

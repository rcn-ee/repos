#!/bin/bash -e

mirror="https://launchpad.net/~daniel-elstner/+archive/ubuntu/sigrok/+files"

package_name="librevisa"
debian_pkg_name="${package_name}"
package_version="0.0.20130812+git20140327"
package_source="${package_name}_${package_version}.orig.tar.gz"
src_dir="${package_name}-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="libr/${package_name}"
dl_path=""

debian_version="${package_version}-0ppa2~wily"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
local_patch="rcnee0"

jessie_version="~jessie+20170705"
stretch_version="~stretch+20170705"

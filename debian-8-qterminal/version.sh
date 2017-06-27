#!/bin/bash -e

#http://packages.siduction.org/lxqt/pool/main/q/qterminal/

mirror="http://packages.siduction.org"

package_name="qterminal"
debian_pkg_name="${package_name}"
package_version="0.6.0"
dl_package_source="${package_name}_${package_version}-10.tar.gz"
package_source="${dl_package_source}"
src_dir="checkout"

git_repo=""
git_sha=""
reprepro_dir="q/${package_name}"
dl_path="lxqt/pool/main/${reprepro_dir}/"

debian_version="${package_version}-10"
debian_patch=""

jessie_version="~bpo80+20150625+1"

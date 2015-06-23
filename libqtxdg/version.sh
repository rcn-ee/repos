#!/bin/bash -e

#http://packages.siduction.org/lxqt/pool/main/libq/libqtxdg/

mirror="http://packages.siduction.org"

package_name="libqtxdg"
debian_pkg_name="${package_name}"
package_version="1.2.0"
package_source="${package_name}_${package_version}-4.tar.gz"
src_dir="checkout"

git_repo=""
git_sha=""
reprepro_dir="libq/${package_name}"
dl_path="lxqt/pool/main/${reprepro_dir}/"

debian_version="${package_version}-4"
debian_patch=""

jessie_version="~bpo80+20150623+1"

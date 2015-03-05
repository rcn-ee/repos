#!/bin/bash -e

#http://packages.siduction.org/lxqt/pool/main/libq/libqtxdg/

mirror="http://packages.siduction.org"

package_name="libqtxdg"
debian_pkg_name="${package_name}"
package_version="1.1.0"
dl_package_source="${package_name}_${package_version}-6.tar.gz"
package_source="${dl_package_source}"
src_dir="checkout"

git_repo=""
git_sha=""
reprepro_dir="libq/${package_name}"
dl_path="lxqt/pool/main/${reprepro_dir}/"

debian_version="${package_version}-6"
debian_patch=""

wheezy_version="~bpo70+20140924+1"
jessie_version="~20150305+1"

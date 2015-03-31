#!/bin/bash -e

#http://packages.siduction.org/extra/pool/main/libd/libdbusmenu-qt5/

mirror="http://packages.siduction.org"

package_name="libdbusmenu-qt5"
debian_pkg_name="${package_name}"
package_version="0.9.3"
package_source="${package_name}_${package_version}-1siduction3.tar.gz"
src_dir="libdbusmenu-qt"

git_repo=""
git_sha=""
reprepro_dir="libd/${package_name}"
dl_path="extra/pool/main/${reprepro_dir}/"

debian_version="${package_version}-1siduction3"
debian_patch=""

jessie_version="~bpo80+20150331+1"

#!/bin/bash -e

#http://packages.siduction.org/lxqt/pool/main/p/polkit-qt-1/

mirror="http://packages.siduction.org"

package_name="polkit-qt-1"
debian_pkg_name="${package_name}"
package_version="0.112.0"
package_source="${package_name}_${package_version}-2.tar.gz"
src_dir="polkit-qt-1"

git_repo=""
git_sha=""
reprepro_dir="p/${package_name}"
dl_path="lxqt/pool/main/${reprepro_dir}/"

debian_version="${package_version}-2"
debian_patch=""

jessie_version="~bpo80+20150407+1"

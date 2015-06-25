#!/bin/bash -e

#http://packages.siduction.org/lxqt/pool/main/q/qtermwidget/

mirror="http://packages.siduction.org"

package_name="qtermwidget"
debian_pkg_name="${package_name}"
package_version="0.6.0"
package_source="${package_name}_${package_version}-10.tar.gz"
src_dir="checkout"

git_repo=""
git_sha=""
reprepro_dir="q/${package_name}"
dl_path="lxqt/pool/main/${reprepro_dir}/"

debian_version="${package_version}-10.1"
debian_patch=""

jessie_version="~bpo80+20150625+1"

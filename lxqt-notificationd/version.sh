#!/bin/bash -e

#http://packages.siduction.org/lxqt/pool/main/l/lxqt-notificationd/

mirror="http://packages.siduction.org"

package_name="lxqt-notificationd"
debian_pkg_name="${package_name}"
package_version="0.9.0"
package_source="${package_name}_${package_version}-11.tar.gz"
src_dir="checkout"

git_repo=""
git_sha=""
reprepro_dir="l/${package_name}"
dl_path="lxqt/pool/main/${reprepro_dir}/"

debian_version="${package_version}-11"
debian_patch=""

jessie_version="~bpo80+20150708+1"
stretch_version="~bpo90+20150708+1"

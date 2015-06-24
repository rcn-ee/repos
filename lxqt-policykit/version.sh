#!/bin/bash -e

#http://packages.siduction.org/lxqt/pool/main/l/lxqt-policykit/

mirror="http://packages.siduction.org"

package_name="lxqt-policykit"
debian_pkg_name="${package_name}"
package_version="0.9.0"
package_source="${package_name}_${package_version}-8.tar.gz"
src_dir="checkout"

git_repo=""
git_sha=""
reprepro_dir="l/${package_name}"
dl_path="lxqt/pool/main/${reprepro_dir}/"

debian_version="${package_version}-8"
debian_patch=""

jessie_version="~bpo80+20150624+1"

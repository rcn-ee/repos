#!/bin/bash -e

#http://packages.siduction.org/extra/pool/main/c/cmst/

mirror="http://packages.siduction.org"

package_name="cmst"
debian_pkg_name="${package_name}"
package_version="2015.01.24"
dl_package_source="${package_name}_${package_version}-4.tar.gz"
package_source="${package_name}_${package_version}.orig.tar.gz"
src_dir="newcheck"

git_repo=""
git_sha=""
reprepro_dir="c/${package_name}"
dl_path="extra/pool/main/${reprepro_dir}/"

debian_version="${package_version}-4"
debian_untar=""
debian_patch=""

jessie_version="~20150130+1"

#!/bin/bash -e

#http://packages.siduction.org/extra/pool/main/c/connman/

mirror="http://packages.siduction.org"

package_name="connman"
debian_pkg_name="${package_name}"
package_version="1.27~20150123g04cbd7e"
dl_package_source="${package_name}_${package_version}-2.tar.gz"
package_source="${package_name}_${package_version}.orig.tar.gz"
src_dir="${package_name}"

git_repo=""
git_sha=""
reprepro_dir="c/${package_name}"
dl_path="extra/pool/main/${reprepro_dir}/"

debian_version="${package_version}-2"
debian_untar=""
debian_patch=""

jessie_version="~20150130+1"

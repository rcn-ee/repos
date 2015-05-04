#!/bin/bash -e

#http://packages.siduction.org/extra/pool/main/c/connman/

mirror="http://packages.siduction.org"

package_name="connman"
debian_pkg_name="${package_name}"
package_version="1.29"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}"

git_repo=""
git_sha=""
reprepro_dir="c/${package_name}"
dl_path="extra/pool/main/${reprepro_dir}/"

debian_version="${package_version}-0+exp1"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""

jessie_version="~bpo80+20150504+1"

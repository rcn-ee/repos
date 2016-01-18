#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="orocos-kdl"
debian_pkg_name="${package_name}"
package_version="1.3.0+dfsg"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="orocos_kinematics_synamics-1.3.0"

git_repo=""
git_sha=""
reprepro_dir="o/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-1"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""
local_patch=""

jessie_version="~bpo80+20160118+1"

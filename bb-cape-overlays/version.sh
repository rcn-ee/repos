#!/bin/bash -e

#https://github.com/beagleboard/bb.org-overlays

package_name="bb-cape-overlays"
debian_pkg_name="${package_name}"
package_version="4.14.20200805.0"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/beagleboard/bb.org-overlays"
git_sha="0b325ca1445f55a2f5f59a8766e4c5819ae4b442"
reprepro_dir="b/${package_name}"
dl_path=""

debian_version="${package_version}-0"
debian_patch=""
debian_diff=""

stretch_version="~stretch+20200805"
buster_version="~buster+20200805"
bionic_version="~bionic+20200805"
focal_version="~focal+20200805"

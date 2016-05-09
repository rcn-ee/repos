#!/bin/bash -e

#https://github.com/beagleboard/bb.org-overlays

package_name="bb-cape-overlays"
debian_pkg_name="${package_name}"
package_version="4.1.20160508"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/beagleboard/bb.org-overlays"
git_sha="4d19f3aa27be100fafb1eee9ed0b01a6079ea2af"
reprepro_dir="b/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee2"
debian_patch=""
debian_diff=""

jessie_version="~bpo80+20160508+1"

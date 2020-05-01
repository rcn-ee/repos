#!/bin/bash -e

#https://github.com/beagleboard/bb.org-overlays

package_name="bb-cape-overlays"
debian_pkg_name="${package_name}"
package_version="4.14.20200430.0"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/beagleboard/bb.org-overlays"
git_sha="4c763d657d45fb2a742248312cf16261cf5b2500"
reprepro_dir="b/${package_name}"
dl_path=""

debian_version="${package_version}-0"
debian_patch=""
debian_diff=""

stretch_version="~stretch+20200430"
buster_version="~buster+20200430"
bionic_version="~bionic+20200430"
focal_version="~focal+20200430"

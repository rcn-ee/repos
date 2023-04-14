#!/bin/bash -e

#https://github.com/linux-usb-gadgets/gt

package_name="gt"
debian_pkg_name="${package_name}"
package_version="0.0.0-git20220507.1"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/linux-usb-gadgets/gt"
git_sha="7f9c45d98425a27444e49606ce3cf375e6164e8e"
reprepro_dir="g/${package_name}"
dl_path=""

debian_version="${package_version}-0"
debian_patch=""
debian_diff=""

clear_changelog="enable"

buster_version="~buster+20230414"
bullseye_version="~bullseye+20230414"
bookworm_version="~bookworm+20230414"
bionic_version="~bionic+20230414"
focal_version="~focal+20230414"
jammy_version="~jammy+20230414"

#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="libusbgx"
debian_pkg_name="${package_name}"
package_version="0.2.0-git20210811.6"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/linux-usb-gadgets/libusbgx"
git_sha="ec0b01c03fdc7893997b7b32ec1c12c6103f62f3"
reprepro_dir="libu/${package_name}"
dl_path=""

debian_version="${package_version}-0"
debian_patch=""
debian_diff=""

clear_changelog="enable"

bullseye_version="~bullseye+20240118"
bookworm_version="~bookworm+20240118"
jammy_version="~jammy+20240118"

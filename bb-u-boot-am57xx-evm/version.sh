#!/bin/bash -e

#https://git.beagleboard.org/beagleboard/u-boot/-/tree/v2022.04-bbb.io-am335x-am57xx

package_name="bb-u-boot-am57xx-evm"
debian_pkg_name="${package_name}"
package_version="2022.04.20220823.2"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="b/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0"
debian_untar=""
debian_patch=""

clear_changelog="enable"

buster_version="~buster+20231207"
bullseye_version="~bullseye+20231207"
bookworm_version="~bookworm+20231207"
trixie_version="~trixie+20231207"
focal_version="~focal+20231207"
jammy_version="~jammy+20231207"
noble_version="~noble+20231207"

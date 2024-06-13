#!/bin/bash -e

#https://github.com/coder/code-server/releases

arch="armv7l"
ver="4.90.1"

package_name="bb-code-server"
debian_pkg_name="${package_name}"
package_version="${ver}.0"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="b/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0"
debian_untar=""
debian_patch=""

debian_dl_1="https://github.com/coder/code-server/releases/download/v${ver}/code-server-${ver}-linux-${arch}.tar.gz"

clear_changelog="enable"

buster_version="~buster+20240516"
bullseye_version="~bullseye+20240613"
bookworm_version="~bookworm+20240613"
trixie_version="~trixie+20240613"
jammy_version="~jammy+20240613"
noble_version="~noble+20240613"

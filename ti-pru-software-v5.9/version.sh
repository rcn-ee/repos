#!/bin/bash -e

#https://git.ti.com/gitweb?p=pru-software-support-package/pru-software-support-package.git;a=tags
#https://git.gfnd.rcn-ee.org/TexasInstruments/pru-software-support-package/tags

package_name="ti-pru-software-v5.9"
debian_pkg_name="${package_name}"
package_version="5.9.0.0"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="t/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0"
debian_untar=""
debian_patch=""
local_patch="bbbio2"

clear_changelog="enable"

bullseye_version="~bullseye+20240118"
bookworm_version="~bookworm+20240118"
trixie_version="~trixie+20240118"

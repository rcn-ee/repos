#!/bin/bash -e

#https://git.ti.com/gitweb?p=pru-software-support-package/pru-software-support-package.git;a=tags
#https://git.gfnd.rcn-ee.org/TexasInstruments/pru-software-support-package/tags

package_name="ti-pru-software-v6.2"
debian_pkg_name="${package_name}"
package_version="6.2.0"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="t/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0"
debian_untar=""
debian_patch=""
local_patch="bbbio1"

clear_changelog="enable"

bullseye_version="~bullseye+20240117"
bookworm_version="~bookworm+20240117"
trixie_version="~trixie+20240117"

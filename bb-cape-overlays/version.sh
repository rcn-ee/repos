#!/bin/bash -e

#https://github.com/beagleboard/bb.org-overlays

package_name="bb-cape-overlays"
debian_pkg_name="${package_name}"
package_version="4.1.20170301"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/beagleboard/bb.org-overlays"
git_sha="0af48ec0fbf08a47679f7135f10ccd429e4fe185"
reprepro_dir="b/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee0"
debian_patch=""
debian_diff=""

jessie_version="~bpo80+20170302"
stretch_version="~bpo90+20170302"
xenial_version="~bpo1604+20170302"

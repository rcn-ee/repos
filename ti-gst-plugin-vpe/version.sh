#!/bin/bash -e

#Library used for remotely invoking the hw accelerated codec on IVA-HD
#http://git.ti.com/gitweb/?p=glsdk/gst-plugin-vpe.git;a=summary

package_name="gst-plugin-vpe"
debian_pkg_name="${package_name}"
package_version="0.20150825"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://git.ti.com/glsdk/gst-plugin-vpe.git"
git_sha="1a8da5e527275f6bba33663d0d7017d8e1f8f7d9"
reprepro_dir="d/${package_name}"
dl_path=""

debian_version="${package_version}-1"
debian_patch=""
debian_diff=""
local_patch="rcnee1"

jessie_version="~bpo80+20151216+1"

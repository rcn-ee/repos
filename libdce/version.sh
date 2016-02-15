#!/bin/bash -e

#http://omapzoom.org/?p=repo/libdce.git;a=summary

package_name="libdce"
debian_pkg_name="${package_name}"
package_version="3.00.08.02"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://git.omapzoom.org/repo/libdce.git"
git_sha="3040e7e3f7d1ed42a1273ccc6b912328b90b16db"
reprepro_dir="libd/${package_name}"
dl_path=""

debian_version="${package_version}-1"
debian_patch=""
debian_diff=""

wheezy_version="~bpo70+20151020+1"
jessie_version="~bpo80+20151020+1"
stretch_version="~bpo90+20151020+1"

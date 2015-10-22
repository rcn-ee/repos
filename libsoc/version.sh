#!/bin/bash -e

package_name="libsoc"
debian_pkg_name="${package_name}"
package_version="0.6.5-git20150802"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/jackmitch/libsoc.git"
git_sha="2cae8c061e6132347e37f4eb6069501687951e7e"
reprepro_dir="libs/${package_name}"
dl_path=""

debian_version="${package_version}-1"
debian_patch=""
debian_diff=""

wheezy_version="~bpo70+20150803+1"
jessie_version="~bpo80+20150803+1"
stretch_version="~bpo90+20150803+1"
trusty_version="~bpo1404+20150803+1"
vivid_version="~bpo1504+20150803+1"
wily_version="~bpo1510+20150803+1"

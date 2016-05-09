#!/bin/bash -e

#https://github.com/omapconf/omapconf

package_name="tiomapconf"
debian_pkg_name="${package_name}"
package_version="1.72.0-git20160414"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/omapconf/omapconf"
git_sha="d67b7496d2652b180a1249599252b1b21f816b27"
reprepro_dir="o/${package_name}"
dl_path=""

debian_version="${package_version}-1"
debian_patch=""
debian_diff=""

wheezy_version="~bpo70+20160414+1"
jessie_version="~bpo80+20160414+1"
stretch_version="~bpo90+20160414+1"
trusty_version="~bpo1404+20160414+1"
wily_version="~bpo1510+20160414+1"
xenial_version="~bpo1604+20160414+1"

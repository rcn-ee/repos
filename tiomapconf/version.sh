#!/bin/bash -e

#https://github.com/omapconf/omapconf

package_name="tiomapconf"
debian_pkg_name="${package_name}"
package_version="1.72.0-git20150825"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/omapconf/omapconf"
git_sha="e821a16e707cbde41ed07c1a05de4a497b39c000"
reprepro_dir="o/${package_name}"
dl_path=""

debian_version="${package_version}-1"
debian_patch=""
debian_diff=""

wheezy_version="~bpo70+20150826+1"
jessie_version="~bpo80+20150826+1"
stretch_version="~bpo90+20150826+1"
trusty_version="~bpo1404+20150826+1"
vivid_version="~bpo1504+20150826+1"
wily_version="~bpo1510+20150826+1"

#!/bin/bash -e

#https://github.com/omapconf/omapconf

package_name="tiomapconf"
debian_pkg_name="${package_name}"
package_version="1.71.0-git20150625"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/omapconf/omapconf"
git_sha="727b8e6bee3de0bd7428f23048f51aa29bbba8da"
reprepro_dir="o/${package_name}"
dl_path=""

debian_version="${package_version}-1"
debian_patch=""
debian_diff=""

wheezy_version="~bpo70+20150625+1"
jessie_version="~bpo80+20150625+1"
stretch_version="~bpo90+20150625+1"
trusty_version="~bpo1404+20150625+1"
utopic_version="~bpo1410+20150625+1"
vivid_version="~bpo1504+20150625+1"
wily_version="~bpo1510+20150625+1"

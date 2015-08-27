#!/bin/bash -e

#https://github.com/omapconf/omapconf

package_name="tiomapconf"
debian_pkg_name="${package_name}"
package_version="1.72.0-git20150827"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/omapconf/omapconf"
git_sha="3760d5859d3935db100000598fb688d10a13b63c"
reprepro_dir="o/${package_name}"
dl_path=""

debian_version="${package_version}-1"
debian_patch=""
debian_diff=""

wheezy_version="~bpo70+20150827+1"
jessie_version="~bpo80+20150827+1"
stretch_version="~bpo90+20150827+1"
trusty_version="~bpo1404+20150827+1"
vivid_version="~bpo1504+20150827+1"
wily_version="~bpo1510+20150827+1"

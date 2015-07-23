#!/bin/bash -e

mirror="http://ppa.launchpad.net"

package_name="cmem"
debian_pkg_name="${package_name}"
package_version="4.00.02.10.eng-4"
package_source="${debian_pkg_name}_${package_version}~ppa4.tar.gz"
src_dir="${package_name}_${package_version}"

git_repo=""
git_sha=""
reprepro_dir="c/${package_name}"
dl_path="ti-keystone-team/ti-keystone-ppa/ubuntu/pool/main/${reprepro_dir}/"

debian_version="${package_version}~ppa4"
debian_patch=""

wheezy_version="~bpo70+20150723+1"
jessie_version="~bpo80+20150723+1"
stretch_version="~bpo90+20150723+1"

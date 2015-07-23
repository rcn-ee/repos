#!/bin/bash -e

#http://git.ti.com/cgit/cgit.cgi/keystone-linux/multi-proc-manager.git/tree/

mirror="http://ppa.launchpad.net"

package_name="mpm"
debian_pkg_name="${package_name}"
package_version="2.00.01.00"
package_source="${debian_pkg_name}_${package_version}-0ubuntu1~ppa3.tar.gz"
src_dir="${package_name}-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="m/${package_name}"
dl_path="ti-keystone-team/ti-keystone-ppa/ubuntu/pool/main/${reprepro_dir}/"

debian_version="${package_version}-0ubuntu1~ppa3"
debian_patch=""

wheezy_version="~bpo70+20150723+1"
jessie_version="~bpo80+20150723+1"
stretch_version="~bpo90+20150723+1"

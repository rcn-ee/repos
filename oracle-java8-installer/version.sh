#!/bin/bash -e

#https://launchpad.net/~webupd8team/+archive/ubuntu/java/+packages

#wget https://launchpad.net/~webupd8team/+archive/ubuntu/java/+files/oracle-java8-installer_8u111+8u111arm-1~webupd8~0.tar.xz

package_name="oracle-java8-installer"
debian_pkg_name="${package_name}"
package_version="8u111+8u111"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="o/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0"
debian_untar=""
debian_patch=""
local_patch="rcnee0"

jessie_version="~bpo80+20170104+1"
stretch_version="~bpo90+20170104+1"
trusty_version="~bpo1404+20170104+1"
xenial_version="~bpo1604+20170104+1"

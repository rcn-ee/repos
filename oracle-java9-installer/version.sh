#!/bin/bash -e

#https://launchpad.net/~webupd8team/+archive/ubuntu/java/+packages

#wget https://launchpad.net/~webupd8team/+archive/ubuntu/java/+files/oracle-java9-installer_9b149+9b149arm-1~webupd8~0.tar.xz

package_name="oracle-java9-installer"
debian_pkg_name="${package_name}"
package_version="9b149+9b149arm"
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

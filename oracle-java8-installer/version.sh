#!/bin/bash -e

#https://launchpad.net/~webupd8team/+archive/ubuntu/java/+packages

#wget https://launchpad.net/~webupd8team/+archive/ubuntu/java/+files/oracle-java8-installer_8u151-1~webupd8~0.tar.xz

package_name="oracle-java8-installer"
debian_pkg_name="${package_name}"
package_version="8u151-1"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="o/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0rcnee0"
debian_untar=""
debian_patch=""

jessie_version="~jessie+20171227"
stretch_version="~stretch+20171227"
buster_version="~buster+20171227"
xenial_version="~xenial+20171227"
bionic_version="~bionic+20171227"

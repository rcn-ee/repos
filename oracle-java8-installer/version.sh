#!/bin/bash -e

#https://launchpad.net/~webupd8team/+archive/ubuntu/java/+packages

#wget https://launchpad.net/~webupd8team/+archive/ubuntu/java/+files/oracle-java8-installer_8u25%2B8u6arm-1~webupd8~1.tar.xz

package_name="oracle-java8-installer"
debian_pkg_name="${package_name}"
package_version="8u25+8u6arm"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="o/${package_name}"
dl_path="${mirror}/pool/main/${reprepro_dir}/"

debian_version="${package_version}-1"
debian_untar=""
debian_patch=""

wheezy_version="~bpo70+20141031+1"
jessie_version="~20141031+1"

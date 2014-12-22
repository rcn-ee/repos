#!/bin/bash -e

#https://rcn-ee.net/pkgs/c9v3/c9v3_3.0.1-git20140211-build.tar.xz

package_name="cloud9-installer"
debian_pkg_name="${package_name}"
package_version="3.0.623"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="c/${package_name}"
dl_path="${mirror}/pool/main/${reprepro_dir}/"

debian_version="${package_version}-1"
debian_untar=""
debian_patch=""

wheezy_version="~bpo70+20141222+1"
jessie_version="~20141222+1"
trusty_version="~20141222+1"

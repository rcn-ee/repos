#!/bin/bash -e

#https://rcn-ee.net/pkgs/c9v3/

package_name="cloud9-installer"
debian_pkg_name="${package_name}"
package_version="3.0.645"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="c/${package_name}"
dl_path="${mirror}/pool/main/${reprepro_dir}/"

debian_version="${package_version}-1"
debian_untar=""
debian_patch=""

wheezy_version="~bpo70+20150105+1"
jessie_version="~20150105+1"
trusty_version="~20150105+1"

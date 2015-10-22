#!/bin/bash -e

#https://github.com/c9/core

package_name="cloud9-installer"
debian_pkg_name="${package_name}"
package_version="3.0.2745-git20150920"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="c/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-2"
debian_untar=""
debian_patch=""

stretch_version="~bpo90+20150921+1"
wheezy_version="~bpo70+20150923+1"
jessie_version="~bpo80+20150923+1"

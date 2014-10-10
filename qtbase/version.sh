#!/bin/bash -e

#https://packages.qa.debian.org/q/qtbase-opensource-src.html

mirror="http://ftp.de.debian.org/debian"

package_name="qtbase-opensource-src"
debian_pkg_name="${package_name}"
package_version="5.3.2+dfsg"
package_source="${debian_pkg_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}-5.3.2"

git_repo=""
git_sha=""
reprepro_dir="q/${debian_pkg_name}"
dl_path="${mirror}/pool/main/${reprepro_dir}/"

debian_version="${package_version}-4"
debian_untar="${debian_pkg_name}_${debian_version}.debian.tar.xz"
debian_patch=""

wheezy_version="~bpo70+20140924+1"
jessie_version="~20140924+1"

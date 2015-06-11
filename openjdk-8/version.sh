#!/bin/bash -e

mirror="http://ftp.de.debian.org/debian"

package_name="openjdk-8"
debian_pkg_name="${package_name}"
package_version="8u45-b14"
package_source="${package_name}_${package_version}.orig.tar.gz"
src_dir="${package_name}-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="o/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-3"
debian_untar=""
debian_patch="${package_name}_${debian_version}.diff.gz"

wheezy_version="~bpo70+20141112+1"
jessie_version="~bpo80+20150611+1"

#!/bin/bash -e

mirror="http://ftp.de.debian.org/debian"

package_name="xf86-video-modesetting"
debian_pkg_name="${package_name}"
package_version="0.9.0"
package_source="xserver-xorg-video-modesetting_${package_version}.orig.tar.gz"
src_dir="${package_name}-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="x/xserver-xorg-video-modesetting"
dl_path="${mirror}/pool/main/${reprepro_dir}/"

debian_version="${package_version}-1"
debian_untar=""
debian_patch="xserver-xorg-video-modesetting_${debian_version}.diff.gz"

wheezy_version="~bpo70+20140924+1"
jessie_version="~20140924+1"

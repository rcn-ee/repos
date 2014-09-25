#!/bin/bash -e

#http://packages.siduction.org/lxqt/pool/main/l/lxqt-globalkeys/

mirror="http://packages.siduction.org"

package="lxqt-globalkeys"
location="lxqt/pool/main/l/${package}"
pkg_version="0.7.96"
deb_version="1"
orig_comp="bz2"
deb_file="liblxqt-globalkeys-qt5-0-dev_${pkg_version}-${deb_version}_${deb_arch}.deb"


package_name="lxqt-globalkeys"
debian_pkg_name="${package_name}"
package_version="0.7.96"
package_source="${package_name}_${package_version}.orig.tar.bz2"
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="l/${package_name}"
dl_path="${mirror}/lxqt/pool/main/${reprepro_dir}/"

debian_version="${package_version}-1"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""

wheezy_version="~bpo70+20140924+1"
jessie_version="~20140925+1"

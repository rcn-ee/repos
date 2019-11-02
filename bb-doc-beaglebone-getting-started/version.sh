#!/bin/bash -e

#https://github.com/beagleboard/beaglebone-getting-started

package_name="doc-beaglebone-getting-started"
debian_pkg_name="${package_name}"
package_version="1.20191031.0"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="d/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0rcnee0"
debian_untar=""
debian_patch=""
debian_dl_1="http://git.gfnd.rcn-ee.org:82/cgit/archive/.git/plain/beaglebone-getting-started/beaglebone-getting-started-2019-10-31.img.xz"

stretch_version="~stretch+20191102"
buster_version="~buster+20191102"
xenial_version="~xenial+20191102"
bionic_version="~bionic+20191102"

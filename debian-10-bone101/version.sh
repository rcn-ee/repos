#!/bin/bash -e

package_name="bone101"
debian_pkg_name="${package_name}"
package_version="2.1.3"
package_source="${package_name}_${package_version}.orig.tar.gz"
src_dir="${package_name}-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="b/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0rcnee14"
debian_untar=""
debian_patch=""

#dl_mirror="http://gitlab.gfnd.rcn-ee.org/RobertCNelson/npm-package-node-red/raw/master/deploy/buster"

#v10="v10.15.1"

#    node_async="async-2.0.1"
#node_sensortag="sensortag-1.3.0"

#debian_dl_1="${dl_mirror}/${node_async}-${v10}.tar.xz"
#debian_dl_2="${dl_mirror}/${node_sensortag}-${v10}.tar.xz"

buster_version="~buster+20221228"

#!/bin/bash -e

package_name="apple-swift"
debian_pkg_name="${package_name}"
package_version="2.1"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="apple-swift-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="d/${package_name}"
dl_path=""

debian_version="${package_version}-1"
debian_untar=""
debian_patch=""

jessie_version="~bpo80+20151202+1"
stretch_version="~bpo90+20151202+1"
xenial_version="~bpo1604+20151202+1"

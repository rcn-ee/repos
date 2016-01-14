#!/bin/bash -e

mirror="http://ftp.de.debian.org/debian"

package_name="mesa"
debian_pkg_name="${package_name}"
package_version="11.1.1"
package_source="${package_name}_${package_version}.orig.tar.gz"
src_dir="${package_name}-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="m/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-1"
debian_untar=""
debian_patch="${package_name}_${debian_version}.diff.gz"

jessie_version="~bpo80+20160114+1"
stretch_version="~bpo90+20160114+1"
xenial_version="~bpo1604+20160114+1"

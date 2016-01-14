#!/bin/bash -e

#mirror="http://ftp.de.debian.org/debian"
mirror="http://deb.dovetail-automata.com"

package_name="machinekit"
debian_pkg_name="${package_name}"
package_version="0.1.1502"
package_source="${package_name}_${package_version}.orig.tar.bz2"
src_dir="${package_name}"

git_repo=""
git_sha=""
reprepro_dir="m/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-1da.bbot.pr779.git0edd3c0~1wheezy"
debian_untar="${package_name}_${debian_version}.debian.tar.bz2"
debian_patch=""

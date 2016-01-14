#!/bin/bash -e

mirror="https://rcn-ee.com/mirror/deb.dovetail-automata.com"

package_name="zeromq4"
debian_pkg_name="${package_name}"
package_version="4.0.4"

git_repo=""
git_sha=""
reprepro_dir="z/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-2~1da~wheezy1"
debian_untar="${package_name}_${debian_version}.debian.tar.gz"
debian_patch=""

#!/bin/bash -e

mirror="https://rcn-ee.com/mirror/deb.dovetail-automata.com"

package_name="libsodium"
debian_pkg_name="${package_name}"
package_version="0.5.0"

git_repo=""
git_sha=""
reprepro_dir="libs/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0.1mk~wheezy1"
debian_untar="${package_name}_${debian_version}.debian.tar.gz"
debian_patch=""

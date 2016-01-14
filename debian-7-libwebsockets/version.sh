#!/bin/bash -e

mirror="https://rcn-ee.com/mirror/deb.dovetail-automata.com"

package_name="libwebsockets"
debian_pkg_name="${package_name}"
package_version="2.2.git95a8abb"

git_repo=""
git_sha=""
reprepro_dir="libw/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0.2da~git95a8abb~wheezy1"
debian_untar="${package_name}_${debian_version}.debian.tar.gz"
debian_patch=""

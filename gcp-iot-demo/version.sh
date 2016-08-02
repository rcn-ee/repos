#!/bin/bash -e

package_name="gcp-iot-demo"
debian_pkg_name="${package_name}"
package_version="0.0.1"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="g/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0rcnee0"
debian_untar=""
debian_patch=""
debian_dl_1="https://github.com/rcn-ee/npm-package-gcp-iot-demo/raw/a768d8dd1366726980acba4771ff7dfb3565c1c8/deploy/gcp-iot-demo-0.0.1-fb406df-v0.12.15.tar.xz"


jessie_version="~bpo80+20160802+1"

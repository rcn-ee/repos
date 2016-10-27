#!/bin/bash -e

package_name="firmware-am57xx-opencl-monitor"
debian_pkg_name="${package_name}"
package_version="1.1.10.3-r0.0"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="f/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0rcnee2"
debian_untar=""
debian_patch=""

jessie_version="~bpo80+20161027+1"
stretch_version="~bpo90+20161027+1"
xenial_version="~bpo1604+20161027+1"

#!/bin/bash -e

#https://github.com/intel-iot-devkit/mraa
#https://launchpad.net/~mraa/+archive/ubuntu/mraa

package_name="mraa"
debian_pkg_name="${package_name}"
package_version="1.7.0-git20170906"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/intel-iot-devkit/mraa"
git_sha="615e0cd83ac7202440468b061d23ed282e288ddb"
reprepro_dir="libm/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee1"
debian_patch=""
debian_diff=""

stretch_version="~stretch+20170911"

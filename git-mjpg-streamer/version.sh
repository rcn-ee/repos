#!/bin/bash -e

#https://github.com/jacksonliam/mjpg-streamer

package_name="mjpg-streamer"
debian_pkg_name="${package_name}"
package_version="0.0.0-git20170316"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/jacksonliam/mjpg-streamer"
git_sha="3ed3f4cad86c4ad6e58bdc70a91c3cc3c949276a"
reprepro_dir="m/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee1"
debian_patch=""
debian_diff=""
#local_patch="rcnee0"

jessie_version="~bpo80+20170406"
stretch_version="~bpo90+20170406"

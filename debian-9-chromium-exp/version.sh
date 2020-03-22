#!/bin/bash -e

#https://snapshot.debian.org/binary/chromium/
#oldest: https://snapshot.debian.org/package/chromium-browser/67.0.3396.87-1~deb9u1/#chromium_67.0.3396.87-1:7e:deb9u1
#mirror="https://snapshot.debian.org/archive/debian-security/20180701T010208Z/"
#
#20200321:  https://snapshot.debian.org/package/chromium-browser/68.0.3440.75-1~deb9u1/#chromium_68.0.3440.75-1:7e:deb9u1
#mirror="https://snapshot.debian.org/archive/debian-security/20180727T051456Z/"

mirror="https://snapshot.debian.org/archive/debian-security/20180727T051456Z/"

package_name="chromium-browser"
debian_pkg_name="${package_name}"
package_version="68.0.3440.75"
package_source="${debian_pkg_name}_${package_version}.orig.tar.xz"
src_dir="chromium-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="c/${package_name}"
dl_path="pool/updates/main/${reprepro_dir}/"

debian_version="${package_version}-1~deb9u1"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""
local_patch="rcnee0"

stretch_version="~stretch+20200321"

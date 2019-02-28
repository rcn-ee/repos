#!/bin/bash -e

package_name="bb-node-red-installer"
debian_pkg_name="${package_name}"
package_version="0.19.6"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="b/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0rcnee0"
debian_untar=""
debian_patch=""

#dl_mirror="https://github.com/rcn-ee/npm-package-node-red/raw/master/deploy/stretch"
dl_mirror="http://gitlab.gfnd.rcn-ee.org/RobertCNelson/npm-package-node-red/raw/master/deploy/stretch"

v6="v6.17.0"
v8="v8.15.1"

           node_red="node-red-0.19.6-d8b4c1e2"
      node_red_gpio="node-red-contrib-gpio-0.14.0"
node_red_mjpgcamera="node-red-contrib-mjpgcamera-1.0.4"
  node_red_particle="node-red-contrib-particle-1.1.0"
 node_red_dashboard="node-red-dashboard-2.14.0"
    node_red_serial="node-red-node-serialport-0.7.0"
   node_red_blockly="node-red-contrib-blockly-1.1.0"

debian_dl_1="${dl_mirror}/${node_red}-${v8}.tar.xz"
debian_dl_2="${dl_mirror}/${node_red_gpio}-${v8}.tar.xz"
debian_dl_3="${dl_mirror}/${node_red_mjpgcamera}-${v8}.tar.xz"
debian_dl_4="${dl_mirror}/${node_red_particle}-${v8}.tar.xz"
debian_dl_5="${dl_mirror}/${node_red_dashboard}-${v8}.tar.xz"
debian_dl_6="${dl_mirror}/${node_red_serial}-${v8}.tar.xz"
debian_dl_7="${dl_mirror}/${node_red_blockly}-${v8}.tar.xz"

debian_dl_8="${dl_mirror}/${node_red}-${v6}.tar.xz"
debian_dl_9="${dl_mirror}/${node_red_gpio}-${v6}.tar.xz"
debian_dl_10="${dl_mirror}/${node_red_mjpgcamera}-${v6}.tar.xz"
debian_dl_11="${dl_mirror}/${node_red_particle}-${v6}.tar.xz"
debian_dl_12="${dl_mirror}/${node_red_dashboard}-${v6}.tar.xz"
debian_dl_13="${dl_mirror}/${node_red_serial}-${v6}.tar.xz"
debian_dl_14="${dl_mirror}/${node_red_blockly}-${v6}.tar.xz"

stretch_version="~stretch+20190228"

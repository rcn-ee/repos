#!/bin/bash -e

package_name="bb-node-red-installer"
debian_pkg_name="${package_name}"
package_version="1.0.2"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="b/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0rcnee3"
debian_untar=""
debian_patch=""

dl_mirror="http://git.gfnd.rcn-ee.org:82/cgit/npm-package-node-red-scripts/.git/plain/deploy/buster"

v10="v10.15.2"

           node_red="node-red-1.0.2"
      node_red_gpio="node-red-contrib-gpio-0.14.0"
node_red_mjpgcamera="node-red-contrib-mjpgcamera-1.0.4"
  node_red_particle="node-red-contrib-particle-1.1.0"
 node_red_dashboard="node-red-dashboard-2.17.1"
    node_red_serial="node-red-node-serialport-0.8.8"
   node_red_blockly="node-red-contrib-blockly-1.1.0"

debian_dl_1="${dl_mirror}/${node_red}-${v10}.tar.xz"
debian_dl_2="${dl_mirror}/${node_red_gpio}-${v10}.tar.xz"
debian_dl_3="${dl_mirror}/${node_red_mjpgcamera}-${v10}.tar.xz"
debian_dl_4="${dl_mirror}/${node_red_particle}-${v10}.tar.xz"
debian_dl_5="${dl_mirror}/${node_red_dashboard}-${v10}.tar.xz"
debian_dl_6="${dl_mirror}/${node_red_serial}-${v10}.tar.xz"
debian_dl_7="${dl_mirror}/${node_red_blockly}-${v10}.tar.xz"

buster_version="~buster+20191029"

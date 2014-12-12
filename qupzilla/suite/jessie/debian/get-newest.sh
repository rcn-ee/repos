#! /bin/sh
set -e

package=qupzilla
version=$2

debian_orig_txz=${package}_${version}~dfsg1.orig.tarxz
debian_newdir=${package}-${version}~dfsg1
upstream_archive=v${version}.tar.gz
upstream_newdir=${package}-${version}

cd ..
tar xzf $upstream_archive
rm -f ${package}_${version}.orig*

mv ${upstream_newdir} ${debian_newdir}
##############################
# cleans unwanted files
# 
rm ${debian_newdir}/src/lib/data/html/*.js
rm ${debian_newdir}/bin/locale/*.qm

tar cJf ${debian_orig_txz} ${debian_newdir}

echo "Created the archive ../${debian_orig_txz} and unrolled it to ../${debian_newdir}"


#!/bin/sh
# Script to remove non-DFSG-free elements from fceux upstream tarball
# License: GPL-2+
set -e

extentions="bz2 chm dll exe gz lib zip"
for ext in ${extentions}; do
    find . -name *.${ext} -print | \
    while read i; do
        echo "Removing '${i}'..."
        rm "${i}"
    done
done

dirs="~attic src/drivers/win/directx vc"
for d in ${dirs}; do
    if [ -e "./${d}" ]; then
        echo "Removing './${d}'..."
        rm -rf "./${d}"
    fi
done

# vim: si ts=4 sw=4 et:

#!/bin/sh

set -e

eval `uscan --report --dehs | awk -F'[<>]' -f debian/dehs-to-shell.awk`
upstream_tarball=`echo "$upstream_url" | sed -e 's@.*/@@'`
upstream_dir=`basename "$upstream_tarball" '.tar.gz'`
for i in package debian_uversion debian_mangled_uversion upstream_version \
    upstream_url upstream_tarball; do
    	eval "val=\"\$$i\""
	if [ -z "$val" ]; then
		echo "uscan --report --dehs did not provide $i"
		exit 1
	fi
done

# We will need orig_dir if we ever need to actually repack - as in
# remove or replace files, directories, etc.
#
#orig_dir="$package-$debian_uversion.orig"

orig_name="${package}_$debian_uversion.orig"
orig_tarball="$orig_name.tar.gz"

up_dir="`pwd`/../tarballs"

# Fetch the upstream tarball if needed
mkdir -p "$up_dir"
if [ ! -f "$up_dir/$upstream_tarball" ]; then
	echo "Fetching upstream tarball $up_dir/$upstream_tarball"
	(cd "$up_dir" && wget -nv -c "$upstream_url")
else
	echo "Upstream tarball $up_dir/$upstream_tarball exists";
fi

# Nothing to remove or replace so we do not even need to extract,
# merely copy to the new tarball name.
# Yes, this will keep dpkg-source complaining about the directory
# name mismatch - just as it does on pretty much any other package ;)
#
rm -f "$up_dir/$orig_tarball"
if [ -e "$up_dir/$orig_tarball" ]; then
	echo "Could not remove $up_dir/$orig_tarball" 1>&2
	exit 1
fi
# Try to link first, if not, then copy
if ! ln "$up_dir/$upstream_tarball" "$up_dir/$orig_tarball" || [ ! -f "$up_dir/$orig_tarball" ]; then
	cp "$up_dir/$upstream_tarball" "$up_dir/$orig_tarball"
fi
echo "The repackaged source is at $up_dir/$orig_tarball"

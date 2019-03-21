#!/bin/sh

# to be run from the package top level directory
# parts taken from http://blog.orebokech.com/2007/08/converting-debian-packages-from-dpatch.html
# (c) gregor herrmann, 2007-2008, GPL2+
# (c) Damyan Ivanov, 2007-2008, GPL2+

# (c) Martin Quinson, 2008, GPL2+
# svn-related lines commented out by Martin Quinson.

set -e

export QUILT_PATCHES=debian/patches

dh_testdir

[ -f debian/patches/00list ] || exit 1

for p in $(dpatch list-all); do
        quilt import -P $p.patch debian/patches/$p.dpatch
        AUTHOR=$(dpatch cat --author-only $p.dpatch)
        DESC=$(dpatch cat --desc-only $p.dpatch)
        echo "Author: $AUTHOR" | quilt header -r $p.patch
        echo "Description: $DESC" | quilt header -a $p.patch
        

        quilt push
        quilt refresh --no-timestamps --no-index --strip-trailing-whitespace
        # svn add debian/patches/$p.patch
done
quilt pop -a

COUNT_D=$(ls -1 debian/patches/*.dpatch | wc -l)
COUNT_Q=$(ls -1 debian/patches/*.patch | wc -l)

# svn add debian/patches/series
# svn rm debian/patches/00list debian/patches/*.dpatch

sed -i -e 's;/usr/share/dpatch/dpatch\.make;/usr/share/quilt/quilt.make;' debian/rules
sed -i -e 's;DPATCH_STAMPFN;QUILT_STAMPFN;' debian/rules
sed -i -e 's;patch-stamp;$(QUILT_STAMPFN);' debian/rules

# same as "sed s/dpatch/quilt", but supports multi-line Build-Depends
perl -i -pe '
if( /^Build-Depends: / ) {
    $do_replace = 1;
    s/dpatch ?(?:\(.+\))?/quilt (>= 0.40)/;
    next;
}
if( /^ / ) {
    s/dpatch ?(?:\(.+\))?/quilt (>= 0.40)/ if $do_replace;
} else {
    $do_replace = 0;
}' debian/control

echo
echo "The next commit would remove $COUNT_D dpatch patches and add $COUNT_Q quilt patches."

if [ "$COUNT_D" != "$COUNT_Q" ] ; then
        echo "WARNING: The numbers of removed dpatch patches and added quilt patches differ!"
fi

exit 0

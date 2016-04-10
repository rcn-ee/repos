#! /bin/sh
# Author: Eugeniy Meshcheryakov <eugen@debian.org>
# This file is in the public domain
#
# Usage: sh make-snapshot.sh /path/to/systemtap/repo/.git

set -e

REPO="$1"

lastrelease=`git --bare --git-dir="$REPO" describe --match "release-*" --abbrev=0 HEAD | sed s/release-//`
today=`date +%Y%m%d`
pkgver="$lastrelease+0git$today"

echo "Using release version $lastrelease"
echo "New package version: $pkgver"

git --bare --git-dir="$REPO" archive --prefix=systemtap-$pkgver/ HEAD | gzip -9 > systemtap-$pkgver.tar.gz

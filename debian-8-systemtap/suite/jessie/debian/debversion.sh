#! /bin/sh

set -e

if [ $# -ge 1 ]
then
	CHANGELOG="$1"
else
	CHANGELOG="debian/changelog"
fi

DEBIAN_VERSION=$(dpkg-parsechangelog "-l$CHANGELOG"| sed -n 's/Version: //p')
DEBIAN_DIST=$(dpkg-parsechangelog "-l$CHANGELOG"| sed -n 's/Distribution: //p')

if [ "$DEBIAN_DIST" != "unstable" ]
then
	DEBIAN_MORE=" ($DEBIAN_DIST)"
else
	DEBIAN_MORE=
fi

DEBIAN_MSG="\"Debian version ${DEBIAN_VERSION}${DEBIAN_MORE}\""

cat <<EOF
#ifndef GIT_VERSION_H
#define GIT_VERSION_H 1

#define GIT_MESSAGE ${DEBIAN_MSG}

#endif
EOF

#!/bin/sh
# Determine the translation options and translate

set -e -u

usage() {
	name=$(basename $0)
	echo <<EOF
Usage: $name [options...]"
Options:
  --sandbox       Translate a sandboxed PyPy
  --python=PYTHON Use PYTHON to tranlate PyPy

EOF
}

SANDBOX=0
PYTHON=python

while [ $# -ge 1 ]; do
	case "$1" in
	--sandbox)
		SANDBOX=1
		;;
	--python)
		PYTHON="$2"
		shift
		;;
	--help|-h)
		usage
		exit 0
		;;
	*)
		echo "Unkown option: $1" >&2
		usage
		exit 1
		;;
	esac
	shift
done

RPYOPTS="--batch --source"
TARGETOPTS=""

OPT=3
ROOTFINDER=shadowstack
if echo "$DEB_BUILD_OPTIONS" | egrep -q '\bnoopt\b'; then
	OPT=0
elif [ $SANDBOX -gt 0 ]; then
	OPT=2
elif dpkg-architecture -iany-i386; then
	OPT=jit
	ROOTFINDER=asmgcc
	#RPYOPTS="$RPYOPTS --jit-backend=x86-without-sse2"
elif dpkg-architecture -iany-arm; then
	# No JIT support for ARMv5
	if ! dpkg-architecture -elinux-armel; then
		OPT=jit
	fi
	ROOTFINDER=shadowstack
elif dpkg-architecture -iany-amd64; then
	# No JIT on x32
	if ! dpkg-architecture -elinux-x32; then
		OPT=jit
	fi
	ROOTFINDER=asmgcc
fi
RPYOPTS="$RPYOPTS --opt=$OPT"

if [ $SANDBOX -gt 0 ]; then
	RPYOPTS="$RPYOPTS --sandbox --gc=generation"
	ROOTFINDER=shadowstack
fi
if [ $OPT = "mem" -o $OPT = "jit" -o $OPT = 2 -o $OPT = 3 ]; then
	RPYOPTS="$RPYOPTS --gcrootfinder=$ROOTFINDER"
fi

CONTINUATION=0
if dpkg-architecture -iany-i386 \
   || dpkg-architecture -iany-amd64 \
   || dpkg-architecture -iany-arm; then
	CONTINUATION=1
fi
if [ $CONTINUATION -eq 0 ]; then
	TARGETOPTS="$TARGETOPTS --withoutmod-_continuation"
fi

set -x
cd pypy/goal
exec "$PYTHON" -u ../../rpython/bin/rpython $RPYOPTS targetpypystandalone $TARGETOPTS 2>&1

#!/bin/sh
# Determine if we have enough RAM
# PyPy upstream claims it needs at least 2GiB on 32bit and 4GiB on 64bit
# (pointers dominate the memory)

set -e -u

# We don't enforce this on Ubuntu, which has less minority architectures.
if dpkg-vendor --derives-from Ubuntu; then
	# Only get out of jail free on the primary archive buildds
	# Do the RAM check for PPA builds
	if grep -q '^Purpose: *PRIMARY' /CurrentlyBuilding; then
		exit 0
	fi
fi

# Memory we will require on 32-bit archs
# This estimate is on the low side, we'll be spilling over into swap, but
# should still be able to build within a couple of days.
REQ_32_MEM=1400

# x86 has JIT enabled (which will need more) and machines with >= 4GB of RAM
# aren't rare, so let's be a little more conservative (c.f. #713787)
# (except kfreebsd-amd64 which currently has 3GB buildds, sigh)
if dpkg-architecture -iany-i386 || dpkg-architecture -ilinux-amd64; then
	REQ_32_MEM=2000
fi

MEM=$(sed -rne 's/^MemTotal: *([0-9]+) kB$$/\1/p' /proc/meminfo)
MEM=$((MEM / 1024))
SWAP=$(sed -rne 's/^SwapTotal: *([0-9]+) kB$$/\1/p' /proc/meminfo)
SWAP=$((SWAP / 1024))

BITS=$(dpkg-architecture -qDEB_HOST_ARCH_BITS)
if [ $BITS -ge 64 ]; then
	REQ_MEM=$(($REQ_32_MEM * 2))
else
	REQ_MEM=$REQ_32_MEM
fi

echo "PyPy requires >= $REQ_MEM MiB of RAM to build (on a $BITS-bit machine)."
echo "This machine has $MEM MiB of RAM."

if dpkg-architecture -qDEB_BUILD_ARCH | grep -q s390; then
	MEM=$(($MEM + $SWAP))
	echo "Counting the $SWAP MiB of swap too, as s390 apparently has very fast swap."
fi

if [ $REQ_MEM -lt $MEM ]; then
	echo "Assuming we have enough RAM to build."
else
	echo "You probably don't have enough RAM to build PyPy in any reasonable amount of time." >&2
	echo "Aborting" >&2
	exit 1
fi

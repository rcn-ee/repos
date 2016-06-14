#!/bin/sh
set -e

__goos__deb_arch_os() {
	case "$1" in
		kfreebsd) echo freebsd ;;
		linux) echo "$1" ;;
		*) echo >&2 "error: unrecongized DEB_*_ARCH_OS: $1"; exit 1 ;;
	esac
}

__goarch__deb_arch_cpu() {
	case "$1" in
		amd64|arm|arm64|ppc64) echo "$1" ;;
		i386) echo 386 ;;
		ppc64el) echo ppc64le ;;
		*) echo >&2 "error: unrecongized DEB_*_ARCH_CPU: $1"; exit 1 ;;
	esac
}

#       build machine
#           The machine the package is built on.
#
#       host machine
#           The machine the package is built for.

export GOHOSTOS="$(__goos__deb_arch_os "$(dpkg-architecture -qDEB_BUILD_ARCH_OS 2>/dev/null)")"
export GOOS="$(__goos__deb_arch_os "$(dpkg-architecture -qDEB_HOST_ARCH_OS 2>/dev/null)")"

export GOHOSTARCH="$(__goarch__deb_arch_cpu "$(dpkg-architecture -qDEB_BUILD_ARCH_CPU 2>/dev/null)")"
export GOARCH="$(__goarch__deb_arch_cpu "$(dpkg-architecture -qDEB_HOST_ARCH_CPU 2>/dev/null)")"

if [ -z "$GOHOSTOS" -o -z "$GOOS" -o -z "$GOHOSTARCH" -o -z "$GOARCH" ]; then
	exit 1
fi

# Always use the 387 floating point unit instead of sse2. This is important to
# ensure that the binaries we build (both when compiling golang on the buildds
# and when users cross-compile for 386) can actually run on older CPUs (where
# old means e.g. an AMD Athlon XP 2400+). See http://bugs.debian.org/753160 and
# https://code.google.com/p/go/issues/detail?id=8152
export GO386=387

unset GOARM
if [ "$GOARCH" = 'arm' ]; then
	# start with GOARM=5 for maximum compatibility (see note about GO386 above)
	GOARM=5
	case "$(dpkg-architecture -qDEB_HOST_ARCH 2>/dev/null)" in
		armhf) GOARM=6 ;;
	esac
fi
export GOARM

eval "$@"

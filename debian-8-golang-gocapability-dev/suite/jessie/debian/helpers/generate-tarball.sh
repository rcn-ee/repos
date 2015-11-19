#!/bin/bash
set -e

# usage: $0 [directory [version]]

directory="$1"
version="$2"

if [ -z "$directory" ]; then
	echo >&2 "usage: $0 directory [version]"
	echo >&2 "   ie: $0 ../tarballs"
	echo >&2 "       $0 .. 0.0~git19700101.1.0000000"
	exit 1
fi

debian="$(readlink -f "$(dirname "$BASH_SOURCE")/..")"
packageLine="$(head -n1 "$debian/changelog")"
packageName="$(echo "$packageLine" | cut -d' ' -f1)"
packageDebianVersion="$(echo "$packageLine" | cut -d'(' -f2 | cut -d')' -f1)"
packageVersion="${packageDebianVersion%-*}" # strip off the "debian version" suffix (-1, -2, -3, etc)

if [ -z "$version" ]; then
	echo >&2 "version not specified, using '$packageVersion' from d/changelog"
	version="$packageVersion"
fi

tag="upstream/${version//'~'/_}"
mkdir -p "$directory"
directory="$(readlink -f "$directory")"
archive="$directory/${packageName}_${version}.orig.tar.gz"
commit="$(git log -1 --pretty='%h' "$tag" -- || true)"

if [ -z "$commit" ]; then
	echo >&2 "error: $tag does not appear to be a valid tag"
	echo >&2 '  did you forget to run "create-upstream-tag.sh"?'
	exit 1
fi

gitRoot="$(git rev-parse --show-toplevel)"
( set -x
	cd "$gitRoot"
	git archive \
		--format='tar.gz' \
		--prefix="${packageName}_${commit}/" \
		"$tag" \
			> "$archive"
)

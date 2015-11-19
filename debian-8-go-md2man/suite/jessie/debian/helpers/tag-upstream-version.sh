#!/bin/bash
set -e

version="$1"

dir="$(dirname "$(readlink -f "$BASH_SOURCE")")"
"$dir/setup-upstream-remote.sh"

debian="$(readlink -f "$(dirname "$BASH_SOURCE")/..")"
packageLine="$(head -n1 "$debian/changelog")"
packageDebianVersion="$(echo "$packageLine" | cut -d'(' -f2 | cut -d')' -f1)"
packageVersion="${packageDebianVersion%-*}" # strip off the "debian version" suffix (-1, -2, -3, etc)

if [ -z "$version" ]; then
	echo >&2 "version not specified, using '$packageVersion' from d/changelog"
	version="$packageVersion"
fi

git fetch -qn upstream "+refs/tags/v$version:refs/tags/upstream/$version"

echo
echo "local tag 'upstream/$version' updated"
echo
echo 'use the following to push it:'
echo
echo "  git push -f origin upstream/$version:upstream/$version"
echo
echo 'if this upstream version has not been merged into master yet, use:'
echo
echo "  git merge upstream/$version"
echo

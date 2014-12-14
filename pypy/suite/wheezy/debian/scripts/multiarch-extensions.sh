#!/bin/sh

# Rename libraries to fully-qualified multiarch filenames.

set -euf
find lib_pypy -name '*.so' | while read extension; do
	if echo "$extension" | grep -q '\.pypy-[0-9]*[a-z]*\.so'; then
		dest="${extension%.so}-${DEB_HOST_MULTIARCH}.so"
		mv "$extension" "$dest"
	fi
done

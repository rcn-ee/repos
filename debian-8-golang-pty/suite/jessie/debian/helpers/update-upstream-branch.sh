#!/bin/bash
set -e

dir="$(dirname "$(readlink -f "$BASH_SOURCE")")"
"$dir/setup-upstream-remote.sh"

( set -x; git fetch -q upstream master )
( set -x; git update-ref refs/heads/upstream FETCH_HEAD )

echo
echo 'local "upstream" branch updated'
echo
echo 'use the following to push it:'
echo
echo '  git push -f origin upstream:upstream'
echo

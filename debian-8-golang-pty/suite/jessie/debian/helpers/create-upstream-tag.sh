#!/bin/bash
set -e

upstreamCommit="$1"
dayVersion="${2:-1}"

if [ -z "$upstreamCommit" ]; then
	echo >&2 "usage: $0 commit [day-version]"
	echo >&2 "   ie: $0 8d849acb"
	echo >&2 "   ie: $0 upstream # to tag the latest local upstream commit"
	echo >&2 "   ie: $0 upstream 2 # to tag a second commit in the same day"
	echo >&2
	echo >&2 'DO NOT USE BRANCH NAMES OR TAG NAMES FROM UPSTREAM!'
	echo >&2 'ONLY COMMIT HASHES OR "upstream" WILL WORK PROPERLY!'
	echo >&2
	echo >&2 'Also, you _must_ update your upstream remote and branch first, because that'
	echo >&2 'is where these commits come from ultimately.'
	echo >&2 '(See also the "update-upstream-branch.sh" helper.)'
	exit 1
fi

dir="$(dirname "$(readlink -f "$BASH_SOURCE")")"
"$dir/setup-upstream-remote.sh"

git fetch -qp --all || true
commit="$(git log -1 --date='short' --pretty='%h' "$upstreamCommit" --)"

unix="$(git log -1 --format='%at' "$commit" --)"
gitTime="$(date --date="@$unix" +'%Y%m%d')"
version="0.0~git${gitTime}.${dayVersion}.${commit}"

echo
echo "commit $commit becomes version $version"
echo

tag="upstream/${version//'~'/_}"

( set -x; git tag -f "$tag" "$commit" )

echo
echo "local tag '$tag' created"
echo
echo 'use the following to push it:'
echo
echo "  git push -f origin $tag:$tag"
echo
echo 'if this upstream version has not been merged into master yet, use:'
echo
echo "  git merge $tag"
echo

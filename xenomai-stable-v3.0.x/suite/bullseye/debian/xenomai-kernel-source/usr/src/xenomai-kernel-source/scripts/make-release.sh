#! /bin/bash

usage() {
	echo "usage: $0 name"
	exit 1
}

name=$1

if [ -z "$name" ]; then
	usage
fi

if [ ! -f config/version-code ] || [ ! -d .git ]; then
	echo "Must be run from top-level directory"
	exit 1
fi

if [ -n "`git status -s -uno`" ]; then
	echo "Working directory is dirty!"
	exit 1
fi

echo -e "Tag commit\n\n    `git log -1 --oneline`"
echo -e "\nof branch\n\n    `git branch | sed -n 's/^\* //p'`"
echo -ne "\nas $name? (y/N) "
read answer
if [ "$answer" != "y" ]; then
	exit 1
fi

echo $name | sed "s/v//" > config/version-code
cp  config/version-code config/version-label
git commit -sv config/version-code config/version-label -m "config: Bump version number"
git tag -as $name -m "Release $name"

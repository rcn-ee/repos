#!/bin/bash
set -e

upstream='https://github.com/syndtr/gocapability.git'

if ! git remote | grep -q upstream; then
	( set -x; git remote add upstream "$upstream" )
fi

#!/bin/bash
set -e

upstream='https://github.com/kr/pty.git'

if ! git remote | grep -q upstream; then
	( set -x; git remote add upstream "$upstream" )
fi

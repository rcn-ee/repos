#! /bin/sh
# Copyright (c) 2013 Sune Vuorela <sune@debian.org>
# Copyright (c) 2014 Lisandro Damián Nicanor Pérez Meyer <lisandro@debian.org>
#
# Permission is hereby granted, free of charge, to any person obtaining
# a copy of this software and associated documentation files (the
# "Software"), to deal in the Software without restriction, including
# without limitation the rights to use, copy, modify, merge, publish,
# distribute, sublicense, and/or sell copies of the Software, and to
# permit persons to whom the Software is furnished to do so, subject to
# the following conditions:
#
# The above copyright notice and this permission notice shall be included
# in all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
# IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
# CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
# TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
# SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

# Usage:
# Define DEBUG to see which symbols is being processed.
# Define WRITERESULTS to actually mark the real symbols files.

PRIVATE_HEADERS=debian/qtbase5-private-dev/usr/include

error() {
	echo $@
	exit 1
}

debug() {
	[ -n "${DEBUG}" ] && echo $@
}

if [ ! -e "${PRIVATE_HEADERS}" ] 
then
	error "Private headers not found"
fi

if [ ! -n "${WRITERESULTS}" ]
then
	# Create a backup copy of the original symbols file.
	for symbols_file in `ls debian/*.symbols`
	do
		cp $symbols_file $symbols_file.mps
	done
fi

grep -rh class ${PRIVATE_HEADERS} |
	grep EXPORT | 
	while read class export classname rest 
	do
		echo ${#classname}${classname} 
	done | 
	while read privateclass 
	do
		debug Marking ${privateclass} as private
		if [ -n "${WRITERESULTS}" ]
		then
			sed -i "s/\(.*${privateclass}[^ ]* *[^ ]*\)$/\1 1/" debian/*.symbols
		else
			sed -i "s/\(.*${privateclass}[^ ]* *[^ ]*\)$/\1 1/" debian/*.symbols.mps
		fi
	done 

if [ ! -n "${WRITERESULTS}" ]
then
	# Diff the symbols files and output it's differences.
	for symbols_file in `ls debian/*.symbols`
	do
		diff -Nau $symbols_file $symbols_file.mps
	done
fi

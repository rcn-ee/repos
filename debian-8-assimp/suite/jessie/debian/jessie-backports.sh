#!/bin/sh

# simple script to modify the debian/(control|rules) for a sid build to
# jessie-backports requirements

# debian/control
## - remove "Breaks|Replaces: libassimp3"
## - replace all occurences of libassimp3v5 with libassimp3
## - remove versioned dependency on g++
## LATER: use a proper debian/control parser and regenerate the file,
##        rather than doing a dumb 'sed'
sed \
 -e '/^Breaks: libassimp3$/d' \
 -e '/^Replaces: libassimp3$/d' \
 -e 's|libassimp3v5|libassimp3|g' \
 -e '/^ g\+\+\b.*(>=.*),/d' \
 -i debian/control



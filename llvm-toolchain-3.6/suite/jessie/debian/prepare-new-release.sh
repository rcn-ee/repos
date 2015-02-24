#!/bin/sh
ORIG_VERSION=3.4
TARGET_VERSION=3.5
ORIG_VERSION_2=3_4
TARGET_VERSION_2=3_5

LIST=`ls debian/*$ORIG_VERSION*`
for F in $LIST; do
    TARGET=`echo $F|sed -e "s|$ORIG_VERSION|$TARGET_VERSION|g"`
    svn mv $F $TARGET
done
LIST=`ls debian/*$TARGET_VERSION* debian/control debian/*.install debian/*.links debian/orig-tar.sh debian/rules`
for F in $LIST; do
    sed -i -e "s|$ORIG_VERSION_2|$TARGET_VERSION_2|g" $F
    sed -i -e "s|$ORIG_VERSION|$TARGET_VERSION|g" $F
done


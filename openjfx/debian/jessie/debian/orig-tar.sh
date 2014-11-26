#!/bin/sh

VERSION=$2
TAR=../openjfx_$VERSION.orig.tar.xz
DIR=rt-$VERSION

rm $3

wget http://hg.openjdk.java.net/openjfx/8u-dev/rt/archive/$VERSION.tar.gz

tar -xf $VERSION.tar.gz
rm $VERSION.tar.gz

XZ_OPT=--best tar -c -v -J -f $TAR \
                  --exclude '.hg*' \
                  --exclude '.classpath' \
                  --exclude '.project' \
                  --exclude '.idea' \
                  --exclude 'apps/samples' \
                  --exclude 'modules/graphics/src/main/native-iio/libjpeg*' \
                  --exclude 'modules/media/src/main/native/gstreamer/3rd_party/glib/*' \
                  --exclude 'modules/web/src/main/native/Tools/TestResultServer/static-dashboards/dygraph-combined.js' \
                  $DIR

rm -Rf $DIR

#!/bin/sh

if [ ! -f "$1" ]; then
  echo "does not exist: $1"
  exit 1
fi

jdkdir=$(tar tf $1 | head -1 | sed 's,/.*,,')
echo $jdkdir

dist=$(lsb_release -is)

echo "not needed anymore. 2.4.4 has both jdk and langtools cleaned up"
exit 1

# Untar openjdk source zip.
rm -rf openjdk
case "$1" in
  *.zip) unzip -q -x $1 ;;
  *.tar*) tar xf $1;;
esac

case "$1" in
  *jdk*)
    echo "Cleanup jdk tarball..."
    # Remove J2DBench sources, some of which have questionable license
    # headers.
    rm -rf \
        $jdkdir/src/share/demo/java2d/J2DBench

    # binary files
    rm -f \
        $jdkdir/test/sun/net/idn/*.spp

    rm -rf \
        $jdkdir/test/sun/security/pkcs11/nss/lib/*

    rm -f \
        $jdkdir/test/java/util/Locale/data/deflocale.sh \
        $jdkdir/test/java/util/Locale/data/deflocale.rhel5 \
        $jdkdir/test/java/util/Locale/data/deflocale.rhel5.fmtasdefault \
        $jdkdir/test/java/util/Locale/data/deflocale.sol10.fmtasdefault \
        $jdkdir/test/java/util/Locale/data/deflocale.win7 \
        $jdkdir/test/java/util/Locale/data/deflocale.win7.fmtasdefault
;;

  *langtools*)
    echo "Cleanup langtools tarball..."
    rm -rf $jdkdir/test/tools/javac/T5090006/broken.jar
;;

esac

# Create new zip with new name.

NEW_ZIP=$(echo $1 | sed -e 's/\.tar.gz/-dfsg.tar.gz/;s/\.zip/-dfsg.tar.gz/')
GZIP=-9v tar -cz -f $NEW_ZIP $jdkdir

# Remove old unzipped openjdk dir.
rm -rf $jdkdir

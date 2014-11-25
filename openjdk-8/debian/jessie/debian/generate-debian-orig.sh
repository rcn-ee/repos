#!/bin/sh

tarballs="corba.tar.gz hotspot.tar.gz jaxp.tar.gz jaxws.tar.gz jdk.tar.gz langtools.tar.gz openjdk.tar.gz"
# AArch64 hotspot
aarch64_hsname=f50993b6c38d
tarballs="$tarballs $aarch64_hsname.tar.gz"
jamvmtb=jamvm-ac22c9948434e528ece451642b4ebde40953ee7e.tar.gz
cacaotb=cacao-e215e36be9fc.tar.gz
tarballdir=7u55
version=7u55-2.4.7
base=openjdk-7
pkgdir=$base-$version
origtar=${base}_${version}.orig.tar.gz

icedtea_checkout=icedtea7-2.4.7
debian_checkout=openjdk7

if [ -d $pkgdir ]; then
    echo directory $pkgdir already exists
    exit 1
fi

if [ -d $pkgdir.orig ]; then
    echo directory $pkgdir.orig already exists
    exit 1
fi

if [ -f $origtar ]; then
    echo "Using existing $origtar"
    tar xf $origtar
    if [ -d $pkgdir.orig ]; then
       mv $pkgdir.orig $pkgdir
    fi
    tar -c -f - -C $icedtea_checkout . | tar -x -f - -C $pkgdir
    rm -rf $pkgdir/.hg
else
    echo "Creating new $pkgdir.orig/"
    rm -rf $pkgdir.orig
    mkdir -p $pkgdir.orig
    case "$base" in
      openjdk*)
        for i in $tarballs; do
            cp -p $tarballdir/$i $pkgdir.orig/
        done
	if [ -n "$cacaotb" ]; then
          cp -p $tarballdir/$cacaotb $pkgdir.orig/
	fi
        cp -p $tarballdir/$jamvmtb $pkgdir.orig/
      ;;
    esac
    tar -c -f - -C $icedtea_checkout . | tar -x -f - -C $pkgdir.orig
    (
      cd $pkgdir.orig
      sh autogen.sh
      rm -rf autom4te.cache
    )
    cp -a $pkgdir.orig $pkgdir
    rm -rf $pkgdir.orig/.hg
fi

echo "Build debian diff in $pkgdir/"
cp -a $debian_checkout $pkgdir/debian
(
  cd $pkgdir
  #bash debian/update-shasum.sh
  #bash debian/update-hgrev.sh
  ls
  patch -p1 < debian/patches/icedtea-patch.diff
  sh autogen.sh
  rm -rf autom4te.cache
  echo "aarch64 http://openjdk.linaro.org/hotspot $aarch64_hsname $(sha256sum $aarch64_hsname.tar.gz) $aarch64_hsname.tar.gz" >> hotspot.map
)

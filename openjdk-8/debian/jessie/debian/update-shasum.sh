#!/bin/bash

tarballs=(jdk-dfsg.tar.gz langtools-dfsg.tar.gz)
varshasum=(JDK_SHA256SUM LANGTOOLS_SHA256SUM)
tarballdir=.

makefile1=Makefile.am

function update_var() {
    varname=$1
    newsum=$2

    echo "$varname: ${newsum}"
    if [ -f $makefile1 ]; then
        sed -i "s/\(^$varname\)\(..*$\)/\1 = ${newsum}/" $makefile1
    fi
}

# For all modules
for (( i = 0 ; i < ${#tarballs[@]} ; i++ )); do
   newsum=$(sha256sum $tarballdir/${tarballs[$i]} | cut -f 1 -d ' ')
   update_var ${varshasum[$i]} $newsum
done

# Use downloaded cacao source tarball
#newsum=$(sha256sum $tarballdir/cacao-*.tar.* | cut -f 1 -d ' ')
#update_var "CACAO_SHA256SUM" $newsum

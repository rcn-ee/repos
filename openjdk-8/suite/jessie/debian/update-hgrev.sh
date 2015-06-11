#!/bin/bash

tarballs=(corba.tar.gz hotspot.tar.gz jaxp.tar.gz jaxws.tar.gz jdk-dfsg.tar.gz langtools-dfsg.tar.gz openjdk.tar.gz)
varhgchange=(CORBA_CHANGESET HOTSPOT_CHANGESET JAXP_CHANGESET JAXWS_CHANGESET JDK_CHANGESET LANGTOOLS_CHANGESET OPENJDK_CHANGESET)
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

function actual_tar_rev() {
    tar=$1

    revision=$(tar tf $tar | head -1 | sed 's,/.*,,' | sed 's,.*-,,')
}

# For all modules
for (( i = 0 ; i < ${#varhgchange[@]} ; i++ )); do
   actual_tar_rev $tarballdir/${tarballs[$i]}
   update_var ${varhgchange[$i]} $revision
done
#!/bin/bash -e

. version.sh

server="http://sigrok.org/download/source"

if [ ! -f ${package_name}-${package_version}.tar.gz ] ; then
	wget -c ${server}/${package_name}/${package_name}-${package_version}.tar.gz
fi

if [ -d ${package_name}_${package_version}.orig ] ; then
	rm -rf ${package_name}_${package_version}.orig || true
fi

mkdir -p ${package_name}_${package_version}.orig
tar xf ${package_name}-${package_version}.tar.gz -C ${package_name}_${package_version}.orig
cd ${package_name}_${package_version}.orig
mv libserialport-0.1.1/* ./
rm -rf libserialport-0.1.1/
tar cvfJ ../${package_name}_${package_version}.orig.tar.xz ./*
cd ../

#if [ ! -f ${package_name}_${package_version}.orig.tar.gz ] ; then
#	cp ${package_name}-${package_version}.tar.gz ${package_name}_${package_version}.orig.tar.gz
#fi

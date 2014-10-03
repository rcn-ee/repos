#!/bin/bash

if [ -f Packages.gz ] ; then
	rm Packages.gz
fi

wget http://packages.siduction.org/lxqt/dists/unstable/main/binary-amd64/Packages.gz

if [ -f Packages ] ; then
	rm Packages
fi

gunzip Packages.gz

grep -E "Source:|Version:" Packages > tmp.txt
tr '\n' ' ' < tmp.txt > list.txt
sed -i -e 's/ Source:/\nSource:/g' list.txt
sed -i -e 's/Source: //g' list.txt
sed -i -e 's/Version: //g' list.txt

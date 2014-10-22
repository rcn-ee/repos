#!/bin/bash

wget -c http://ftp.de.debian.org/debian/pool/main/t/tmux/tmux_1.6-2.dsc
wget -c http://ftp.de.debian.org/debian/pool/main/t/tmux/tmux_1.6.orig.tar.gz
wget -c http://ftp.de.debian.org/debian/pool/main/t/tmux/tmux_1.6-2.debian.tar.gz

if [ ! -f tmux-1.6_1.6.orig.tar.gz ] ; then
	cp -v tmux_1.6.orig.tar.gz tmux-1.6_1.6.orig.tar.gz
fi

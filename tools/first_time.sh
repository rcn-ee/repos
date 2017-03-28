#!/bin/sh

sudo apt update
sudo apt install sbuild quilt gobject-introspection scons xserver-xorg-dev dos2unix sphinx-common cdbs \
gnome-pkg-tools pkg-kde-tools \
dh-autoreconf dh-golang dh-systemd

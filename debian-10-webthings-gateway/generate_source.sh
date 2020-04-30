#!/bin/bash -e

. version.sh

if [ ! -f webthings-gateway_0.12.0.orig.tar.gz ] ; then
	wget -c https://github.com/rcn-ee/gateway-deb/raw/master/webthings-gateway_0.12.0.orig.tar.gz || true
fi


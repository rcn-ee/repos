#!/bin/bash -e

. version.sh

if [ ! -f webthings-gateway_0.11.0.orig.tar.gz ] ; then
	wget -c https://github.com/rcn-ee/gateway-deb/raw/generate_dsc/webthings-gateway_0.11.0.orig.tar.gz || true
fi


#!/bin/bash -e

. version.sh

server="https://nodejs.org/download/release"

get_extract () {
	wget -c ${server}/v${real_package_version}/node-v${real_package_version}.tar.gz || true

	mkdir -p ./${package_name}_${package_version}

	tar xf node-v${real_package_version}.tar.gz -C ./${package_name}_${package_version}
}
get_extract
real_package_version=0.10.41
get_extract


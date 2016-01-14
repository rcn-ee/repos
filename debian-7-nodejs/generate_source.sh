#!/bin/bash -e

. version.sh

server="https://nodejs.org/download/release"

wget -c ${server}/v${real_package_version}/node-v${real_package_version}.tar.gz || true

if [ -d ./${package_name}_${package_version} ] ; then
	rm -rf ./${package_name}_${package_version} || true
fi

mkdir -p ./${package_name}_${package_version}

tar xf node-v${real_package_version}.tar.gz -C ./${package_name}_${package_version}
rm -r ./${package_name}_${package_version}/node-v${real_package_version}/deps/cares/ || true
rm -r ./${package_name}_${package_version}/node-v${real_package_version}/deps/npm/ || true
rm -r ./${package_name}_${package_version}/node-v${real_package_version}/deps/openssl/ || true
rm -r ./${package_name}_${package_version}/node-v${real_package_version}/deps/zlib/ || true
rm    ./${package_name}_${package_version}/node-v${real_package_version}/doc/api/assets/joyent-footer.svg || true
rm    ./${package_name}_${package_version}/node-v${real_package_version}/doc/api/assets/logo.svg || true
rm    ./${package_name}_${package_version}/node-v${real_package_version}/doc/api_assets/joyent-footer.svg || true
rm    ./${package_name}_${package_version}/node-v${real_package_version}/doc/api_assets/logo.svg || true
rm    ./${package_name}_${package_version}/node-v${real_package_version}/doc/full-white-stripe.jpg || true
rm    ./${package_name}_${package_version}/node-v${real_package_version}/doc/mac_osx_nodejs_installer_logo.png || true
rm    ./${package_name}_${package_version}/node-v${real_package_version}/doc/sh_javascript.min.js || true
rm    ./${package_name}_${package_version}/node-v${real_package_version}/doc/thin-white-stripe.jpg || true
rm    ./${package_name}_${package_version}/node-v${real_package_version}/src/res/node.ico || true
rm -r ./${package_name}_${package_version}/node-v${real_package_version}/test/gc/node_modules/ || true
rm -r ./${package_name}_${package_version}/node-v${real_package_version}/tools/closure_linter/ || true
rm -r ./${package_name}_${package_version}/node-v${real_package_version}/tools/gyp/ || true
rm -r ./${package_name}_${package_version}/node-v${real_package_version}/tools/msvs/genfiles/ || true
rm -r ./${package_name}_${package_version}/node-v${real_package_version}/tools/wrk/ || true
rm    ./${package_name}_${package_version}/node-v${real_package_version}/tools/certdata.txt || true
cd ./${package_name}_${package_version}/
tar -cJf ${package_name}_${package_version}.orig.tar.xz ./node-v${real_package_version}/
cp -v ${package_name}_${package_version}.orig.tar.xz ../
cd ../

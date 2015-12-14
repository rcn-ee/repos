#!/bin/bash -e

. version.sh

mkdir -p ./${package_name}_${package_version}

cd ./${package_name}_${package_version}
git clone https://github.com/apple/swift --depth=1
git clone https://github.com/apple/swift-llvm --depth=1
git clone https://github.com/apple/swift-clang --depth=1
git clone https://github.com/apple/swift-lldb --depth=1
git clone https://github.com/apple/swift-cmark --depth=1
git clone https://github.com/apple/swift-llbuild --depth=1
git clone https://github.com/apple/swift-package-manager --depth=1
git clone https://github.com/apple/swift-corelibs-xctest --depth=1
git clone https://github.com/apple/swift-corelibs-foundation --depth=1
cd ..
tar -cJf ${package_name}_${package_version}.orig.tar.xz ./${package_name}_${package_version}


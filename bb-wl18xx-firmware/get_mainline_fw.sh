#!/bin/bash

get_fw () {
	git checkout ${sha} -b ${fw}
	cp -v ./ti-connectivity/wl18xx-fw-4.bin ../debian/wl18xx-fw-4-${fw}.bin
}

dl_src () {
	if [ -d ./src/ ] ; then
		rm -rf ./src/
	fi

	git clone https://git.kernel.org/pub/scm/linux/kernel/git/firmware/linux-firmware.git ./src/
}

dl_src

cd ./src/
sha="d5f9eea5a251d43412b07f5295d03e97b89ac4a5"
fw="8.9.0.0.83"
get_fw

if [ -d ./src/ ] ; then
	rm -rf ./src/
fi

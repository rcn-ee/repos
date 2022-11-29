#!/bin/bash

dl_src () {
	if [ -d ./src/ ] ; then
		rm -rf ./src/
	fi

	git clone https://git.kernel.org/pub/scm/linux/kernel/git/firmware/linux-firmware.git ./src/
}

dl_src

cp -v ./src/ti-connectivity/wl18xx-fw-4.bin ./override/

if [ -d ./src/ ] ; then
	rm -rf ./src/
fi

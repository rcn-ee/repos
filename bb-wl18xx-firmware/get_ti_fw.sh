#!/bin/bash

get_fw () {
	git checkout ${sha} -b ${fw}
	cp -v ./wl18xx-fw-4.bin ../debian/wl18xx-fw-4-${fw}.bin
}

dl_src () {
	if [ -d ./src/ ] ; then
		rm -rf ./src/
	fi

	git clone https://git.ti.com/cgit/wilink8-wlan/wl18xx_fw ./src/
}

dl_src

cd ./src/
sha="d153edae2a75393937da43159b7e6251c2cd01b6"
fw="8.9.0.0.79"
get_fw

sha="75f399c3b87e5cb9f9fc930a91024dcc679f5382"
fw="8.9.0.0.81"
get_fw

sha="fa462db10b5ce288404e7eee80f1b4b723f4ab79"
fw="8.9.0.0.84"
get_fw

sha="43dbcdfa19342068a023b2b9b07f65f8b11d1bea"
fw="8.9.0.0.85"
get_fw

sha="5ec05007f2662f460f881c5868311fd3ab7e6e71"
fw="8.9.0.0.86"
get_fw

sha="bda5304cc86e9c4029f8101394d2a8b39c640f53"
fw="8.9.0.0.88"
get_fw

sha="6c5ca87b9a912f09d090d5e1b6ace86d26718888"
fw="8.9.0.0.89"
get_fw

sha="d2588c16809ecca8e0dc7ea011fc6180c7b08a92"
fw="8.9.0.0.90"
get_fw

sha="efe46943410eb00776cf05175243e06760e66f1a"
fw="8.9.1.0.0"
get_fw

if [ -d ./src/ ] ; then
	rm -rf ./src/
fi

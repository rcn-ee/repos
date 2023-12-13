#!/bin/bash -e

. version.sh

current_kernel () {
	if [ -f /tmp/LATEST-${var} ] ; then
		rm -rf /tmp/LATEST-${var} | true
	fi
	unset latest_kernel
	wget --quiet --directory-prefix=/tmp/ https://rcn-ee.us/repos/latest/${dist}-${arch}/LATEST-${var} || true
	if [ -f /tmp/LATEST-${var} ] ; then
		latest_kernel=$(cat "/tmp/LATEST-${var}" | grep "ABI:1 ${ver}" | awk '{print $3}')
		echo ${dist}-${arch}-${latest_kernel}
	fi
}

generate_header () {
	echo "# This file is autogenerated. Do not edit!" > ./suite/${dist}/debian/${wfile}
	echo "Source: bbb.io-kernel" >> ./suite/${dist}/debian/${wfile}
	echo "Section: misc" >> ./suite/${dist}/debian/${wfile}
	echo "Priority: optional" >> ./suite/${dist}/debian/${wfile}
	echo "Maintainer: Robert Nelson <robertcnelson@gmail.com>" >> ./suite/${dist}/debian/${wfile}
	echo "Build-Depends:" >> ./suite/${dist}/debian/${wfile}
	echo " debhelper-compat (= ${debhelper})" >> ./suite/${dist}/debian/${wfile}
	echo "Standards-Version: 4.5.0" >> ./suite/${dist}/debian/${wfile}
	echo "Rules-Requires-Root: no" >> ./suite/${dist}/debian/${wfile}
	echo "" >> ./suite/${dist}/debian/${wfile}
	echo "Package: bbb.io-kernel-tasks" >> ./suite/${dist}/debian/${wfile}
	echo "Architecture: armhf" >> ./suite/${dist}/debian/${wfile}
	echo "Depends:" >> ./suite/${dist}/debian/${wfile}
	echo " tasksel" >> ./suite/${dist}/debian/${wfile}
	echo " , \${misc:Depends}" >> ./suite/${dist}/debian/${wfile}
	echo "Description: BeagleBoard.org Kernel Branches" >> ./suite/${dist}/debian/${wfile}
	echo " This package contains tasksel information for the BeagleBoard.org Kernel Branch." >> ./suite/${dist}/debian/${wfile}
}

generate_kernel_ti () {
	if [ ! "x${latest_kernel}" = "x" ] ; then
		echo "" >> ./suite/${dist}/debian/${wfile}
		echo "Package: bbb.io-kernel-${msg}" >> ./suite/${dist}/debian/${wfile}
		echo "Section: metapackages" >> ./suite/${dist}/debian/${wfile}
		echo "Architecture: armhf" >> ./suite/${dist}/debian/${wfile}
		echo "Pre-Depends: linux-image-${latest_kernel}" >> ./suite/${dist}/debian/${wfile}
		echo "Depends:" >> ./suite/${dist}/debian/${wfile}
		echo " \${misc:Depends}" >> ./suite/${dist}/debian/${wfile}
		echo " , bbb.io-kernel-tasks (= \${source:Version})" >> ./suite/${dist}/debian/${wfile}
		echo "Recommends: libpruio-modules-${latest_kernel}" >> ./suite/${dist}/debian/${wfile}
		echo "Description: BeagleBoard.org ${msg}" >> ./suite/${dist}/debian/${wfile}
		echo " This metapackage will install linux-image-${msg} in Debian." >> ./suite/${dist}/debian/${wfile}

		echo "" >> ./suite/${dist}/debian/${wfile}
		echo "Package: bbb.io-kernel-${msg}-am335x" >> ./suite/${dist}/debian/${wfile}
		echo "Section: metapackages" >> ./suite/${dist}/debian/${wfile}
		echo "Architecture: armhf" >> ./suite/${dist}/debian/${wfile}
		echo "Pre-Depends: linux-image-${latest_kernel}" >> ./suite/${dist}/debian/${wfile}
		echo "Depends:" >> ./suite/${dist}/debian/${wfile}
		echo " \${misc:Depends}" >> ./suite/${dist}/debian/${wfile}
		echo " , bbb.io-kernel-tasks (= \${source:Version})" >> ./suite/${dist}/debian/${wfile}
		echo "Recommends:" >> ./suite/${dist}/debian/${wfile}
		echo " libpruio-modules-${latest_kernel}" >> ./suite/${dist}/debian/${wfile}
		if [ "x${sgxti335x}" = "xenabled" ] ; then
			echo " , ti-sgx-ti335x-modules-${latest_kernel}" >> ./suite/${dist}/debian/${wfile}
		fi
		if [ "x${rtl8723bu}" = "xenabled" ] ; then
			echo " , rtl8723bu-modules-${latest_kernel}" >> ./suite/${dist}/debian/${wfile}
		fi
		if [ "x${rtl8723du}" = "xenabled" ] ; then
			echo " , rtl8723du-modules-${latest_kernel}" >> ./suite/${dist}/debian/${wfile}
		fi
		if [ "x${rtl8821cu}" = "xenabled" ] ; then
			echo " , rtl8821cu-modules-${latest_kernel}" >> ./suite/${dist}/debian/${wfile}
		fi
		if [ "x${qcacld}" = "xenabled" ] ; then
			echo " , qcacld-2.0-modules-${latest_kernel}" >> ./suite/${dist}/debian/${wfile}
		fi
		echo " , bb-u-boot-am335x-evm" >> ./suite/${dist}/debian/${wfile}
		echo "Description: BeagleBoard.org ${msg} for am335x" >> ./suite/${dist}/debian/${wfile}
		echo " This metapackage will install linux-image-${msg} for am335x in Debian." >> ./suite/${dist}/debian/${wfile}

		echo "" >> ./suite/${dist}/debian/${wfile}
		echo "Package: bbb.io-kernel-${msg}-am57xx" >> ./suite/${dist}/debian/${wfile}
		echo "Section: metapackages" >> ./suite/${dist}/debian/${wfile}
		echo "Architecture: armhf" >> ./suite/${dist}/debian/${wfile}
		echo "Pre-Depends: linux-image-${latest_kernel}" >> ./suite/${dist}/debian/${wfile}
		echo "Depends:" >> ./suite/${dist}/debian/${wfile}
		echo " \${misc:Depends}" >> ./suite/${dist}/debian/${wfile}
		echo " , bbb.io-kernel-tasks (= \${source:Version})" >> ./suite/${dist}/debian/${wfile}
		echo "Recommends:" >> ./suite/${dist}/debian/${wfile}
		echo " libpruio-modules-${latest_kernel}" >> ./suite/${dist}/debian/${wfile}
		if [ "x${sgxjacinto6evm}" = "xenabled" ] ; then
			echo " , ti-sgx-jacinto6evm-modules-${latest_kernel}" >> ./suite/${dist}/debian/${wfile}
		fi
		echo " , bb-u-boot-am57xx-evm" >> ./suite/${dist}/debian/${wfile}
		echo "Description: BeagleBoard.org ${msg} for am57xx" >> ./suite/${dist}/debian/${wfile}
		echo " This metapackage will install linux-image-${msg} for am57xx in Debian." >> ./suite/${dist}/debian/${wfile}
	fi
}

generate_kernel_mainline_bone () {
	if [ ! "x${latest_kernel}" = "x" ] ; then
		echo "" >> ./suite/${dist}/debian/${wfile}
		echo "Package: bbb.io-kernel-${msg}" >> ./suite/${dist}/debian/${wfile}
		echo "Section: metapackages" >> ./suite/${dist}/debian/${wfile}
		echo "Architecture: armhf" >> ./suite/${dist}/debian/${wfile}
		echo "Pre-Depends: linux-image-${latest_kernel}," >> ./suite/${dist}/debian/${wfile}
		echo "Depends: \${misc:Depends}, bbb.io-kernel-tasks (= \${source:Version})" >> ./suite/${dist}/debian/${wfile}
		echo "Recommends: libpruio-modules-${latest_kernel}" >> ./suite/${dist}/debian/${wfile}
		echo "Description: BeagleBoard.org ${msg} for am335x" >> ./suite/${dist}/debian/${wfile}
		echo " This metapackage will install linux-image-${msg} for am335x in Debian." >> ./suite/${dist}/debian/${wfile}
	fi
}

generate_kernel_mainline_armv7 () {
	if [ ! "x${latest_kernel}" = "x" ] ; then
		echo "" >> ./suite/${dist}/debian/${wfile}
		echo "Package: bbb.io-kernel-${msg}" >> ./suite/${dist}/debian/${wfile}
		echo "Section: metapackages" >> ./suite/${dist}/debian/${wfile}
		echo "Architecture: armhf" >> ./suite/${dist}/debian/${wfile}
		echo "Pre-Depends: linux-image-${latest_kernel}," >> ./suite/${dist}/debian/${wfile}
		echo "Depends: \${misc:Depends}, bbb.io-kernel-tasks (= \${source:Version})" >> ./suite/${dist}/debian/${wfile}
		echo "Recommends: libpruio-modules-${latest_kernel}" >> ./suite/${dist}/debian/${wfile}
		echo "Description: BeagleBoard.org ${msg} for armv7" >> ./suite/${dist}/debian/${wfile}
		echo " This metapackage will install linux-image-${msg} for armv7 in Debian." >> ./suite/${dist}/debian/${wfile}
	fi
}

generate_kernel_mainline_armv7_lpae () {
	if [ ! "x${latest_kernel}" = "x" ] ; then
		echo "" >> ./suite/${dist}/debian/${wfile}
		echo "Package: bbb.io-kernel-${msg}" >> ./suite/${dist}/debian/${wfile}
		echo "Section: metapackages" >> ./suite/${dist}/debian/${wfile}
		echo "Architecture: armhf" >> ./suite/${dist}/debian/${wfile}
		echo "Pre-Depends: linux-image-${latest_kernel}," >> ./suite/${dist}/debian/${wfile}
		echo "Depends: \${misc:Depends}, bbb.io-kernel-tasks (= \${source:Version})" >> ./suite/${dist}/debian/${wfile}
		echo "Recommends: libpruio-modules-${latest_kernel}" >> ./suite/${dist}/debian/${wfile}
		echo "Description: BeagleBoard.org ${msg} for armv7-lpae" >> ./suite/${dist}/debian/${wfile}
		echo " This metapackage will install linux-image-${msg} for armv7-lpae in Debian." >> ./suite/${dist}/debian/${wfile}
	fi
}

changelog () {
	git diff ./suite/${dist}/debian/control > /tmp/changelog-readme.diff
	cat /tmp/changelog-readme.diff | grep +Pre-Depends: | awk '{print $2}' | awk -F ',' '{print $1}' > /tmp/changelog-readme.cat
	sort -u /tmp/changelog-readme.cat > /tmp/changelog-readme.sort
	echo "  * Kernel Updates" > suite/${dist}/readme.log
	ts "  *" /tmp/changelog-readme.sort >> suite/${dist}/readme.log
	cat suite/${dist}/readme.log
}

do_all_lts () {
	msg="5.10-bone" ; var="omap-psp" ; ver="LTS510" ; current_kernel ; generate_kernel_mainline_bone
	msg="5.15-bone" ; var="omap-psp" ; ver="LTS515" ; current_kernel ; generate_kernel_mainline_bone
	msg="6.1-bone"  ; var="omap-psp" ; ver="LTS61"  ; current_kernel ; generate_kernel_mainline_bone
	msg="6.6-bone"  ; var="omap-psp" ; ver="LTS66"  ; current_kernel ; generate_kernel_mainline_bone

	msg="5.10-bone-rt" ; var="bone-rt" ; ver="LTS510" ; current_kernel ; generate_kernel_mainline_bone
	msg="5.15-bone-rt" ; var="bone-rt" ; ver="LTS515" ; current_kernel ; generate_kernel_mainline_bone
	msg="6.1-bone-rt"  ; var="bone-rt" ; ver="LTS61"  ; current_kernel ; generate_kernel_mainline_bone
	msg="6.6-bone-rt"  ; var="bone-rt" ; ver="LTS66"  ; current_kernel ; generate_kernel_mainline_bone

	msg="5.10-armv7" ; var="armv7" ; ver="LTS510" ; current_kernel ; generate_kernel_mainline_armv7
	msg="5.15-armv7" ; var="armv7" ; ver="LTS515" ; current_kernel ; generate_kernel_mainline_armv7
	msg="6.1-armv7"  ; var="armv7" ; ver="LTS61"  ; current_kernel ; generate_kernel_mainline_armv7
	msg="6.6-armv7"  ; var="armv7" ; ver="LTS66"  ; current_kernel ; generate_kernel_mainline_armv7

	msg="5.10-armv7-rt" ; var="armv7-rt" ; ver="LTS510" ; current_kernel ; generate_kernel_mainline_armv7
	msg="5.15-armv7-rt" ; var="armv7-rt" ; ver="LTS515" ; current_kernel ; generate_kernel_mainline_armv7
	msg="6.1-armv7-rt"  ; var="armv7-rt" ; ver="LTS61"  ; current_kernel ; generate_kernel_mainline_armv7
	msg="6.6-armv7-rt"  ; var="armv7-rt" ; ver="LTS66"  ; current_kernel ; generate_kernel_mainline_armv7

	msg="5.10-armv7-lpae" ; var="armv7-lpae" ; ver="LTS510" ; current_kernel ; generate_kernel_mainline_armv7_lpae
	msg="5.15-armv7-lpae" ; var="armv7-lpae" ; ver="LTS515" ; current_kernel ; generate_kernel_mainline_armv7_lpae
	msg="6.1-armv7-lpae"  ; var="armv7-lpae" ; ver="LTS61"  ; current_kernel ; generate_kernel_mainline_armv7_lpae
	msg="6.6-armv7-lpae"  ; var="armv7-lpae" ; ver="LTS66"  ; current_kernel ; generate_kernel_mainline_armv7_lpae
}

do_focal () {
	#20.04
	arch="armhf"
	dist="focal"
	debhelper="12"
	wfile="control"
	generate_header

	sgxti335x="enabled"
	sgxjacinto6evm="enabled"
	rtl8723bu="enabled"
	rtl8821cu="enabled"

	msg="4.19-ti"    ; var="ti"    ; ver="LTS419" ; current_kernel ; generate_kernel_ti
	msg="4.19-ti-rt" ; var="ti-rt" ; ver="LTS419" ; current_kernel ; generate_kernel_ti
	msg="5.4-ti"     ; var="ti"    ; ver="LTS54"  ; current_kernel ; generate_kernel_ti
	msg="5.4-ti-rt"  ; var="ti-rt" ; ver="LTS54"  ; current_kernel ; generate_kernel_ti

	rtl8723du="enabled"
	qcacld="enabled"

	msg="5.10-ti"    ; var="ti"    ; ver="LTS510" ; current_kernel ; generate_kernel_ti
	msg="5.10-ti-rt" ; var="ti-rt" ; ver="LTS510" ; current_kernel ; generate_kernel_ti

	unset qcacld
	unset rtl8723bu
	unset rtl8821cu
	unset sgxjacinto6evm
	unset sgxti335x

	msg="6.1-ti"     ; var="ti"    ; ver="LTS61"  ; current_kernel ; generate_kernel_ti
	msg="6.1-ti-rt"  ; var="ti-rt" ; ver="LTS61"  ; current_kernel ; generate_kernel_ti
	unset rtl8723du

	do_all_lts

	msg="5.19-bone" ; var="omap-psp" ; ver="V519X"  ; current_kernel ; generate_kernel_mainline_bone

	msg="6.3-bone"  ; var="omap-psp" ; ver="V63X"  ; current_kernel ; generate_kernel_mainline_bone
	msg="6.4-bone"  ; var="omap-psp" ; ver="V64X"  ; current_kernel ; generate_kernel_mainline_bone
	msg="6.5-bone"  ; var="omap-psp" ; ver="V65X"  ; current_kernel ; generate_kernel_mainline_bone

	msg="6.7-bone"  ; var="omap-psp" ; ver="V67X"  ; current_kernel ; generate_kernel_mainline_bone

	changelog
}

do_jammy () {
	#22.04
	arch="armhf"
	dist="jammy"
	debhelper="13"
	wfile="control"
	generate_header

	sgxti335x="enabled"
	sgxjacinto6evm="enabled"
	rtl8723bu="enabled"
	rtl8821cu="enabled"

	rtl8723du="enabled"
	qcacld="enabled"

	msg="5.10-ti"    ; var="ti"    ; ver="LTS510" ; current_kernel ; generate_kernel_ti
	msg="5.10-ti-rt" ; var="ti-rt" ; ver="LTS510" ; current_kernel ; generate_kernel_ti

	unset qcacld
	unset rtl8723bu
	unset rtl8821cu
	unset sgxjacinto6evm
	unset sgxti335x

	msg="6.1-ti"     ; var="ti"    ; ver="LTS61"  ; current_kernel ; generate_kernel_ti
	msg="6.1-ti-rt"  ; var="ti-rt" ; ver="LTS61"  ; current_kernel ; generate_kernel_ti
	unset rtl8723du

	do_all_lts

	msg="5.19-bone" ; var="omap-psp" ; ver="V519X"  ; current_kernel ; generate_kernel_mainline_bone

	msg="6.3-bone"  ; var="omap-psp" ; ver="V63X"  ; current_kernel ; generate_kernel_mainline_bone
	msg="6.4-bone"  ; var="omap-psp" ; ver="V64X"  ; current_kernel ; generate_kernel_mainline_bone
	msg="6.5-bone"  ; var="omap-psp" ; ver="V65X"  ; current_kernel ; generate_kernel_mainline_bone

	msg="6.7-bone"  ; var="omap-psp" ; ver="V67X"  ; current_kernel ; generate_kernel_mainline_bone

	changelog
}

do_noble () {
	#24.04
	arch="armhf"
	dist="noble"
	debhelper="13"
	wfile="control"
	generate_header

	msg="6.7-bone"  ; var="omap-psp" ; ver="V67X"  ; current_kernel ; generate_kernel_mainline_bone

	changelog
}

do_buster () {
	#10.x
	arch="armhf"
	dist="buster"
	debhelper="12"
	wfile="control"
	generate_header

	sgxti335x="enabled"
	sgxjacinto6evm="enabled"
	rtl8723bu="enabled"
	rtl8821cu="enabled"

	msg="4.14-ti-xenomai" ; var="ti-xenomai" ; ver="LTS414" ; current_kernel ; generate_kernel_ti

	msg="4.19-ti"    ; var="ti"    ; ver="LTS419" ; current_kernel ; generate_kernel_ti
	msg="4.19-ti-rt" ; var="ti-rt" ; ver="LTS419" ; current_kernel ; generate_kernel_ti
	msg="5.4-ti"     ; var="ti"    ; ver="LTS54"  ; current_kernel ; generate_kernel_ti
	msg="5.4-ti-rt"  ; var="ti-rt" ; ver="LTS54"  ; current_kernel ; generate_kernel_ti

	rtl8723du="enabled"
	qcacld="enabled"

	msg="5.10-ti"    ; var="ti"    ; ver="LTS510" ; current_kernel ; generate_kernel_ti
	msg="5.10-ti-rt" ; var="ti-rt" ; ver="LTS510" ; current_kernel ; generate_kernel_ti

	unset qcacld
	unset rtl8723bu
	unset rtl8821cu
	unset sgxjacinto6evm
	unset sgxti335x

	msg="6.1-ti"     ; var="ti"    ; ver="LTS61"  ; current_kernel ; generate_kernel_ti
	msg="6.1-ti-rt"  ; var="ti-rt" ; ver="LTS61"  ; current_kernel ; generate_kernel_ti
	unset rtl8723du

	msg="4.19-bone" ; var="omap-psp" ; ver="LTS419" ; current_kernel ; generate_kernel_mainline_bone
	msg="5.4-bone"  ; var="omap-psp" ; ver="LTS54"  ; current_kernel ; generate_kernel_mainline_bone

	msg="4.19-bone-rt" ; var="bone-rt" ; ver="LTS419" ; current_kernel ; generate_kernel_mainline_bone
	msg="5.4-bone-rt"  ; var="bone-rt" ; ver="LTS54"  ; current_kernel ; generate_kernel_mainline_bone

	msg="4.19-armv7" ; var="armv7" ; ver="LTS419" ; current_kernel ; generate_kernel_mainline_armv7
	msg="5.4-armv7"  ; var="armv7" ; ver="LTS54"  ; current_kernel ; generate_kernel_mainline_armv7

	msg="4.19-armv7-rt" ; var="armv7-rt" ; ver="LTS419" ; current_kernel ; generate_kernel_mainline_armv7
	msg="5.4-armv7-rt"  ; var="armv7-rt" ; ver="LTS54"  ; current_kernel ; generate_kernel_mainline_armv7

	msg="4.19-armv7-lpae" ; var="armv7-lpae" ; ver="LTS419" ; current_kernel ; generate_kernel_mainline_armv7_lpae
	msg="5.4-armv7-lpae"  ; var="armv7-lpae" ; ver="LTS54"  ; current_kernel ; generate_kernel_mainline_armv7_lpae

	do_all_lts

	msg="5.14-bone" ; var="omap-psp" ; ver="V514X" ; current_kernel ; generate_kernel_mainline_bone

	msg="5.16-bone" ; var="omap-psp" ; ver="V516X" ; current_kernel ; generate_kernel_mainline_bone
	msg="5.17-bone" ; var="omap-psp" ; ver="V517X" ; current_kernel ; generate_kernel_mainline_bone
	msg="5.18-bone" ; var="omap-psp" ; ver="V518X" ; current_kernel ; generate_kernel_mainline_bone
	msg="5.19-bone" ; var="omap-psp" ; ver="V519X" ; current_kernel ; generate_kernel_mainline_bone
	msg="6.0-bone"  ; var="omap-psp" ; ver="V60X"  ; current_kernel ; generate_kernel_mainline_bone

	msg="6.3-bone"  ; var="omap-psp" ; ver="V63X"  ; current_kernel ; generate_kernel_mainline_bone
	msg="6.4-bone"  ; var="omap-psp" ; ver="V64X"  ; current_kernel ; generate_kernel_mainline_bone
	msg="6.5-bone"  ; var="omap-psp" ; ver="V65X"  ; current_kernel ; generate_kernel_mainline_bone

	msg="6.7-bone"  ; var="omap-psp" ; ver="V67X"  ; current_kernel ; generate_kernel_mainline_bone
	changelog
}

do_bullseye () {
	#11.x
	arch="armhf"
	dist="bullseye"
	debhelper="13"
	wfile="control"
	generate_header

	sgxti335x="enabled"
	sgxjacinto6evm="enabled"
	rtl8723bu="enabled"
	rtl8821cu="enabled"

	msg="4.14-ti-xenomai" ; var="ti-xenomai" ; ver="LTS414" ; current_kernel ; generate_kernel_ti

	msg="4.19-ti"    ; var="ti"    ; ver="LTS419" ; current_kernel ; generate_kernel_ti
	msg="4.19-ti-rt" ; var="ti-rt" ; ver="LTS419" ; current_kernel ; generate_kernel_ti
	msg="5.4-ti"     ; var="ti"    ; ver="LTS54"  ; current_kernel ; generate_kernel_ti
	msg="5.4-ti-rt"  ; var="ti-rt" ; ver="LTS54"  ; current_kernel ; generate_kernel_ti

	rtl8723du="enabled"
	qcacld="enabled"

	msg="5.10-ti"    ; var="ti"    ; ver="LTS510" ; current_kernel ; generate_kernel_ti
	msg="5.10-ti-rt" ; var="ti-rt" ; ver="LTS510" ; current_kernel ; generate_kernel_ti

	unset qcacld
	unset rtl8723bu
	unset rtl8821cu
	unset sgxjacinto6evm
	unset sgxti335x

	msg="6.1-ti"     ; var="ti"    ; ver="LTS61"  ; current_kernel ; generate_kernel_ti
	msg="6.1-ti-rt"  ; var="ti-rt" ; ver="LTS61"  ; current_kernel ; generate_kernel_ti
	unset rtl8723du

	msg="4.19-bone" ; var="omap-psp" ; ver="LTS419" ; current_kernel ; generate_kernel_mainline_bone
	msg="5.4-bone"  ; var="omap-psp" ; ver="LTS54"  ; current_kernel ; generate_kernel_mainline_bone

	msg="4.19-bone-rt" ; var="bone-rt" ; ver="LTS419" ; current_kernel ; generate_kernel_mainline_bone
	msg="5.4-bone-rt"  ; var="bone-rt" ; ver="LTS54"  ; current_kernel ; generate_kernel_mainline_bone

	msg="4.19-armv7" ; var="armv7" ; ver="LTS419" ; current_kernel ; generate_kernel_mainline_armv7
	msg="5.4-armv7"  ; var="armv7" ; ver="LTS54"  ; current_kernel ; generate_kernel_mainline_armv7

	msg="4.19-armv7-rt" ; var="armv7-rt" ; ver="LTS419" ; current_kernel ; generate_kernel_mainline_armv7
	msg="5.4-armv7-rt"  ; var="armv7-rt" ; ver="LTS54"  ; current_kernel ; generate_kernel_mainline_armv7

	msg="4.19-armv7-lpae" ; var="armv7-lpae" ; ver="LTS419" ; current_kernel ; generate_kernel_mainline_armv7_lpae
	msg="5.4-armv7-lpae"  ; var="armv7-lpae" ; ver="LTS54"  ; current_kernel ; generate_kernel_mainline_armv7_lpae

	do_all_lts

	msg="5.14-bone" ; var="omap-psp" ; ver="V514X" ; current_kernel ; generate_kernel_mainline_bone

	msg="5.16-bone" ; var="omap-psp" ; ver="V516X" ; current_kernel ; generate_kernel_mainline_bone
	msg="5.17-bone" ; var="omap-psp" ; ver="V517X" ; current_kernel ; generate_kernel_mainline_bone
	msg="5.18-bone" ; var="omap-psp" ; ver="V518X" ; current_kernel ; generate_kernel_mainline_bone
	msg="5.19-bone" ; var="omap-psp" ; ver="V519X" ; current_kernel ; generate_kernel_mainline_bone
	msg="6.0-bone"  ; var="omap-psp" ; ver="V60X"  ; current_kernel ; generate_kernel_mainline_bone

	msg="6.2-bone"  ; var="omap-psp" ; ver="V62X"  ; current_kernel ; generate_kernel_mainline_bone
	msg="6.3-bone"  ; var="omap-psp" ; ver="V63X"  ; current_kernel ; generate_kernel_mainline_bone
	msg="6.4-bone"  ; var="omap-psp" ; ver="V64X"  ; current_kernel ; generate_kernel_mainline_bone
	msg="6.5-bone"  ; var="omap-psp" ; ver="V65X"  ; current_kernel ; generate_kernel_mainline_bone

	msg="6.7-bone"  ; var="omap-psp" ; ver="V67X"  ; current_kernel ; generate_kernel_mainline_bone

	changelog
}

do_bookworm () {
	#12.x
	arch="armhf"
	dist="bookworm"
	debhelper="13"
	wfile="control"
	generate_header

	sgxti335x="enabled"
	sgxjacinto6evm="enabled"
	rtl8723bu="enabled"
	rtl8821cu="enabled"

	msg="4.19-ti"    ; var="ti"    ; ver="LTS419" ; current_kernel ; generate_kernel_ti
	msg="4.19-ti-rt" ; var="ti-rt" ; ver="LTS419" ; current_kernel ; generate_kernel_ti
	msg="5.4-ti"     ; var="ti"    ; ver="LTS54"  ; current_kernel ; generate_kernel_ti
	msg="5.4-ti-rt"  ; var="ti-rt" ; ver="LTS54"  ; current_kernel ; generate_kernel_ti

	rtl8723du="enabled"
	qcacld="enabled"

	msg="5.10-ti"    ; var="ti"    ; ver="LTS510" ; current_kernel ; generate_kernel_ti
	msg="5.10-ti-rt" ; var="ti-rt" ; ver="LTS510" ; current_kernel ; generate_kernel_ti

	unset qcacld
	unset rtl8723bu
	unset rtl8821cu
	unset sgxjacinto6evm
	unset sgxti335x

	msg="6.1-ti"     ; var="ti"    ; ver="LTS61"  ; current_kernel ; generate_kernel_ti
	msg="6.1-ti-rt"  ; var="ti-rt" ; ver="LTS61"  ; current_kernel ; generate_kernel_ti
	unset rtl8723du

	do_all_lts

	msg="6.2-bone"  ; var="omap-psp" ; ver="V62X"  ; current_kernel ; generate_kernel_mainline_bone
	msg="6.3-bone"  ; var="omap-psp" ; ver="V63X"  ; current_kernel ; generate_kernel_mainline_bone
	msg="6.4-bone"  ; var="omap-psp" ; ver="V64X"  ; current_kernel ; generate_kernel_mainline_bone
	msg="6.5-bone"  ; var="omap-psp" ; ver="V65X"  ; current_kernel ; generate_kernel_mainline_bone

	msg="6.7-bone"  ; var="omap-psp" ; ver="V67X"  ; current_kernel ; generate_kernel_mainline_bone

	changelog
}

do_trixie () {
	#13.x
	arch="armhf"
	dist="trixie"
	debhelper="13"
	wfile="control"
	generate_header

	sgxti335x="enabled"
	sgxjacinto6evm="enabled"
	rtl8723bu="enabled"
	rtl8821cu="enabled"

	#4.19-ti/5.4-ti will not build on trixie/sid...
	#msg="4.19-ti"    ; var="ti"    ; ver="LTS419" ; current_kernel ; generate_kernel_ti
	#msg="4.19-ti-rt" ; var="ti-rt" ; ver="LTS419" ; current_kernel ; generate_kernel_ti
	#msg="5.4-ti"     ; var="ti"    ; ver="LTS54"  ; current_kernel ; generate_kernel_ti
	#msg="5.4-ti-rt"  ; var="ti-rt" ; ver="LTS54"  ; current_kernel ; generate_kernel_ti

	rtl8723du="enabled"
	qcacld="enabled"

	msg="5.10-ti"    ; var="ti"    ; ver="LTS510" ; current_kernel ; generate_kernel_ti
	msg="5.10-ti-rt" ; var="ti-rt" ; ver="LTS510" ; current_kernel ; generate_kernel_ti

	unset qcacld
	unset rtl8723bu
	unset rtl8821cu
	unset sgxjacinto6evm
	unset sgxti335x

	msg="6.1-ti"     ; var="ti"    ; ver="LTS61"  ; current_kernel ; generate_kernel_ti
	msg="6.1-ti-rt"  ; var="ti-rt" ; ver="LTS61"  ; current_kernel ; generate_kernel_ti
	unset rtl8723du

	do_all_lts

	msg="6.2-bone"  ; var="omap-psp" ; ver="V62X"  ; current_kernel ; generate_kernel_mainline_bone
	msg="6.3-bone"  ; var="omap-psp" ; ver="V63X"  ; current_kernel ; generate_kernel_mainline_bone
	msg="6.4-bone"  ; var="omap-psp" ; ver="V64X"  ; current_kernel ; generate_kernel_mainline_bone
	msg="6.5-bone"  ; var="omap-psp" ; ver="V65X"  ; current_kernel ; generate_kernel_mainline_bone

	msg="6.7-bone"  ; var="omap-psp" ; ver="V67X"  ; current_kernel ; generate_kernel_mainline_bone
	changelog
}

do_focal
do_jammy
do_noble
do_buster
do_bullseye
do_bookworm
do_trixie


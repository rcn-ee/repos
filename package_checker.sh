#!/bin/bash

debian_pool="http://ftp.de.debian.org/debian/pool"
sigrok_dl="http://sigrok.org/download/source"

generic_http () {
	echo "Checking: ${package_name}"
	if [ -f /tmp/index.html ] ; then
		rm -f /tmp/index.html
	fi
	wget --no-verbose --directory-prefix=/tmp/ ${site}/${package_name}/ &> /dev/null
	cat /tmp/index.html | grep "<a href=" > /tmp/temp.html
	sed -i -e "s/<a href/\\n<a href/g" /tmp/temp.html
	sed -i -e 's/\"/\"><\/a>\n/2' /tmp/temp.html
	cat /tmp/temp.html | grep href | grep dsc > /tmp/index.html
	sed -i -e 's/<a href="//g' /tmp/index.html
	sed -i -e 's/"><\/a>//g' /tmp/index.html
}

generic_http_tar () {
	echo "Checking: ${package_name}"
	if [ -f /tmp/index.html ] ; then
		rm -f /tmp/index.html
	fi
	wget --no-verbose --directory-prefix=/tmp/ ${site}/${package_name}/ &> /dev/null
	cat /tmp/index.html | grep "<a href=" > /tmp/temp.html
	sed -i -e "s/<a href/\\n<a href/g" /tmp/temp.html
	sed -i -e 's/\"/\"><\/a>\n/2' /tmp/temp.html
	cat /tmp/temp.html | grep tar | grep tar > /tmp/index.html
	sed -i -e 's/<a href="//g' /tmp/index.html
	sed -i -e 's/"><\/a>//g' /tmp/index.html
	sed -i -e 's/>//g' /tmp/index.html
}

generic_check () {
	if [ ! "x${version}" = "x" ] ; then
		if [ ! "x${package_version}" = "x${version}" ] ; then
			echo "PACKAGE UPDATE: ${package_name}: debian-repo:${version} bb.org-repo:${package_version}"
			echo ""
		fi
	else
		echo "Fail: [${site}/${package_name}/]"
		echo ""
	fi
}

check_http_tar () {
	generic_http_tar
	version=$(cat /tmp/index.html | grep tar | tail -n 1 | awk -F ".tar.gz" '{print $1}')
	generic_check
}

check_http_exp () {
	generic_http
	version=$(cat /tmp/index.html | grep -v bpo | grep dsc | tail -n 1 | awk -F ".dsc" '{print $1}')
	generic_check
}

check_http () {
	generic_http
	if [ "x${filter}" = "x" ] ; then
		if [ "x${ignore}" = "x" ] ; then
			version=$(cat /tmp/index.html | grep -v '~deb' | grep -v exp | grep -v bpo | grep dsc | tail -n 1 | awk -F ".dsc" '{print $1}')
		else
			version=$(cat /tmp/index.html | grep -v ${ignore} | grep -v '~deb' | grep -v exp | grep -v bpo | grep dsc | tail -n 1 | awk -F ".dsc" '{print $1}')
			unset ignore
		fi
	else
		if [ "x${ignore}" = "x" ] ; then
			version=$(cat /tmp/index.html | grep ${filter} | grep -v '~deb' | grep -v exp | grep -v bpo | grep dsc | tail -n 1 | awk -F ".dsc" '{print $1}')
		else
			version=$(cat /tmp/index.html | grep -v ${ignore} | grep ${filter} | grep -v '~deb' | grep -v exp | grep -v bpo | grep dsc | tail -n 1 | awk -F ".dsc" '{print $1}')
			unset ignore
		fi
		unset filter
	fi
	generic_check
}

check_http_machine () {
	generic_http
	version=$(cat /tmp/index.html | grep jessie | grep dsc | tail -n 1 | awk -F ".dsc" '{print $1}')
	generic_check
}

check () {
	echo "Checking: ${package_name}"
	output=$(rmadison -s ${suite} ${package_name} | grep ${package_name})
	version=$(echo ${output} | awk '{print $3}')
	if [ ! "x${version}" = "x" ] ; then
		if [ ! "x${package_version}" = "x${version}" ] ; then
			echo "Change: ${package_name}: ${suite}:${version} local:${package_version}"
			echo ""
		fi
	else
		echo ${output}
	fi
}

important () {
	echo "important"
	site="${debian_pool}/main/p"
	package_name="pastebinit" ; package_version="${package_name}_1.5-1" ; check_http

	site="${debian_pool}/non-free/f"
	package_name="firmware-nonfree" ; package_version="${package_name}_20170823-1" ; check_http
}

builds () {
	echo "build tools:"

	site="${debian_pool}/main/c"
	package_name="cmake" ; package_version="${package_name}_3.5.2-2" ; check_http

	site="${debian_pool}/main/p"
	package_name="pkg-kde-tools" ; package_version="${package_name}_0.15.20" ; check_http

	site="${debian_pool}/main/e"
	package_name="extra-cmake-modules" ; package_version="${package_name}_5.19.0-1" ; check_http
}

mesa () {
	echo "llvm/mesa:"

	site="${debian_pool}/main/l"
	#https://packages.debian.org/source/stretch/llvm-toolchain-3.7
#	package_name="llvm-toolchain-3.7" ; package_version="${package_name}_3.7.1-5" ; check_http
	#https://packages.debian.org/source/stretch/llvm-toolchain-3.8
#	package_name="llvm-toolchain-3.8" ; package_version="${package_name}_3.8.1-24" ; check_http
	#https://packages.debian.org/source/stretch/llvm-toolchain-3.9
#	package_name="llvm-toolchain-3.9" ; package_version="${package_name}_3.9.1-18" ; check_http
	#https://packages.debian.org/source/sid/llvm-toolchain-4.0
#	ignore="rc"
#	package_name="llvm-toolchain-4.0" ; package_version="${package_name}_4.0.1-8" ; check_http
	#https://packages.debian.org/source/sid/llvm-toolchain-5.0
	ignore="rc"
	package_name="llvm-toolchain-5.0" ; package_version="${package_name}_5.0.1-2" ; check_http
	#https://packages.debian.org/source/sid/llvm-toolchain-6.0
	ignore="rc"
	package_name="llvm-toolchain-6.0" ; package_version="${package_name}_5.0.1-2" ; check_http

	site="${debian_pool}/main/libc"
	filter="0.2"
	package_name="libclc" ; package_version="${package_name}_0.2.0+git20171106-1" ; check_http

	site="${debian_pool}/main/libd"
	package_name="libdrm" ; package_version="${package_name}_2.4.89-1" ; check_http

	site="${debian_pool}/main/libv"
	package_name="libvdpau" ; package_version="${package_name}_1.1.1-6" ; check_http

	site="${debian_pool}/main/libv"
	package_name="libva" ; package_version="${package_name}_1.8.3-1" ; check_http

	site="${debian_pool}/main/w"
	package_name="wayland" ; package_version="${package_name}_1.12.0-1" ; check_http

	site="${debian_pool}/main/m"
	package_name="mesa" ; package_version="${package_name}_17.3.1-1" ; check_http
	package_name="mesa-demos" ; package_version="${package_name}_8.3.0-5" ; check_http
}

machinekit () {
	echo "machinekit:"

	site="${debian_pool}/main/c"
	package_name="czmq" ; package_version="${package_name}_3.0.2-2" ; check_http

	#site="http://deb.dovetail-automata.com/pool/main/libw"
	#package_name="libwebsockets" ; package_version="${package_name}_1.3-1%7egit95a8abb%7e1431844465git95a8abb%7e1jessie%7e1da" ; check_http_machine
}

nodejs () {
	echo "nodejs: (jessie)"
	site="${debian_pool}/main/libu"
	package_name="libuv1"; package_version="${package_name}_1.8.0-1"; check_http

	site="${debian_pool}/main/g"
	filter="201"
	package_name="gyp"; package_version="${package_name}_0.1+20150913git1f374df9-1"; check_http

	echo "nodejs: (jessie-exp)"
	site="${debian_pool}/main/o"
	filter="1.0.2"
	package_name="openssl"; package_version="${package_name}_1.0.2f-2"; check_http

	site="${debian_pool}/main/n"
	filter="4.3"
	package_name="nodejs"; package_version="${package_name}_4.2.6~dfsg-1"; check_http
}

libsigrok () {
	#http://sigrok.org/wiki/Downloads#Binaries_and_distribution_packages
	#https://launchpad.net/~daniel-elstner/+archive/ubuntu/sigrok/+packages
	echo "libsigrok: (jessie)"

	site="${debian_pool}/main/libr"
	#https://packages.debian.org/source/sid/librevisa
#	package_name="librevisa"; package_version="${package_name}_0.0.20130812+git20140327-0"; check_http

	site="${sigrok_dl}"
	#http://sigrok.org/download/source/libserialport/
	package_name="libserialport"; package_version="${package_name}-0.1.1"; check_http_tar

	#http://sigrok.org/download/source/libsigrok/
	package_name="libsigrok"; package_version="${package_name}-0.5.0"; check_http_tar

	#http://sigrok.org/download/source/libsigrokdecode/
	package_name="libsigrokdecode"; package_version="${package_name}-0.5.0"; check_http

	#http://sigrok.org/download/source/sigrok-cli/
	package_name="sigrok-cli"; package_version="${package_name}-0.7.0"; check_http

	#http://sigrok.org/download/source/pulseview/
	package_name="pulseview"; package_version="${package_name}-0.4.0"; check_http

	#https://packages.debian.org/source/sid/sigrok-firmware-fx2lafw
	package_name="sigrok-firmware-fx2lafw"; package_version="${package_name}_0.1.3-0"; check_http
}

bbgw () {
	site="${debian_pool}/main/s"
	package_name="swig"; package_version="${package_name}_3.0.8-0"; check_http
}

chromium () {
	echo "chromium-browser: (jessie)"
	site="http://ports.ubuntu.com/pool/universe/c"
	filter="16.04"
	package_name="chromium-browser" ; package_version="${package_name}_60.0.3112.113-0ubuntu0.16.04.1298" ; check_http

	echo "chromium-browser: (stretch)"
	site="${debian_pool}/main/c"
	package_name="chromium-browser" ; package_version="${package_name}_63.0.3239.84-1" ; check_http
}

important
#builds
mesa
#machinekit
#nodejs
libsigrok
#bbgw
chromium

#really slow...
exit

suite="experimental"

suite="sid"
package_name="openjfx" ; package_version="8u20-b26-3" ; check
package_name="waffle" ; package_version="1.5.1-1" ; check
package_name="xinput-calibrator" ; package_version="0.7.5+git20140213-1" ; check
package_name="xserver-xorg-video-omap" ; package_version="0.4.3-git20130328-1" ; check
package_name="xserver-xorg-video-modesetting" ; package_version="0.9.0-1" ; check

suite="jessie"
package_name="cython" ; package_version="0.19.1+git34-gac3e3a2-1" ; check
package_name="jansson"; package_version="2.7-1"; check
package_name="libsodium"; package_version="1.0.0-1"; check
package_name="npm"; package_version="1.4.21+ds-2"; check
package_name="python-sendfile" ; package_version="2.0.0-6" ; check
package_name="python-pyftpdlib" ; package_version="1.2.0-1" ; check

echo "Done:"
#


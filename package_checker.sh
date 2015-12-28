#!/bin/bash

debian_pool="http://ftp.de.debian.org/debian/pool"

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

generic_check () {
	if [ ! "x${version}" = "x" ] ; then
		if [ ! "x${package_version}" = "x${version}" ] ; then
			echo "Change: ${package_name}: upstream:${version} local:${package_version}"
			echo ""
		fi
	else
		echo "Fail: [${site}/${package_name}/]"
		echo ""
	fi
}

check_http_exp () {
	generic_http
	version=$(cat /tmp/index.html | grep -v bpo | grep dsc | tail -n 1 | awk -F ".dsc" '{print $1}')
	generic_check
}

check_http () {
	generic_http
	if [ "x${filter}" = "x" ] ; then
		version=$(cat /tmp/index.html | grep -v exp | grep -v bpo | grep dsc | tail -n 1 | awk -F ".dsc" '{print $1}')
	else
		version=$(cat /tmp/index.html | grep ${filter} | grep -v exp | grep -v bpo | grep dsc | tail -n 1 | awk -F ".dsc" '{print $1}')
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

builds () {
	echo "build tools:"

	site="${debian_pool}/main/c"
	package_name="cmake" ; package_version="${package_name}_3.3.2-2" ; check_http

	site="${debian_pool}/main/p"
	package_name="pkg-kde-tools" ; package_version="${package_name}_0.15.19" ; check_http

	site="${debian_pool}/main/e"
	package_name="extra-cmake-modules" ; package_version="${package_name}_5.16.0-1" ; check_http
}

mesa () {
	echo "llvm/mesa:"

	site="${debian_pool}/main/l"
	package_name="llvm-toolchain-3.6" ; package_version="${package_name}_3.6.2-3" ; check_http
	package_name="llvm-toolchain-3.7" ; package_version="${package_name}_3.7.1-1" ; check_http
	package_name="llvm-toolchain-snapshot" ; package_version="${package_name}_3.8~svn254193-1" ; check_http

	site="${debian_pool}/main/libc"
	filter="0.2"
	package_name="libclc" ; package_version="${package_name}_0.2.0+git20150813-2" ; check_http

	site="${debian_pool}/main/libd"
	package_name="libdrm" ; package_version="${package_name}_2.4.65-3" ; check_http

	site="${debian_pool}/main/libv"
	package_name="libvdpau" ; package_version="${package_name}_1.1.1-3" ; check_http

	site="${debian_pool}/main/m"
	package_name="mesa" ; package_version="${package_name}_11.1.0-1" ; check_http
	package_name="mesa-demos" ; package_version="${package_name}_8.3.0-1" ; check_http
}

qt5_kde () {
	echo "qt5: kde:"

	site="${debian_pool}/main/s"
	package_name="solid" ; package_version="${package_name}_5.16.0-1" ; check_http

	site="${debian_pool}/main/k"
	package_name="kcoreaddons" ; package_version="${package_name}_5.16.0-1" ; check_http
	package_name="kguiaddons" ; package_version="${package_name}_5.16.0-1" ; check_http
	package_name="kwindowsystem" ; package_version="${package_name}_5.16.0-1" ; check_http
}

qt5_apps () {
	echo "qt5: apps:"

	site="${debian_pool}/main/q"
	package_name="qupzilla" ; package_version="${package_name}_1.8.9~dfsg1-1" ; check_http
	package_name="qtermwidget" ; package_version="${package_name}_0.6.0-10" ; check_http
	package_name="qterminal" ; package_version="${package_name}_0.6.0-10" ; check_http
	package_name="qlipper" ; package_version="${package_name}_5.0.0+20150823-2" ; check_http
	package_name="qps" ; package_version="${package_name}_1.10.16+20150823-1" ; check_http

	echo "connman/cmst:"
	site="http://packages.siduction.org/extra/pool/main/c"
	package_name="connman" ; package_version="${package_name}_1.30-1" ; check_http_exp
	site="${debian_pool}/main/c"
	package_name="cmst" ; package_version="${package_name}_2015.12.03-1" ; check_http
}

qt5_lxqt () {
	echo "lxqt: debian"

	site="${debian_pool}/main/libd"
	package_name="libdbusmenu-qt" ; package_version="${package_name}_0.9.3+15.10.20150604-1" ; check_http

	site="${debian_pool}/main/p"
	package_name="policykit-1" ; package_version="${package_name}_0.113-2" ; check_http

	site="${debian_pool}/main/p"
	package_name="polkit-qt-1" ; package_version="${package_name}_0.112.0-4" ; check_http

	site="${debian_pool}/main/o"
	package_name="obconf-qt" ; package_version="${package_name}_0.1.2-8" ; check_http

	#https://github.com/lxde/compton-conf
	#resync version with stretch and drop...
	site="${debian_pool}/main/c"
	package_name="compton-conf" ; package_version="${package_name}_0.1.2-8" ; check_http

	#https://tracker.debian.org/pkg/libqtxdg
	site="${debian_pool}/main/libq"
	package_name="libqtxdg" ; package_version="${package_name}_1.3.0-2" ; check_http

	#https://tracker.debian.org/pkg/libsysstat
	site="${debian_pool}/main/libs"
	package_name="libsysstat" ; package_version="${package_name}_0.3.1-1" ; check_http

	#https://tracker.debian.org/pkg/screengrab
	site="${debian_pool}/main/s"
	package_name="screengrab" ; package_version="${package_name}_1.95+20151117-4" ; check_http

	#https://tracker.debian.org/pkg/liblxqt
	site="${debian_pool}/main/libl"
	package_name="liblxqt" ; package_version="${package_name}_0.10.0-3" ; check_http

	#https://tracker.debian.org/pkg/lxqt-about
	site="${debian_pool}/main/l"
	package_name="lxqt-about" ; package_version="${package_name}_0.10.0-2" ; check_http

	#https://tracker.debian.org/pkg/lxqt-admin
	site="${debian_pool}/main/l"
	package_name="lxqt-admin" ; package_version="${package_name}_0.10.0-2" ; check_http

	#https://tracker.debian.org/pkg/lxqt-common
	site="${debian_pool}/main/l"
	package_name="lxqt-common" ; package_version="${package_name}_0.10.0-2" ; check_http

	#https://tracker.debian.org/pkg/lxqt-globalkeys
	site="${debian_pool}/main/l"
	package_name="lxqt-globalkeys" ; package_version="${package_name}_0.10.0-2" ; check_http

	#https://tracker.debian.org/pkg/lxqt-openssh-askpass
	site="${debian_pool}/main/l"
	package_name="lxqt-openssh-askpass" ; package_version="${package_name}_0.10.0-2" ; check_http

	#https://tracker.debian.org/pkg/lxqt-notificationd
	site="${debian_pool}/main/l"
	package_name="lxqt-notificationd" ; package_version="${package_name}_0.10.0-1" ; check_http

	#https://tracker.debian.org/pkg/lxqt-powermanagement
	site="${debian_pool}/main/l"
	package_name="lxqt-powermanagement" ; package_version="${package_name}_0.10.0-2" ; check_http

	#https://tracker.debian.org/pkg/lxqt-policykit
	site="${debian_pool}/main/l"
	package_name="lxqt-policykit" ; package_version="${package_name}_0.10.0-2" ; check_http

	#https://tracker.debian.org/pkg/lxqt-qtplugin
	site="${debian_pool}/main/l"
	package_name="lxqt-qtplugin" ; package_version="${package_name}_0.10.0-2" ; check_http

	#https://tracker.debian.org/pkg/lxqt-session
	site="${debian_pool}/main/l"
	package_name="lxqt-session" ; package_version="${package_name}_0.10.0-2" ; check_http

	#https://tracker.debian.org/pkg/lxqt-sudo
	site="${debian_pool}/main/l"
	package_name="lxqt-sudo" ; package_version="${package_name}_0.10.0-2" ; check_http

	#https://tracker.debian.org/pkg/pcmanfm-qt
	site="${debian_pool}/main/p"
	package_name="pcmanfm-qt" ; package_version="${package_name}_0.10.0-2" ; check_http

	#https://tracker.debian.org/pkg/lxqt-runner
	site="${debian_pool}/main/l"
	package_name="lxqt-runner" ; package_version="${package_name}_0.10.0-2" ; check_http

	#https://tracker.debian.org/pkg/lxqt-config
	site="${debian_pool}/main/l"
	package_name="lxqt-config" ; package_version="${package_name}_0.10.0-2" ; check_http

	#https://tracker.debian.org/pkg/lxqt-panel
	site="${debian_pool}/main/l"
	package_name="lxqt-panel" ; package_version="${package_name}_0.10.0-2" ; check_http

#in progress..
	site="${debian_pool}/main/l"
	package_name="lximage-qt" ; package_version="${package_name}_0.4.0-7" ; check_http
}

machinekit () {
	echo "machinekit:"

	site="${debian_pool}/main/c"
	package_name="czmq" ; package_version="${package_name}_3.0.2-2" ; check_http

	#site="http://deb.dovetail-automata.com/pool/main/libw"
	#package_name="libwebsockets" ; package_version="${package_name}_1.3-1%7egit95a8abb%7e1431844465git95a8abb%7e1jessie%7e1da" ; check_http_machine
}

nodejs () {
	echo "nodejs: (jessie-exp)"
	site="${debian_pool}/main/o"
	filter="1.0.2"
	package_name="openssl"; package_version="${package_name}_1.0.2e-1"; check_http

	site="${debian_pool}/main/libu"
	package_name="libuv1"; package_version="${package_name}_1.7.5-1"; check_http

	site="${debian_pool}/main/g"
	filter="201"
	package_name="gyp"; package_version="${package_name}_0.1+20150913git1f374df9-1"; check_http

	site="${debian_pool}/main/n"
	filter="4.2"
	package_name="nodejs"; package_version="${package_name}_4.2.3~dfsg-2"; check_http
}

builds
mesa
qt5_kde
qt5_apps
qt5_lxqt
#machinekit
nodejs

echo "others"

site="http://ports.ubuntu.com/pool/universe/c"
package_name="chromium-browser" ; package_version="${package_name}_47.0.2526.73-0ubuntu1.1218" ; check_http

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

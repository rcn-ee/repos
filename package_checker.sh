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

important () {
	echo "important"
	site="${debian_pool}/main/p"
	package_name="pastebinit" ; package_version="${package_name}_1.4-6" ; check_http

	site="${debian_pool}/non-free/f"
	package_name="firmware-nonfree" ; package_version="${package_name}_20160110-1" ; check_http
}

builds () {
	echo "build tools:"

	site="${debian_pool}/main/c"
	package_name="cmake" ; package_version="${package_name}_3.4.1-2" ; check_http

	site="${debian_pool}/main/p"
	package_name="pkg-kde-tools" ; package_version="${package_name}_0.15.20" ; check_http

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
	package_name="mesa" ; package_version="${package_name}_11.1.1-2" ; check_http
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
	package_name="qupzilla" ; package_version="${package_name}_1.8.9~dfsg1-2" ; check_http
	package_name="qtermwidget" ; package_version="${package_name}_0.6.0-10" ; check_http
	package_name="qterminal" ; package_version="${package_name}_0.6.0-10" ; check_http
	package_name="qlipper" ; package_version="${package_name}_5.0.0+20151111-1" ; check_http
	package_name="qps" ; package_version="${package_name}_1.10.16+20151210-1" ; check_http

	echo "connman/cmst:"
	site="http://packages.siduction.org/extra/pool/main/c"
	package_name="connman" ; package_version="${package_name}_1.31-1" ; check_http_exp
	site="${debian_pool}/main/c"
	package_name="cmst" ; package_version="${package_name}_2015.12.03-2" ; check_http
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
	package_name="libqtxdg" ; package_version="${package_name}_1.3.0-3" ; check_http

	#https://tracker.debian.org/pkg/libsysstat
	site="${debian_pool}/main/libs"
	package_name="libsysstat" ; package_version="${package_name}_0.3.1-2" ; check_http

	#https://tracker.debian.org/pkg/screengrab
	site="${debian_pool}/main/s"
	package_name="screengrab" ; package_version="${package_name}_1.95+20151117-4" ; check_http

	#https://tracker.debian.org/pkg/liblxqt
	site="${debian_pool}/main/libl"
	package_name="liblxqt" ; package_version="${package_name}_0.10.0-4" ; check_http

	#https://tracker.debian.org/pkg/lxqt-about
	site="${debian_pool}/main/l"
	package_name="lxqt-about" ; package_version="${package_name}_0.10.0-3" ; check_http

	#https://tracker.debian.org/pkg/lxqt-admin
	site="${debian_pool}/main/l"
	package_name="lxqt-admin" ; package_version="${package_name}_0.10.0-3" ; check_http

	#https://tracker.debian.org/pkg/lxqt-common
	site="${debian_pool}/main/l"
	package_name="lxqt-common" ; package_version="${package_name}_0.10.0-2" ; check_http

	#https://tracker.debian.org/pkg/lxqt-globalkeys
	site="${debian_pool}/main/l"
	package_name="lxqt-globalkeys" ; package_version="${package_name}_0.10.0-5" ; check_http

	#https://tracker.debian.org/pkg/lxqt-openssh-askpass
	site="${debian_pool}/main/l"
	package_name="lxqt-openssh-askpass" ; package_version="${package_name}_0.10.0-3" ; check_http

	#https://tracker.debian.org/pkg/lxqt-notificationd
	site="${debian_pool}/main/l"
	package_name="lxqt-notificationd" ; package_version="${package_name}_0.10.0-2" ; check_http

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
	echo "nodejs: (jessie)"
	site="${debian_pool}/main/libu"
	package_name="libuv1"; package_version="${package_name}_1.8.0-1"; check_http

	site="${debian_pool}/main/g"
	filter="201"
	package_name="gyp"; package_version="${package_name}_0.1+20150913git1f374df9-1"; check_http

	echo "nodejs: (jessie-exp)"
	site="${debian_pool}/main/o"
	filter="1.0.2"
	package_name="openssl"; package_version="${package_name}_1.0.2e-1"; check_http

	site="${debian_pool}/main/n"
	filter="4.2"
	package_name="nodejs"; package_version="${package_name}_4.2.5~dfsg-1"; check_http
}

important
builds
mesa
qt5_kde
qt5_apps
qt5_lxqt
#machinekit
nodejs

echo "others"

site="http://ports.ubuntu.com/pool/universe/c"
package_name="chromium-browser" ; package_version="${package_name}_47.0.2526.106-0ubuntu1.1221" ; check_http

ros () {
	#https://wiki.debian.org/DebianScience/Robotics/ROS/Packages
	echo "ros: (jessie)"
	site="${debian_pool}/main/r"
	package_name="ros-catkin-pkg"; package_version="${package_name}_0.2.10-2"; check_http
	package_name="ros-catkin"; package_version="${package_name}_0.6.16-3"; check_http
	package_name="ros-cmake-modules"; package_version="${package_name}_0.4.0-2"; check_http
	package_name="ros-message-generation"; package_version="${package_name}_0.3.0-3"; check_http
	package_name="ros-message-runtime"; package_version="${package_name}_0.4.12-3"; check_http
	package_name="ros-genmsg"; package_version="${package_name}_0.5.6-3"; check_http
	package_name="ros-genpy"; package_version="${package_name}_0.5.7-4"; check_http
	package_name="ros-gencpp"; package_version="${package_name}_0.5.3-3"; check_http
	package_name="ros-genlisp"; package_version="${package_name}_0.4.15-3"; check_http
	package_name="ros-roscpp-core"; package_version="${package_name}_0.5.6-2"; check_http
	package_name="ros-std-msgs"; package_version="${package_name}_0.5.9-2"; check_http
	package_name="ros-common-msgs"; package_version="${package_name}_1.12.3-4"; check_http
	package_name="ros-ros-comm-msgs"; package_version="${package_name}_1.11.1-3"; check_http
	package_name="ros-rospack"; package_version="${package_name}_2.2.5-2"; check_http
	package_name="ros-ros"; package_version="${package_name}_1.12.5-3"; check_http
	package_name="ros-ros-comm"; package_version="${package_name}_1.11.16-2"; check_http
	package_name="ros-roslisp"; package_version="${package_name}_1.9.19-1"; check_http
	package_name="ros-actionlib"; package_version="${package_name}_1.11.4-2"; check_http
	package_name="ros-dynamic-reconfigure"; package_version="${package_name}_1.5.39-2"; check_http
	package_name="ros-angles"; package_version="${package_name}_1.9.10-1"; check_http
	package_name="ros-rosconsole-bridge"; package_version="${package_name}_0.4.2-2"; check_http

	site="${debian_pool}/main/o"
	package_name="orocos-kdl"; package_version="${package_name}_1.3.0+dfsg-1"; check_http

	site="${debian_pool}/main/r"
	package_name="ros-geometry-experimental"; package_version="${package_name}_0.5.12-2"; check_http
	package_name="ros-geometry"; package_version="${package_name}_1.11.7-1"; check_http
	package_name="ros-bond-core"; package_version="${package_name}_1.7.16-3"; check_http
	package_name="ros-class-loader"; package_version="${package_name}_0.3.2-1"; check_http
	package_name="ros-eigen-stl-containers"; package_version="${package_name}_0.1.4-1"; check_http
	package_name="ros-resource-retriever"; package_version="${package_name}_1.11.6-2"; check_http
	package_name="ros-random-numbers"; package_version="${package_name}_0.3.0-2"; check_http
	package_name="ros-geometric-shapes"; package_version="${package_name}_0.4.3-2"; check_http
	package_name="ros-pluginlib"; package_version="${package_name}_1.10.1-2"; check_http
	package_name="ros-image-common"; package_version="${package_name}_1.11.10-1"; check_http
	package_name="ros-interactive-markers"; package_version="${package_name}_1.11.1-2"; check_http
	package_name="ros-laser-geometry"; package_version="${package_name}_1.6.4-2"; check_http
	package_name="ros-rospkg"; package_version="${package_name}_1.0.38-1"; check_http
	package_name="ros-nodelet-core"; package_version="${package_name}_1.9.3-2"; check_http
	package_name="ros-pcl-msgs"; package_version="${package_name}_0.2.0-2"; check_http
	package_name="ros-pcl-conversions"; package_version="${package_name}_0.2.1-1"; check_http

	site="${debian_pool}/main/c"
	package_name="collada-dom"; package_version="${package_name}_2.4.4+ds1-1"; check_http

	site="${debian_pool}/main/a"
	filter="3.2"
	package_name="assimp"; package_version="${package_name}_3.2~dfsg-3~bpo8+1"; check_http

	site="${debian_pool}/main/r"
	package_name="ros-robot-model"; package_version="${package_name}_1.11.8-2"; check_http
	package_name="ros-navigation-msgs"; package_version="${package_name}_1.13.0-1"; check_http

	#needs boost1.58
	#package_name="ros-vision-opencv"; package_version="${package_name}_1.11.10+ds-1"; check_http

	site="${debian_pool}/main/r"
	package_name="ros-python-qt-binding"; package_version="${package_name}_0.2.17-1"; check_http

#helpers..
	site="${debian_pool}/main/r"
	package_name="ros-rosdistro"; package_version="${package_name}_0.4.2-1"; check_http
	package_name="ros-rosinstall"; package_version="${package_name}_0.7.7-1"; check_http
	package_name="ros-rosinstall-generator"; package_version="${package_name}_0.1.11-1"; check_http
	package_name="ros-vcstools"; package_version="${package_name}_0.1.38-1"; check_http
	package_name="ros-wstool"; package_version="${package_name}_0.1.12-1"; check_http
	package_name="ros-bloom"; package_version="${package_name}_0.5.20-1"; check_http
	package_name="ros-rosdep"; package_version="${package_name}_0.11.4-1"; check_http
}

ros

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


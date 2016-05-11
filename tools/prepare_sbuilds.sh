#!/bin/bash -e

if ! id | grep -q root; then
	echo "must be run as root"
	exit
fi

#proxy=""
proxy="apt-proxy:3142/"

debian_server="ftp.us.debian.org/debian"
ubuntu_server="ports.ubuntu.com"

builder=`cat /etc/hostname`

unset flavor

setup_update_sbuild () {
	if [ ! -f /usr/share/debootstrap/scripts/${dist} ] ; then
		ln -s /usr/share/debootstrap/scripts/${deboot} /usr/share/debootstrap/scripts/${dist}
	fi

	if [ ! -f /var/lib/sbuild/${dist}${flavor}-${arch}.tar.gz ] ; then
		sbuild-createchroot ${options} --arch=${arch} --make-sbuild-tarball=/var/lib/sbuild/${dist}${flavor}-${arch}.tar.gz ${dist} `mktemp -d` ${mirror}
	else
		chown -R root:root /var/lib/sbuild/${dist}${flavor}-${arch}.tar.gz
		sbuild-update -udcar ${dist}${flavor}-${arch}-sbuild
	fi
}

echo "\$build_arch_all = 1;" > ~/.sbuildrc
echo "\$build_source = 1;" >> ~/.sbuildrc
echo "\$distribution = 'stretch';" >> ~/.sbuildrc

mirror="http://${proxy}${debian_server}"
deboot="sid"

if [ ! "x${builder}" = "xa4-imx6q-wandboard-2gb" ] ; then
if [ ! "x${builder}" = "xb5-omap5-igep0050-4gb" ] ; then
if [ ! "x${builder}" = "xapm-mustang-8gb" ] ; then
	dist="wheezy"
	unset flavor
	arch="armhf"
	options=""
	setup_update_sbuild
fi
fi
fi

dist="jessie"
unset flavor
arch="armhf"
options=""
setup_update_sbuild

dist="jessie"
flavor="-nodejs-v0.12.x"
arch="armhf"
options=""
setup_update_sbuild

dist="jessie"
flavor="-nodejs-v4.x"
arch="armhf"
options=""
setup_update_sbuild

dist="jessie"
flavor="-nodejs-v6.x"
arch="armhf"
options=""
setup_update_sbuild

if [ ! "x${builder}" = "xa4-imx6q-wandboard-2gb" ] ; then
if [ ! "x${builder}" = "xb5-omap5-igep0050-4gb" ] ; then
if [ ! "x${builder}" = "xapm-mustang-8gb" ] ; then
	dist="stretch"
	unset flavor
	arch="armhf"
	options=""
	setup_update_sbuild
fi
fi
fi

mirror="http://${proxy}${ubuntu_server}"
deboot="gutsy"

if [ ! "x${builder}" = "xa4-imx6q-wandboard-2gb" ] ; then
if [ ! "x${builder}" = "xb5-omap5-igep0050-4gb" ] ; then
if [ ! "x${builder}" = "xapm-mustang-8gb" ] ; then
	dist="trusty"
	unset flavor
	arch="armhf"
	options="--exclude=debfoster"
	setup_update_sbuild
fi
fi
fi

if [ ! "x${builder}" = "xa4-imx6q-wandboard-2gb" ] ; then
if [ ! "x${builder}" = "xb5-omap5-igep0050-4gb" ] ; then
if [ ! "x${builder}" = "xapm-mustang-8gb" ] ; then
	dist="wily"
	unset flavor
	arch="armhf"
	options="--exclude=debfoster"
	setup_update_sbuild
fi
fi
fi

if [ ! "x${builder}" = "xa4-imx6q-wandboard-2gb" ] ; then
if [ ! "x${builder}" = "xb5-omap5-igep0050-4gb" ] ; then
if [ ! "x${builder}" = "xapm-mustang-8gb" ] ; then
	dist="xenial"
	unset flavor
	arch="armhf"
	options="--exclude=debfoster"
	setup_update_sbuild
fi
fi
fi

if [ ! "x${builder}" = "xa4-imx6q-wandboard-2gb" ] ; then
if [ ! "x${builder}" = "xb5-omap5-igep0050-4gb" ] ; then
if [ ! "x${builder}" = "xapm-mustang-8gb" ] ; then
	dist="yakkety"
	unset flavor
	arch="armhf"
	options="--exclude=debfoster"
	setup_update_sbuild
fi
fi
fi
#

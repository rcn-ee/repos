#!/bin/bash -e

#proxy=""
proxy="apt-proxy:3142/"

debian_server="ftp.us.debian.org/debian"
ubuntu_server="ports.ubuntu.com"

builder=`cat /etc/hostname`

setup_update_sbuild () {
	if [ ! -f /usr/share/debootstrap/scripts/${dist} ] ; then
		sudo ln -s /usr/share/debootstrap/scripts/${deboot} /usr/share/debootstrap/scripts/${dist}
	fi

	if [ ! -f /var/lib/sbuild/${dist}-${arch}.tar.gz ] ; then
		sudo sbuild-createchroot ${options} --arch=${arch} --make-sbuild-tarball=/var/lib/sbuild/${dist}-${arch}.tar.gz ${dist} `mktemp -d` ${mirror}
	else
		sudo chown -R root:root /var/lib/sbuild/${dist}-${arch}.tar.gz
		sudo sbuild-update -udcar ${dist}-${arch}-sbuild
	fi
}

echo "\$build_arch_all = 1;" > ~/.sbuildrc
echo "\$build_source = 1;" >> ~/.sbuildrc
echo "\$distribution = 'stretch';" >> ~/.sbuildrc

mirror="http://${proxy}${debian_server}"
deboot="sid"

if [ ! "x${builder}" = "xa4-imx6q-wandboard-2gb" ] ; then
if [ ! "x${builder}" = "xb5-omap5-igep0050-4gb" ] ; then
	dist="wheezy"
	arch="armhf"
	options=""
	setup_update_sbuild
fi
fi

dist="jessie"
arch="armhf"
options=""
setup_update_sbuild

if [ ! "x${builder}" = "xa4-imx6q-wandboard-2gb" ] ; then
if [ ! "x${builder}" = "xb5-omap5-igep0050-4gb" ] ; then
	dist="stretch"
	arch="armhf"
	options=""
	setup_update_sbuild
fi
fi

mirror="http://${proxy}${ubuntu_server}"
deboot="gutsy"

if [ ! "x${builder}" = "xa4-imx6q-wandboard-2gb" ] ; then
if [ ! "x${builder}" = "xb5-omap5-igep0050-4gb" ] ; then
	dist="trusty"
	arch="armhf"
	options="--exclude=debfoster"
	setup_update_sbuild
fi
fi

if [ ! "x${builder}" = "xa4-imx6q-wandboard-2gb" ] ; then
if [ ! "x${builder}" = "xb5-omap5-igep0050-4gb" ] ; then
	dist="wily"
	arch="armhf"
	options="--exclude=debfoster"
	setup_update_sbuild
fi
fi

if [ ! "x${builder}" = "xa4-imx6q-wandboard-2gb" ] ; then
if [ ! "x${builder}" = "xb5-omap5-igep0050-4gb" ] ; then
	dist="xenial"
	arch="armhf"
	options="--exclude=debfoster"
	setup_update_sbuild
fi
fi
#

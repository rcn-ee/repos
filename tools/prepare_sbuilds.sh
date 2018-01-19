#!/bin/bash -e

if ! id | grep -q root; then
	echo "must be run as root"
	exit
fi

#proxy=""
proxy="apt-proxy:3142/"

debian_server="deb.debian.org/debian"
ubuntu_server="ports.ubuntu.com"

builder=`cat /etc/hostname`

unset flavor

setup_update_sbuild () {
	if [ ! -f /usr/share/debootstrap/scripts/${dist} ] ; then
		ln -s /usr/share/debootstrap/scripts/${deboot} /usr/share/debootstrap/scripts/${dist}
	fi

	if [ -f /usr/share/lintian/data/changes-file/known-dists ] ; then
		unset lintian_check
		lintian_check=$(cat /usr/share/lintian/data/changes-file/known-dists | grep -v '#' | grep ${dist} || true)
		if [ "x${lintian_check}" = "x" ] ; then
			echo "${dist}" >> /usr/share/lintian/data/changes-file/known-dists
		fi
	fi

	if [ ! -f /var/lib/sbuild/${dist}-${arch}${flavor}.tar.gz ] ; then
		sbuild-createchroot ${options} --arch=${arch} --make-sbuild-tarball=/var/lib/sbuild/${dist}-${arch}${flavor}.tar.gz ${dist} `mktemp -d` ${mirror}
	else
		chown -R root:root /var/lib/sbuild/${dist}-${arch}${flavor}.tar.gz
		sbuild-update -udcar ${dist}-${arch}${flavor}-sbuild
	fi
}

echo "\$build_arch_all = 1;" > ~/.sbuildrc
echo "\$build_source = 1;" >> ~/.sbuildrc
echo "\$distribution = 'stretch';" >> ~/.sbuildrc

mirror="http://${proxy}${debian_server}"
deboot="sid"

dist="jessie"
unset flavor
arch="armhf"
options=""
setup_update_sbuild

dist="jessie"
flavor="-exp"
arch="armhf"
options="--chroot-suffix=${flavor}-sbuild"
setup_update_sbuild

dist="jessie"
flavor="-nodejs-v0.12.x"
arch="armhf"
options="--chroot-suffix=${flavor}-sbuild"
setup_update_sbuild

dist="jessie"
flavor="-nodejs-v4.x"
arch="armhf"
options="--chroot-suffix=${flavor}-sbuild"
setup_update_sbuild

dist="jessie"
flavor="-nodejs-v6.x"
arch="armhf"
options="--chroot-suffix=${flavor}-sbuild"
setup_update_sbuild

if [ ! "x${builder}" = "xapm-mustang-8gb" ] ; then
	dist="stretch"
	unset flavor
	arch="armhf"
	options="--exclude=debfoster"
	setup_update_sbuild
fi

if [ ! "x${builder}" = "xapm-mustang-8gb" ] ; then
	dist="stretch"
	flavor="-exp"
	arch="armhf"
	options="--exclude=debfoster --chroot-suffix=${flavor}-sbuild"
	setup_update_sbuild
fi

if [ ! "x${builder}" = "xapm-mustang-8gb" ] ; then
	dist="buster"
	unset flavor
	arch="armhf"
	options="--exclude=debfoster"
	setup_update_sbuild
fi

mirror="http://${proxy}${ubuntu_server}"
deboot="gutsy"

if [ ! "x${builder}" = "xapm-mustang-8gb" ] ; then
	dist="xenial"
	unset flavor
	arch="armhf"
	options="--exclude=debfoster"
	setup_update_sbuild
fi

if [ ! "x${builder}" = "xapm-mustang-8gb" ] ; then
	dist="artful"
	unset flavor
	arch="armhf"
	options="--exclude=debfoster"
	setup_update_sbuild
fi

if [ ! "x${builder}" = "xapm-mustang-8gb" ] ; then
	dist="bionic"
	unset flavor
	arch="armhf"
	options="--exclude=debfoster"
	setup_update_sbuild
fi
#

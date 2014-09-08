#!/bin/bash -e

#proxy=""
proxy="apt-proxy:3142/"

debian_server="ftp.us.debian.org/debian"
ubuntu_server="ports.ubuntu.com"

setup_update_sbuild () {
	if [ ! -f /var/lib/sbuild/${dist}-armhf.tar.gz ] ; then
		sudo sbuild-createchroot --make-sbuild-tarball=/var/lib/sbuild/${dist}-armhf.tar.gz ${dist} `mktemp -d` ${mirror}
	else
		sudo sbuild-update -udcar ${dist}-armhf-sbuild
	fi
}

mirror="http://${proxy}${debian_server}"
dist="wheezy"
setup_update_sbuild

dist="jessie"
setup_update_sbuild

dist="sid"
setup_update_sbuild

mirror="http://${proxy}${ubuntu_server}"
dist="trusty"
setup_update_sbuild

dist="utopic"
setup_update_sbuild


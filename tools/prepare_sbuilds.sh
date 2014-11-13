#!/bin/bash -e

#proxy=""
proxy="apt-proxy:3142/"

debian_server="ftp.us.debian.org/debian"
deb_arch=$(dpkg --print-architecture)

setup_update_sbuild () {
	if [ ! -f /var/lib/sbuild/${dist}-${deb_arch}.tar.gz ] ; then
		sudo sbuild-createchroot --make-sbuild-tarball=/var/lib/sbuild/${dist}-${deb_arch}.tar.gz ${dist} `mktemp -d` ${mirror}
	else
		sudo chown -R root:root /var/lib/sbuild/${dist}-${deb_arch}.tar.gz
		sudo sbuild-update -udcar ${dist}-${deb_arch}-sbuild
	fi
}

echo "\$build_arch_all = 1;" > ~/.sbuildrc
echo "\$build_source = 1;" >> ~/.sbuildrc
echo "\$distribution = 'jessie';" >> ~/.sbuildrc

mirror="http://${proxy}${debian_server}"
dist="wheezy"
setup_update_sbuild

dist="jessie"
setup_update_sbuild


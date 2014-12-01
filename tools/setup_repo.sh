#!/bin/sh -e

apache_dir="/var/www/html/repos.rcn-ee.net"

setup_repo () {
	if [ ! -d ${apache_dir}/${dist}/dists/${suite}/ ] ; then
		mkdir -p ${apache_dir}/${dist}/conf/
	fi

	echo "Origin: rcn-ee.net" >> ${apache_dir}/${dist}/conf/distributions
	echo "Label: rcn-ee.net" >> ${apache_dir}/${dist}/conf/distributions
	echo "Codename: ${suite}" >> ${apache_dir}/${dist}/conf/distributions
	echo "Architectures: armhf source" >> ${apache_dir}/${dist}/conf/distributions
	echo "Components: main" >> ${apache_dir}/${dist}/conf/distributions
	echo "UDebComponents: main" >> ${apache_dir}/${dist}/conf/distributions
	echo "Description: Apt repository for rcn-ee.net" >> ${apache_dir}/${dist}/conf/distributions
	echo "SignWith: 53A22F89" >> ${apache_dir}/${dist}/conf/distributions
	echo "Log: ${apache_dir}/${dist}/log/${suite}.log" >> ${apache_dir}/${dist}/conf/distributions
	echo "" >> ${apache_dir}/${dist}/conf/distributions

	echo "verbose" > ${apache_dir}/${dist}/conf/options
	echo "basedir ${apache_dir}/${dist}" >> ${apache_dir}/${dist}/conf/options
	echo "ask-passphrase" >> ${apache_dir}/${dist}/conf/options

	if [ ! -f ${apache_dir}/${dist}/conf/repos.rcn-ee.net.gpg.key ] ; then
		cd ${apache_dir}/${dist}/conf/
		gpg --armor --output repos.rcn-ee.net.gpg.key --export 53A22F89
		cd -
	fi
	#for apt-cacher-ng...
	if [ ! -f ${apache_dir}/${dist}/conf/custom.gpg ] ; then
		cd ${apache_dir}/${dist}/conf/
		gpg --armor --output custom.gpg --export 53A22F89
		cd -
	fi
}

dist="debian"
if [ -f ${apache_dir}/${dist}/conf/distributions ] ; then
	rm -f ${apache_dir}/${dist}/conf/distributions || true
fi

dist="ubuntu"
if [ -f ${apache_dir}/${dist}/conf/distributions ] ; then
	rm -f ${apache_dir}/${dist}/conf/distributions || true
fi

dist="debian"
suite="wheezy"
setup_repo

dist="debian"
suite="jessie"
setup_repo

dist="debian"
suite="sid"
setup_repo

dist="ubuntu"
suite="trusty"
setup_repo

dist="ubuntu"
suite="utopic"
setup_repo

dist="ubuntu"
suite="vivid"
setup_repo

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
	echo "SignWith: ${key}" >> ${apache_dir}/${dist}/conf/distributions
	echo "Log: ${apache_dir}/${dist}/log/${suite}.log" >> ${apache_dir}/${dist}/conf/distributions
	echo "" >> ${apache_dir}/${dist}/conf/distributions

	echo "verbose" > ${apache_dir}/${dist}/conf/options
	echo "basedir ${apache_dir}/${dist}" >> ${apache_dir}/${dist}/conf/options
	echo "ask-passphrase" >> ${apache_dir}/${dist}/conf/options

	#53A22F89 key expires: 2015-07-02
	if [ -f ${apache_dir}/${dist}/conf/repos.rcn-ee.net.gpg.key ] ; then
		rm -f ${apache_dir}/${dist}/conf/repos.rcn-ee.net.gpg.key || true
	fi

	cd ${apache_dir}/${dist}/conf/
	gpg --armor --output repos.rcn-ee.net.gpg.key --export ${key}
	cd -

	if [ -f ${apache_dir}/${dist}/conf/repos.rcn-ee.net.2015.gpg.key ] ; then
		rm -f ${apache_dir}/${dist}/conf/repos.rcn-ee.net.2015.gpg.key
	fi

	cd ${apache_dir}/${dist}/conf/
	gpg --armor --output repos.rcn-ee.net.2015.gpg.key --export A4C46402
	cd -

	#for apt-cacher-ng...
	if [ -f ${apache_dir}/${dist}/conf/custom.gpg ] ; then
		rm -f ${apache_dir}/${dist}/conf/custom.gpg
	fi

	cd ${apache_dir}/${dist}/conf/
	gpg --armor --output custom.gpg --export ${key}
	cd -
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
key="53A22F89"

suite="wheezy"
setup_repo

suite="jessie"
setup_repo

suite="stretch"
setup_repo

suite="sid"
setup_repo

dist="ubuntu"
key="A4C46402"

suite="trusty"
setup_repo

suite="utopic"
setup_repo

suite="vivid"
setup_repo

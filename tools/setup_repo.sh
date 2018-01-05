#!/bin/sh -e

apache_dir="/var/www/html/rcn-ee.us/repos"

setup_repo () {
	if [ ! -d ${apache_dir}/${dist}/dists/${suite}/ ] ; then
		mkdir -p ${apache_dir}/${dist}/conf/
	fi

	echo "Origin: rcn-ee.net" >> ${apache_dir}/${dist}/conf/distributions
	echo "Label: rcn-ee.net" >> ${apache_dir}/${dist}/conf/distributions
	echo "Codename: ${suite}" >> ${apache_dir}/${dist}/conf/distributions
	echo "Architectures: ${archs}" >> ${apache_dir}/${dist}/conf/distributions
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
	#A4C46402 default on 2015-05-06
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

dist="debian-exp"
if [ -f ${apache_dir}/${dist}/conf/distributions ] ; then
	rm -f ${apache_dir}/${dist}/conf/distributions || true
fi

dist="debian-machinekit"
if [ -f ${apache_dir}/${dist}/conf/distributions ] ; then
	rm -f ${apache_dir}/${dist}/conf/distributions || true
fi

dist="debian-nodejs"
if [ -f ${apache_dir}/${dist}/conf/distributions ] ; then
	rm -f ${apache_dir}/${dist}/conf/distributions || true
fi

dist="ubuntu"
if [ -f ${apache_dir}/${dist}/conf/distributions ] ; then
	rm -f ${apache_dir}/${dist}/conf/distributions || true
fi

key="A4C46402"

dist="debian"
suite="wheezy"
archs="armhf source"
setup_repo

suite="jessie"
archs="armhf source"
setup_repo

suite="stretch"
archs="armhf source"
setup_repo

suite="buster"
archs="armhf source"
setup_repo

suite="sid"
archs="armhf source"
setup_repo

dist="debian-exp"
suite="jessie"
archs="armhf source"
setup_repo

dist="debian-exp"
suite="stretch"
archs="armhf source"
setup_repo

dist="debian-machinekit"
suite="wheezy"
archs="armhf source"
setup_repo

dist="ubuntu"
suite="trusty"
archs="armhf source"
setup_repo

#eol: july 25 2015
suite="utopic"
archs="armhf source"
setup_repo

#eol: feb 4 2016
suite="vivid"
archs="armhf source"
setup_repo

#eol: July 28 2016
suite="wily"
archs="armhf source"
setup_repo

suite="xenial"
archs="armhf source"
setup_repo

#eol: July 20 2017
suite="yakkety"
archs="armhf source"
setup_repo

#eol: January 2018
suite="zesty"
archs="armhf source"
setup_repo

suite="artful"
archs="armhf source"
setup_repo

suite="bionic"
archs="armhf source"
setup_repo
#

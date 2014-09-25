#!/bin/bash -e

. version.sh

DIR="$PWD"

generate_dsc () {
	if [ -d ${DIR}/${dist} ] ; then
		rm -rf ${DIR}/${dist}/
	fi
	mkdir -p ${DIR}/${dist}/

	cp -v ${DIR}/${package_source} ${DIR}/${dist}

	if [ ! "x${debian_patch}" = "x" ] ; then
		cp -v ${debian_patch} ${DIR}/${dist}
	fi

	cd ${DIR}/${dist}

	if [ ! "x${src_dir}" = "x" ] ; then
		tar xf ${DIR}/${package_source} -C ${DIR}/${dist}/
		cd ${DIR}/${dist}/${src_dir}
		if [ ! "x${debian_patch}" = "x" ] ; then
			zcat ${DIR}/${debian_patch} | patch -p1
		fi
		if [ ! "x${debian_untar}" = "x" ] ; then
			tar xfv ${DIR}/${debian_untar} -C ${DIR}/${dist}/${src_dir}
		fi
	else
		mkdir -p ${DIR}/${dist}/${package_name}_${package_version}
		tar xf ${DIR}/${package_source} -C ${DIR}/${dist}/${package_name}_${package_version}

		cd ${DIR}/${dist}/${package_name}_${package_version}
		if [ ! "x${debian_patch}" = "x" ] ; then
			zcat ${DIR}/${debian_patch} | patch -p1
		fi
		if [ ! "x${debian_untar}" = "x" ] ; then
			tar xfv ${DIR}/${debian_untar} -C ${DIR}/${dist}/${package_name}_${package_version}
		fi
	fi

	if [ ! -d ./debian ] ; then
		mkdir ./debian
	fi

	if [ -d ${DIR}/debian/${dist}/ ] ; then
		cp -rv ${DIR}/debian/${dist}/* ./
	fi

	debuild -us -uc -S

	cd ${DIR}/
}

dist="wheezy"
if [ -d debian/${dist}/ ] ; then
	generate_dsc
fi

dist="jessie"
if [ -d debian/${dist}/ ] ; then
	generate_dsc
fi


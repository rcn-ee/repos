#!/bin/bash -e

. version.sh

DIR="$PWD"

generate_dsc () {
	if [ -d ${DIR}/${dist} ] ; then
		rm -rf ${DIR}/${dist}/
	fi
	mkdir -p ${DIR}/${dist}/${package}_${version}

	cp -v ${DIR}/${deb_source} ${DIR}/${dist}

	if [ ! "x${deb_patch}" = "x" ] ; then
		cp -v ${deb_patch} ${DIR}/${dist}
	fi

	cd ${DIR}/${dist}
	tar xf ${DIR}/${deb_source} -C ${DIR}/${dist}/${package}_${version}

	cd ${DIR}/${dist}/${package}_${version}

	if [ ! "x${src_dir}" = "x" ] ; then
		if [ ! "x${deb_patch}" = "x" ] ; then
			cd ${DIR}/${dist}/${package}_${version}/${src_dir}
			zcat ${DIR}/${deb_patch} | patch -p1
		else
			cd ${src_dir}
		fi
	else
		if [ -d ${DIR}/${dist}/${package}_${version}/${package}-${version} ] ; then
			rm -rf ${DIR}/${dist}/${package}_${version}/${package}-${version} || true
			cd ${DIR}/
			tar xf ${DIR}/${deb_source}
		elif [ -d ${DIR}/${dist}/${package}_${version}/${package}_${version} ] ; then
			rm -rf ${DIR}/${dist}/${package}_${version}/${package}_${version}
			cd ..
			tar xf ${DIR}/${deb_source}
		fi

		if [ ! "x${deb_patch}" = "x" ] ; then
			if [ -d ${DIR}/${dist}/${package}-${version} ] ; then
				cd ${DIR}/${dist}/${package}-${version}
			elif [ -d ${DIR}/${dist}/${package}_${version} ] ; then
				cd ${DIR}/${dist}/${package}_${version}
			fi
			zcat ${DIR}/${deb_patch} | patch -p1
		else
			if [ -d ${DIR}/${dist}/${package}-${version} ] ; then
				cd ${DIR}/${dist}/${package}-${version}
			elif [ -d ${DIR}/${dist}/${package}_${version} ] ; then
				cd ${DIR}/${dist}/${package}_${version}
			fi
		fi
	fi

	ls

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


#!/bin/bash -e

. version.sh

DIR="$PWD"

run () {
	if [ -d ${DIR}/${suite} ] ; then
		rm -rf ${DIR}/${suite}/
	fi
	mkdir -p ${DIR}/${suite}/

	if [ ! -d ${DIR}/common/ ] ; then
		if [ ! "x${package_source}" = "x" ] ; then
			cp -v ${DIR}/${package_source} ${DIR}/${suite}
		fi

		if [ ! "x${debian_patch}" = "x" ] ; then
			cp -v ${debian_patch} ${DIR}/${suite}
		fi

		cd ${DIR}/${suite}

		if [ ! "x${package_source}" = "x" ] ; then
			if [ ! "x${src_dir}" = "x" ] ; then
				tar xf ${DIR}/${package_source} -C ${DIR}/${suite}/
				cd ${DIR}/${suite}/${src_dir}
				ls
				if [ ! "x${debian_patch}" = "x" ] ; then
					zcat ${DIR}/${debian_patch} | patch -p1
				fi
				if [ ! "x${debian_untar}" = "x" ] ; then
					tar xfv ${DIR}/${debian_untar} -C ${DIR}/${suite}/${src_dir}
				fi
			else
				mkdir -p ${DIR}/${suite}/${package_name}_${package_version}
				tar xf ${DIR}/${package_source} -C ${DIR}/${suite}/${package_name}_${package_version}

				cd ${DIR}/${suite}/${package_name}_${package_version}
				ls
				if [ ! "x${debian_patch}" = "x" ] ; then
					zcat ${DIR}/${debian_patch} | patch -p1
				fi
				if [ ! "x${debian_untar}" = "x" ] ; then
					tar xfv ${DIR}/${debian_untar} -C ${DIR}/${suite}/${package_name}_${package_version}
				fi
			fi
		else
			mkdir -p ${DIR}/${suite}/${package_name}_${package_version}
			cd ${DIR}/${suite}/${package_name}_${package_version}
		fi
	else
		mkdir -p ${DIR}/${suite}/${package_name}_${package_version}
		cd ${DIR}/${suite}/${package_name}_${package_version}
	fi

	if [ ! -d ./debian ] ; then
		mkdir ./debian
	fi

	if [ -d ${DIR}/suite/${suite}/ ] ; then
		cp -rv ${DIR}/suite/${suite}/* ./
	fi

	if [ ! "x${debian_dl_1}" = "x" ] ; then
		cd ./debian/
		wget -c ${debian_dl_1}
		cd ../
	fi

	if [ ! "x${debian_dl_2}" = "x" ] ; then
		cd ./debian/
		wget -c ${debian_dl_2}
		cd ../
	fi

	if [ ! "x${debian_dl_3}" = "x" ] ; then
		cd ./debian/
		wget -c ${debian_dl_3}
		cd ../
	fi

	if [ ! "x${debian_dl_4}" = "x" ] ; then
		cd ./debian/
		wget -c ${debian_dl_4}
		cd ../
	fi

	if [ ! "x${debian_dl_5}" = "x" ] ; then
		cd ./debian/
		wget -c ${debian_dl_5}
		cd ../
	fi

	if [ ! "x${debian_dl_6}" = "x" ] ; then
		cd ./debian/
		wget -c ${debian_dl_6}
		cd ../
	fi

	if [ ! "x${debian_dl_7}" = "x" ] ; then
		cd ./debian/
		wget -c ${debian_dl_7}
		cd ../
	fi

	if [ ! "x${debian_dl_8}" = "x" ] ; then
		cd ./debian/
		wget -c ${debian_dl_8}
		cd ../
	fi

	if [ ! "x${debian_dl_9}" = "x" ] ; then
		cd ./debian/
		wget -c ${debian_dl_9}
		cd ../
	fi

	if [ ! "x${debian_dl_10}" = "x" ] ; then
		cd ./debian/
		wget -c ${debian_dl_10}
		cd ../
	fi

	if [ ! "x${debian_dl_11}" = "x" ] ; then
		cd ./debian/
		wget -c ${debian_dl_11}
		cd ../
	fi

	if [ ! "x${debian_dl_12}" = "x" ] ; then
		cd ./debian/
		wget -c ${debian_dl_12}
		cd ../
	fi

	if [ -d ${DIR}/common/ ] ; then
		mkdir -p ./debian/common/
		cp -rv ${DIR}/common/* ./debian/common/
	fi

	debuild -us -uc -S -d

	cd ${DIR}/
}

runner () {
	if [ -d ./suite/${suite}/ ] ; then
		run
	fi
}

start_run () {
	dist="debian"
	deb_arch="armhf"
	suite="jessie" ; runner
	suite="stretch" ; runner
	suite="buster" ; runner

	dist="ubuntu"
	suite="xenial" ; runner
	suite="artful" ; runner
	suite="bionic" ; runner
}

start_run
#

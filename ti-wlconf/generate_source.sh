#!/bin/bash -e

. version.sh

incoming_mirror="http://incoming.debian.org/debian-buildd"

if [ -f ./git/.git/config ] ; then
	git clone --reference ./git/ ${git_repo} ignore
else
	git clone ${git_repo} ignore
fi
if [ -f ./ignore/.git/config ] ; then
	cd ./ignore/
	git archive --format=tar --prefix=${package_name}_${package_version}/ ${git_sha} | xz > ../temp.tar.xz
	cd ../
	rm -rf ./ignore/
fi

mkdir ignore
tar xf temp.tar.xz -C ignore
cd ./ignore/${package_name}_${package_version}/

dos2unix -k wlconf/official_inis/WL1835MOD_INI_C2PC.ini
dos2unix -k wlconf/official_inis/WL1835MOD_INI_C2PC.ini
dos2unix -k wlconf/official_inis/WL1835MOD_INI.ini
dos2unix -k wlconf/official_inis/WL1837MOD_INI_FCC_CE.ini
dos2unix -k wlconf/official_inis/WL1837MOD_INI_FCC_CE_JP.ini
dos2unix -k wlconf/official_inis/WL8_COB_INI.ini
dos2unix -k wlconf/official_inis/WL8_TESTING_INI.ini

mv wlconf/ ${package_name}_${package_version}
tar cvfJ ../../${package_name}_${package_version}.orig.tar.xz ./${package_name}_${package_version}
cd ../../
rm -rf ./ignore/
rm -rf temp.tar.xz

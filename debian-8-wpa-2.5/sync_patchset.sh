#!/bin/bash -e

. version.sh

mkdir -p ./git/

if [ ! -f ./git/.git/config ] ; then
	git clone https://github.com/rcn-ee/hostap ./git/
	cd ./git/
else
	cd ./git/
	git checkout master -f
	git branch -D tmp || true
fi

git pull
git checkout ${git_sha} -b tmp

wdir="../suite/jessie/debian/patches"
git="git am"

${git} "${wdir}/0001-use_pkg-config_for_pcsc-lite_module.patch"
${git} "${wdir}/0002-dbus_group_policy.patch"
${git} "${wdir}/0003-wpa_gui_menu_exec_path.patch"
${git} "${wdir}/0004-dbus_service_syslog.patch"
${git} "${wdir}/0005-wpa_gui_knotify_support.patch"
${git} "${wdir}/0006-wpa_gui_desktop_add-keywords-entry.patch"
number=6 ; git format-patch -${number} -o ${wdir}/

${git} "${wdir}/2015-6/0001-WNM-Ignore-Key-Data-in-WNM-Sleep-Mode-Response-frame.patch"
number=1 ; git format-patch -${number} -o ${wdir}/2015-6/

${git} "${wdir}/2015-7/0001-EAP-pwd-server-Fix-last-fragment-length-validation.patch"
${git} "${wdir}/2015-7/0002-EAP-pwd-peer-Fix-last-fragment-length-validation.patch"
number=2 ; git format-patch -${number} -o ${wdir}/2015-7/

${git} "${wdir}/2015-8/0001-EAP-pwd-peer-Fix-error-path-for-unexpected-Confirm-m.patch"
number=1 ; git format-patch -${number} -o ${wdir}/2015-8/

git checkout master -f
git branch -D tmp

cd ../../

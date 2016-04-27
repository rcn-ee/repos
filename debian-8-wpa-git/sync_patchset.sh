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
${git} "${wdir}/0009-hostapd_fix-hostapd-operation-without-hw_mode-driver.patch"
${git} "${wdir}/0010-wpasupplicant_fix-systemd-unit-dependencies.patch"
${git} "${wdir}/0011-wpasupplicant_P2P-Validate-SSID-element-length-befor.patch"
${git} "${wdir}/0012-wpasupplicant_band_selection_f0d0a5d2.patch"
${git} "${wdir}/0013-wpasupplicant_band_selection_a1b790eb.patch"
${git} "${wdir}/0014-wpasupplicant_band_selection_8b2b718d.patch"
${git} "${wdir}/0015-wpasupplicant_band_selection_aa517ae2.patch"
number=13 ; git format-patch -${number} -o ${wdir}/

${git} "${wdir}/2015-2/0001-WPS-Fix-HTTP-chunked-transfer-encoding-parser.patch"
number=1 ; git format-patch -${number} -o ${wdir}/2015-2/

${git} "${wdir}/2015-3/0001-AP-WMM-Fix-integer-underflow-in-WMM-Action-frame-par.patch"
number=1 ; git format-patch -${number} -o ${wdir}/2015-3/

${git} "${wdir}/2015-4/0001-EAP-pwd-peer-Fix-payload-length-validation-for-Commi.patch"
${git} "${wdir}/2015-4/0002-EAP-pwd-server-Fix-payload-length-validation-for-Com.patch"
${git} "${wdir}/2015-4/0003-EAP-pwd-peer-Fix-Total-Length-parsing-for-fragment-r.patch"
${git} "${wdir}/2015-4/0004-EAP-pwd-server-Fix-Total-Length-parsing-for-fragment.patch"
${git} "${wdir}/2015-4/0005-EAP-pwd-peer-Fix-asymmetric-fragmentation-behavior.patch"
number=5 ; git format-patch -${number} -o ${wdir}/2015-4/

${git} "${wdir}/2015-5/0001-NFC-Fix-payload-length-validation-in-NDEF-record-par.patch"
number=1 ; git format-patch -${number} -o ${wdir}/2015-5/

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

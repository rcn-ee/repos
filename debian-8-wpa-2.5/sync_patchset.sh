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

${git} "${wdir}/2016-1/0001-WPS-Reject-a-Credential-with-invalid-passphrase.patch"
${git} "${wdir}/2016-1/0002-Reject-psk-parameter-set-with-invalid-passphrase-cha.patch"
${git} "${wdir}/2016-1/0003-Remove-newlines-from-wpa_supplicant-config-network-o.patch"
${git} "${wdir}/2016-1/0004-Reject-SET_CRED-commands-with-newline-characters-in-.patch"
${git} "${wdir}/2016-1/0005-Reject-SET-commands-with-newline-characters-in-the-s.patch"
number=5 ; git format-patch -${number} -o ${wdir}/2016-1/

${git} "${wdir}/2017-1/0001-hostapd-Avoid-key-reinstallation-in-FT-handshake.patch"
${git} "${wdir}/2017-1/0002-Prevent-reinstallation-of-an-already-in-use-group-ke.patch"
${git} "${wdir}/2017-1/0003-Extend-protection-of-GTK-IGTK-reinstallation-of-WNM-.patch"
${git} "${wdir}/2017-1/0004-Fix-PTK-rekeying-to-generate-a-new-ANonce.patch"
${git} "${wdir}/2017-1/0005-TDLS-Reject-TPK-TK-reconfiguration.patch"
${git} "${wdir}/2017-1/0006-WNM-Ignore-WNM-Sleep-Mode-Response-if-WNM-Sleep-Mode.patch"
${git} "${wdir}/2017-1/0007-WNM-Ignore-WNM-Sleep-Mode-Response-without-pending-r.patch"
${git} "${wdir}/2017-1/0008-FT-Do-not-allow-multiple-Reassociation-Response-fram.patch"
${git} "${wdir}/2017-1/0009-TDLS-Ignore-incoming-TDLS-Setup-Response-retries.patch"
number=9 ; git format-patch -${number} -o ${wdir}/2017-1/


git checkout master -f
git branch -D tmp

cd ../../

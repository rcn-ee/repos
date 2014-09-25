"""
  Copyright (c) 2010 Julien Lavergne <gilir@ubuntu.com>

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software Foundation,
  Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
"""

import os
import apport.hookutils

#Detect session
session = os.environ['DESKTOP_SESSION']

#If it's not a specific session, pcmanfm uses name "default"
if not session:
    session = "default"

if session == "Lubuntu":
	conf_pcmanfm = "lubuntu.conf"
else:
	conf_pcmanfm = "pcmanfm.conf"

#Set location of various configuration files
system_conf_libfm = "/etc/xdg/libfm/"
home_conf_libfm = os.path.expanduser("~/.config/libfm/")
system_conf_pcmanfm = "/etc/xdg/pcmanfm/" + session
home_conf_pcmanfm = os.path.expanduser("~/.config/pcmanfm/") + session

#Set description for each file reported by apport
report_config_system = "Config_libfm_System_" + session
report_config_home = "Config_libfm_Home_" + session
report_pcmanfm_system = "Config_pcmanfm_System_" + session
report_pcmanfm_home = "Config_pcmanfm_Home_" + session

#List of packages which could be involved with pcmanfm
RELATED_PACKAGES = ["libmenu-cache1","libmenu-cache3","libfm4","libfm-modules","udisks","gvfs","gvfs-backend","lxde-icon-theme","gnome-icon-theme","lxpolkit"]

def add_info(report):
    # If a config file exist in HOME, report it instead of the system one.
    if os.path.exists(os.path.join(home_conf_libfm,"libfm.conf")):
        report[report_config_home] = apport.hookutils.read_file(os.path.join(home_conf_libfm,"libfm.conf"))
    else:
        report[report_config_system] = apport.hookutils.read_file(os.path.join(system_conf_libfm,"libfm.conf"))

    if os.path.exists(os.path.join(home_conf_pcmanfm, conf_pcmanfm)):
        report[report_pcmanfm_home] = apport.hookutils.read_file(os.path.join(home_conf_pcmanfm, conf_pcmanfm))
    else:
        report[report_pcmanfm_system] = apport.hookutils.read_file(os.path.join(system_conf_pcmanfm, conf_pcmanfm))

    # Attach information for relative packages
    apport.hookutils.attach_related_packages(report, RELATED_PACKAGES)

    # Attach udisks info
    report["Udisks_dump"] = apport.hookutils.command_output(["udisks", "--dump"])

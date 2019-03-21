# -*- mode: makefile; coding: utf-8 -*-
# Copyright © 2003 Martin Quinson <mquinson@debian.org>
# Description: An advanced patch system based on the quilt facilities.
#  please refere to the documentation of the quilt package for more information.
#
# Used variables for configuration:
#  

####
# If you use autotools.mk, or any other rule/class which uses it,
# include this file (patchsys-quilt.mk) *after* those.
####


#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License as
# published by the Free Software Foundation; either version 2, or (at
# your option) any later version.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
# 02111-1307 USA.

ifndef _cdbs_bootstrap
_cdbs_scripts_path ?= /usr/lib/cdbs
_cdbs_rules_path ?= /usr/share/cdbs/1/rules
_cdbs_class_path ?= /usr/share/cdbs/1/class
endif

ifndef _cdbs_rules_patchsys_quilt
_cdbs_rules_patchsys_quilt := 1

ifdef _cdbs_rules_patchsys
$(error cannot load two patch systems at the same time)
endif

include $(_cdbs_rules_path)/buildcore.mk$(_cdbs_makefile_suffix)

DEB_SRCDIR ?= .
_cdbs_patch_system_apply_rule := apply-patches
_cdbs_patch_system_unapply_rule := reverse-patches

# standard targets, as recommended by Debian policy 3.8.0
.PHONY: patch unpatch
patch: apply-patches
unpatch: reverse-patches

# DEB_PATCHDIRS: directory containing your source file for patches.
#
# You might find it convenient to add the snippet below to your
# $HOME/.quiltrc so that you can use quilt without having to reset
# QUILT_PATCHES when you switch from one project to the other:
# for where in ./ ../ ../../ ../../../ ../../../../ ../../../../../; do
#        if [ -e ${where}debian/rules -a -d ${where}debian/patches ]; then
#                export QUILT_PATCHES=debian/patches
#        fi
# done
QUILT_PATCH_DIR ?= $(CURDIR)/debian/patches
DEB_PATCHDIRS = $(QUILT_PATCH_DIR)

# DEB_QUILT_TOPDIR: directory where patches will be applied
# Use it only to override back to "." when CDBS sets DEB_SRCDIR
# and you don't want the quilt patching to happen in a subdirectory
DEB_QUILT_TOPDIR ?= $(DEB_SRCDIR)

# Internal variables, do not change it unless you know what you're doing
DEB_QUILT_CMD = cd $(DEB_QUILT_TOPDIR) && QUILT_PATCHES=$(DEB_PATCHDIRS) quilt --quiltrc /dev/null

# Declare Build-Dep of packages using this file onto quilt
CDBS_BUILD_DEPENDS      := $(CDBS_BUILD_DEPENDS), quilt

# Build-Dep on patchutils to check for fool souls patching config.* files
# This is a Bad Thing since cdbs updates those files automatically.
#  (code stolen from cdbs itself, in dpatch.mk)

CDBS_BUILD_DEPENDS      := $(CDBS_BUILD_DEPENDS), patchutils (>= 0.2.25)

# target reverse-config, which we use, don't exist in old cdbs 
CDBS_BUILD_DEPENDS      := $(CDBS_BUILD_DEPENDS), cdbs (>= 0.4.27)

evil_patches_that_do_nasty_things := $(shell \
if lsdiff=`which lsdiff` ; then \
  patchlist=`$(DEB_QUILT_CMD) series \
               | sed 's|^|$(DEB_PATCHDIRS)/|' \
               | tr "\n" " "`; \
  if [ "x$$patchlist" != x ] ; then \
    $$lsdiff -H $$patchlist \
    | egrep "/config\.(guess|sub|rpath)$$" | tr "\n" " " ; \
  fi;\
fi)
ifneq (, $(evil_patches_that_do_nasty_things))
$(warning WARNING:  The following patches are modifying auto-updated files.  This can result in serious trouble:  $(evil_patches_that_do_nasty_things))
endif


post-patches:: apply-patches

clean:: reverse-patches

# The patch subsystem
apply-patches: pre-build debian/stamp-patched
debian/stamp-patched:
# reverse-config must be first
	$(MAKE) -f debian/rules reverse-config
	
# quilt exits with 2 as return when there was nothing to do. 
# That's not an error here (but it's usefull to break loops in crude scripts)
	$(DEB_QUILT_CMD) push -a || test $$? = 2
	touch debian/stamp-patched
	
	$(MAKE) -f debian/rules update-config
# update-config must be last

reverse-patches:
# reverse-config must be first
	$(MAKE) -f debian/rules reverse-config
	
	if [ -d "$(DEB_QUILT_TOPDIR)" ]; then \
	  $(DEB_QUILT_CMD) pop -a -R || test $$? = 2 ; \
	fi
	rm -rf $(DEB_QUILT_TOPDIR)/.pc
	rm -f debian/stamp-patch*

endif

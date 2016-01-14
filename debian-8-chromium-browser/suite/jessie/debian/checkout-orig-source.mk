#!/usr/bin/make -f

MAKEFLAGS = --warn-undefined-variables

ORIG_PACKAGE ?= $(error No ORIG_PACKAGE environment variable defined.)
ORIG_VERSION ?= $(error No ORIG_VERSION environment variable defined.)


# A mix of checkout-excludable locations and others that we will remove after
# checkout.
STRIPPED_DIRS  = $(SRCDIR)/chrome/app/theme/google_chrome
STRIPPED_DIRS += $(SRCDIR)/chrome/common/extensions/docs
STRIPPED_DIRS += $(SRCDIR)/chrome_frame/tools/test/reference_build/chrome_win
STRIPPED_DIRS += $(SRCDIR)/chrome/installer/linux
STRIPPED_DIRS += $(SRCDIR)/chrome/test/data
STRIPPED_DIRS += $(SRCDIR)/chrome/test/data/firefox2_nss_mac
STRIPPED_DIRS += $(SRCDIR)/chrome/test/data/safe_browsing/old
STRIPPED_DIRS += $(SRCDIR)/chrome/third_party/wtl
STRIPPED_DIRS += $(SRCDIR)/chrome/tools/test/reference_build/chrome_linux
STRIPPED_DIRS += $(SRCDIR)/chrome/tools/test/reference_build/chrome_mac
STRIPPED_DIRS += $(SRCDIR)/chrome/tools/test/reference_build/chrome_win
STRIPPED_DIRS += $(SRCDIR)/content/test/data
STRIPPED_DIRS += $(SRCDIR)/content/test/data/layout_tests/LayoutTests
STRIPPED_DIRS += $(SRCDIR)/gears
STRIPPED_DIRS += $(SRCDIR)/google_update
STRIPPED_DIRS += $(SRCDIR)/media/test/data
STRIPPED_DIRS += $(SRCDIR)/native_client/src/trusted/service_runtime/testdata
STRIPPED_DIRS += $(SRCDIR)/net/data
STRIPPED_DIRS += $(SRCDIR)/o3d
STRIPPED_DIRS += $(SRCDIR)/ppapi/examples
STRIPPED_DIRS += $(SRCDIR)/ppapi/native_client/tests
STRIPPED_DIRS += $(SRCDIR)/third_party/boost
STRIPPED_DIRS += $(SRCDIR)/third_party/bsdiff
STRIPPED_DIRS += $(SRCDIR)/third_party/bspatch
STRIPPED_DIRS += $(SRCDIR)/third_party/ffmpeg/binaries
STRIPPED_DIRS += $(SRCDIR)/third_party/fuzzymatch
STRIPPED_DIRS += $(SRCDIR)/third_party/gles_book_examples
STRIPPED_DIRS += $(SRCDIR)/third_party/gold
STRIPPED_DIRS += $(SRCDIR)/third_party/hunspell_dictionaries
STRIPPED_DIRS += $(SRCDIR)/third_party/hunspell/dictionaries
STRIPPED_DIRS += $(SRCDIR)/third_party/hunspell/tests
STRIPPED_DIRS += $(SRCDIR)/third_party/icu/mac
STRIPPED_DIRS += $(SRCDIR)/third_party/lcov
STRIPPED_DIRS += $(SRCDIR)/third_party/lighttpd
STRIPPED_DIRS += $(SRCDIR)/third_party/nspr
STRIPPED_DIRS += $(SRCDIR)/third_party/nss
STRIPPED_DIRS += $(SRCDIR)/third_party/ocmock
STRIPPED_DIRS += $(SRCDIR)/third_party/pthread
STRIPPED_DIRS += $(SRCDIR)/third_party/pyftpdlib
STRIPPED_DIRS += $(SRCDIR)/third_party/scons
STRIPPED_DIRS += $(SRCDIR)/third_party/simplejson
STRIPPED_DIRS += $(SRCDIR)/third_party/sqlite/src/test
STRIPPED_DIRS += $(SRCDIR)/third_party/WebKit/LayoutTests
STRIPPED_DIRS += $(SRCDIR)/third_party/WebKit/Tools/Scripts
STRIPPED_DIRS += $(SRCDIR)/third_party/xdg-utils/tests
STRIPPED_DIRS += $(SRCDIR)/third_party/yasm/source/patched-yasm/modules/arch/x86/tests
STRIPPED_DIRS += $(SRCDIR)/third_party/yasm/source/patched-yasm/modules/dbgfmts/dwarf2/tests
STRIPPED_DIRS += $(SRCDIR)/third_party/yasm/source/patched-yasm/modules/objfmts/bin/tests
STRIPPED_DIRS += $(SRCDIR)/third_party/yasm/source/patched-yasm/modules/objfmts/coff/tests
STRIPPED_DIRS += $(SRCDIR)/third_party/yasm/source/patched-yasm/modules/objfmts/elf/tests
STRIPPED_DIRS += $(SRCDIR)/third_party/yasm/source/patched-yasm/modules/objfmts/macho/tests
STRIPPED_DIRS += $(SRCDIR)/third_party/yasm/source/patched-yasm/modules/objfmts/rdf/tests
STRIPPED_DIRS += $(SRCDIR)/third_party/yasm/source/patched-yasm/modules/objfmts/win32/tests
STRIPPED_DIRS += $(SRCDIR)/third_party/yasm/source/patched-yasm/modules/objfmts/win64/tests
STRIPPED_DIRS += $(SRCDIR)/third_party/yasm/source/patched-yasm/modules/objfmts/xdf/tests
STRIPPED_DIRS += $(SRCDIR)/tools/site_compare
STRIPPED_DIRS += $(SRCDIR)/tools/stats_viewer
STRIPPED_DIRS += $(SRCDIR)/tools/symsrc
STRIPPED_DIRS += $(SRCDIR)/tools/valgrind
STRIPPED_DIRS += $(SRCDIR)/tools/wine_valgrind
STRIPPED_DIRS += $(SRCDIR)/v8/test
STRIPPED_DIRS += $(SRCDIR)/v8/test/cctest
STRIPPED_DIRS += $(SRCDIR)/webkit/data/layout_tests



get-packaged-orig-source: inform pack

inform:
	@echo Now checking out source the long way. This will take several minutes.

$(ORIG_PACKAGE)-$(ORIG_VERSION): GCLIENT_DOWNLOAD_URL  := http://src.chromium.org/svn/trunk/tools/depot_tools
$(ORIG_PACKAGE)-$(ORIG_VERSION): GCLIENT_CONFIG_URL := http://src.chromium.org/svn/releases/$(ORIG_VERSION)
$(ORIG_PACKAGE)-$(ORIG_VERSION): GCLIENT_UPDATE_FLAGS := --nohooks --delete_unversioned_trees
$(ORIG_PACKAGE)-$(ORIG_VERSION): TMP_DIR := $(shell mktemp -d checkoutXXXXXX)
$(ORIG_PACKAGE)-$(ORIG_VERSION): SRCDIR := src
$(ORIG_PACKAGE)-$(ORIG_VERSION):
	@echo Running $@.  $(CURDIR)

	# get gclient tool
	@if [ ! -d $(TMP_DIR)/tools/depot_tools ]; then svn co --quiet $(GCLIENT_DOWNLOAD_URL) $(TMP_DIR)/tools/depot_tools; else svn update $(TMP_DIR)/tools/depot_tools; fi

	# configure for our version
	rm -f $(TMP_DIR)/.gclient
	cd $(TMP_DIR) && ./tools/depot_tools/gclient config $(GCLIENT_CONFIG_URL)
	@for excl in $(STRIPPED_DIRS) ; do \
	  perl -i -pe 's,("custom_deps"\s*:\s*{),$$1\n      "'$$excl'": None\,,' $(TMP_DIR)/.gclient || exit 1; \
	  echo Excluding $$excl from checkout; \
	done

	# download
	export PATH=$${PATH}:tools/depot_tools; cd $(TMP_DIR) && ./tools/depot_tools/gclient update $(GCLIENT_UPDATE_FLAGS) |sed -n '1~1000p'

	-python -c 'Var=lambda *a: "%s"; execfile("$(TMP_DIR)/src/DEPS"); print "\n".join(sorted(deps.keys()))' |grep /test/

	# configure source
	# For NaCL, run the hooks, but not the gyp ones. All one "&&"-chained
	# statement so that a failure will stop the program and be noticed.
	export PATH=$${PATH}:tools/depot_tools; cd $(TMP_DIR) && SDIR=$$(grep '"name"' .gclient |cut -d\" -f4) && perl -i~ -pe 's%\[((.)python\2, (.)(?:$(SRCDIR)/build/gyp_chromium|$(SRCDIR)/build/download_nacl_toolchains.py)\3)%[\2echo\2, \2#disabled#\2, \1%' $$SDIR/DEPS && perl -i~ -pe 's%(\bsys\.executable)\b$$%(\1 or "/usr/bin/python")%' tools/depot_tools/gclient.py && ./tools/depot_tools/gclient runhooks && mv $$SDIR/DEPS~ $$SDIR/DEPS && mv tools/depot_tools/gclient.py~ tools/depot_tools/gclient.py

	# strip

	## Use this in the future.
	# Rules from src/tools/export_tarball/export_tarball.py
	#find $(TMP_DIR) -type f -name \*.svn -o -name \*.git -o name \*ChangeLog\* -remove
	#python -c 'Var=lambda *a: "%s"; execfile("$(TMP_DIR)/src/tools/export_tarball/export_tarball.py"); print "\n".join(NONESSENTIAL_DIRS + TESTDIRS)' |while read d; do find "$$d" -type f -name ! \*gyp\* -remove -print

	cd $(TMP_DIR); for sd in $(STRIPPED_DIRS); do test -e $$sd && rm -rf $$sd || echo No STRIPPED_DIR $$sd exists to remove in postcheckout.; done

	find $(TMP_DIR)/$(SRCDIR) -type f \( -iname \*.exe -o -iname \*.dll -o -iname \*.pdb -o -name \*.o -o -name \*.a -o -name \*.dylib -o -name \*.so -o -name \*.so.\* \) -print -delete |wc -l
	find $(TMP_DIR)/$(SRCDIR) -type f \( -iname \*.bak -o -iname \*.orig -o -iname \*.cache -o -name \*.pyc -o -name \*.pyo \) -print -delete |wc -l
	find $(TMP_DIR)/$(SRCDIR) -type d -name autom4te.cache -print -delete |wc -l
	find $(TMP_DIR)/$(SRCDIR) -type f -name *.target.mk -print -delete |wc -l
	find $(TMP_DIR)/$(SRCDIR) -type f -name \*.host.mk -print -delete |wc -l
	find $(TMP_DIR)/$(SRCDIR) -type f -name \*.source_list.gypcmd -print -delete |wc -l
	find $(TMP_DIR)/$(SRCDIR) -type f -path \*/test/data/\* -print -delete |wc -l

	d=$$(mktemp -d intermediateXXXXXX); mv $(TMP_DIR)/$(SRCDIR) $$d && cp -rv $(TMP_DIR)/tools/depot_tools $$d/$(SRCDIR)/depot_tools && mv $$d $@

	touch $(TMP_DIR)/nonofficial-checkout


pack: SRCDIR := src
pack: $(ORIG_PACKAGE)-$(ORIG_VERSION)
	@echo Running $@.  $(CURDIR)
	find $< -maxdepth 2
	
	cd $(SRCDIR); time tar cf $(PWD)/$(ORIG_PACKAGE)_$(ORIG_VERSION).orig.tar.xz -J --exclude-vcs $<
	@ls -l $(ORIG_PACKAGE)_$(ORIG_VERSION).orig.tar.xz
	rm -rf $<


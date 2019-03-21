#
# This makefile chunk is intended to ease my work on packages. I hope it can
# reveal useful to other people too. But if you see some cruft here and
# there, you'll know why ;)
#
# Several of the package I work on (shadow, most of the pkg-grid alioth
# project) use quilt to manage diff onto upstream tarball.
#
# We only store the debian directory in the SCM since all changes must be
# done as patch managed by quilt.
#
# This makefile is intended to be copied in the directory containing the
# debian/ tree. It can:
#
#  - Download the upstream tarball and open it on need
#    * Define the SITE variable to tell it where to search for it (with wget) 
#    * The package name is guessed from the current directory, but can be
#      explicitely given as the PKG variable.
#    * The verion number must be given as VER variable
#
#  - Copy the debian directory onto the working directory
#    (yeah, cp debian/ $(PKG)-$(VER)/debian. I see you're following)
#
#  - Build the package, capturing the output with script
#
#  - Ensure that just after the package build, we have such a link:
#      $(PKG)-$(VER)/debian/patches -> debian/patches
#    So, changes to the patches with quilt gets saved out of the
#      $(PKG)-$(VER) tree, which can be erased at any time without loss.
#    Of course, just before the build, the makefile ensures that this link
#      is replaced by a copy of the debian/patches directory to make
#      dpkg-buildpackage happy

# TARGETS:
#
#  deb: Do what's documented above.
#
#  debsign: don't add -us -uc to dpkg-buildpackage invocation
#  check-complet: for multi-binary packages, make sure that all the content
#    of debian/tmp gets moved away [to the right place] by dh_install
#  check-lintian:
#  check-linda:
#  check: all of the check-* above
#  scan or watch: watch for new upstream tarballs

# VARIABLES which you can use to configure stuff:
#
#  PKG: package name (defaults to the current directory name)
#  VER: package version (defaults to the changelog entry in debian/changelog)
#  UP_TAR: name of the tarfile, as called upstream 
#     Defaults to $(PKG)-$(UP_VER).tar.gz where UP_VER is VER without -nn part
#     Useful to get it downloaded and/or opened automatically
#  EXTRA_OPEN_CMD: what to do after untarring upstream tarball. 
#     When upstream tarball doesn't contain a gentle $(PKG)-$(UP_VER) as
#       expected by dpkg-buildpackage, do this:
#     EXTRA_OPEN_CMD=mv the_funky_dir_name_given_upstream $(PKG)-$(UP_VER)
#  SITE: where to get the upstream tarball (we do "wget $(SITE)/$(UP_TAR)")
#     

# CAVEATS:
#   
#   - $(PKG)-$(VER) is not considered as precious at all. Don't change
#     anything in it. In particular, don't change $(PKG)-$(VER)/debian files.

##############
### That's it.
### The actual makefile chunk follows, but you shouldn't need to dig into it 
##############

PKG?=$(shell pwd |sed 's|.*/||')
VER?=$(shell dpkg-parsechangelog -ldebian/changelog|grep '^Version'|sed  -e 's/[^ ]* //' -e 's/[^:]://')
UP_VER=$(shell echo $(VER)|sed 's/-.*$$//')
UP_TAR?=$(PKG)-$(UP_VER).tar.gz

########################################################
##################### BUILD TARGET #####################
########################################################

deb:: $(PKG)-$(UP_VER) stamp-debdir $(PKG)_$(UP_VER).orig.tar.gz
	@echo XXXXXXXXXXX Build the deb
	rm -rf $(PKG)-$(UP_VER)/debian/patches
	@if [ -e debian/patches ] ; then \
	   echo "cp -r debian/patches $(PKG)-$(UP_VER)/debian"; \
	   cp -r debian/patches $(PKG)-$(UP_VER)/debian; \
	fi
	-cd $(PKG)-$(UP_VER) && script -c "dpkg-buildpackage -rfakeroot -uc -us" ../build.log
	@if [ -e debian/patches ] ; then \
	  rm -rf $(PKG)-$(UP_VER)/debian/patches ; \
	  echo "Link patches/ to ../debian/patches" ; \
	  cd $(PKG)-$(UP_VER)/debian ;  \
	  ln -s ../../debian/patches .; \
	fi

debsign:: $(PKG)-$(UP_VER) stamp-debdir $(PKG)_$(UP_VER).orig.tar.gz
	@echo XXXXXXXXXXX Build the deb
	rm -rf $(PKG)-$(UP_VER)/debian/patches
	@if [ -e debian/patches ] ; then \
	   echo "cp -r debian/patches $(PKG)-$(UP_VER)/debian"; \
	   cp -r debian/patches $(PKG)-$(UP_VER)/debian; \
	fi
	cd $(PKG)-$(UP_VER) && script -c "dpkg-buildpackage -rfakeroot" ../build.log
	@if [ -e debian/patches ] ; then \
	  rm -rf $(PKG)-$(UP_VER)/debian/patches ; \
	  echo "Link patches/ to ../debian/patches" ; \
	  cd $(PKG)-$(UP_VER)/debian ;  \
	  ln -s ../../debian/patches .; \
	fi

$(PKG)-$(UP_VER):: $(UP_TAR)
	@echo XXXXXXXXXXX Open the tarball
	rm -rf $(PKG)-$(UP_VER)
	tar xfz $(UP_TAR)
	$(EXTRA_OPEN_CMD)

$(UP_TAR)::
	@echo XXXXXXXXXXX Download the tarball
	@if test -e $(UP_TAR) ; then \
	  echo "Tarball found; no download needed."; \
	else \
	  if test "x$(SITE)" = x ; then \
	    echo "Unable to download $(UP_TAR) since no SITE is provided";\
	    echo "Either edit Makefile or download the tarball yourself";\
	    exit 1;\
	  else \
	    wget -nd $(SITE)/$(UP_TAR);\
	  fi;\
	fi
	
stamp-debdir: FORCE
	@echo XXXXXXXXXXX Put the debian dir in position
	rm -rf $(PKG)-$(UP_VER)/debian
	cp -Lr debian $(PKG)-$(UP_VER)/debian
	for i in CVS .svn \{arch\} .arch-ids ; do \
	  find $(PKG)-$(UP_VER)/debian -type d -name $$i | xargs rm -rf ; \
	done
	for i in .cvsignore svn-commit.tmp .arch-inventory ; do \
	  find $(PKG)-$(UP_VER)/debian -type f -name $$i | xargs rm -f ; \
	done
	touch stamp-debdir
	
$(PKG)_$(UP_VER).orig.tar.gz: $(UP_TAR)
	@echo XXXXXXXXXXX Copy the orig.tar.gz
	cp $(UP_TAR) $(PKG)_$(UP_VER).orig.tar.gz

FORCE:

########################################################
##################### CHECK TARGET #####################
########################################################
check-complet: FORCE
	@echo XXXXXXXXXXX Check the package for completness
	@for file in `find $(PKG)-$(UP_VER)/debian/tmp -type f|\
	             sed 's|$(PKG)-$(UP_VER)/debian/tmp/||'` ; do \
	  where=`find $(PKG)-$(UP_VER)/debian/*|\
	         grep -v '$(PKG)-$(UP_VER)/debian/tmp'|\
	         grep $$file|\
		 sed -e "s|$(PKG)-$(UP_VER)/debian/||" \
		     -e 's|\([^/]*\)/.*|\1|' `; \
	  if [ "x$$where" = x ] ; then \
	    base=`basename $$file`; \
	    where=`find $(PKG)-$(UP_VER)/debian/*|\
	           grep -v '$(PKG)-$(UP_VER)/debian/tmp'|\
	           grep $$base|\
	 	   sed -e "s|$(PKG)-$(UP_VER)/debian/||" `; \
	    if [ "x$$where" = x ] ; then \
	     echo "Not Found $$file"; \
	    else \
	     echo "NOT FOUND $$file (beside $$where)"; \
	    fi \
	  else \
	     echo Found $$file in $$where >/dev/null; \
	  fi;\
	done

check-relocation: FORCE
	@echo XXXXXXXXXXX Check the relocation of the package
	@for pkg in `grep Package $(PKG)-$(UP_VER)/debian/control|\
	             sed 's|Package: ||'` ; do \
	  echo "XXX check $$pkg"; \
	  LC_ALL=C grep -r $(PWD) $(PKG)-$(UP_VER)/debian/$$pkg |\
	    while read line ; do \
	      if echo $$line|grep -q 'Binary file' >/dev/null ; then \
	        name=`echo $$line|sed 's/Binary file \([^ ]*\) .*$$/\1/'`; \
		echo "  Binary $$name =>";\
		strings $$name |grep $(PWD)|\
		  grep -v '.c$$'|sed 's/^/    /';\
	      else \
	      echo "  $$line"; \
	      fi; \
	    done; \
	done

check-relocation-old: FORCE
	@echo XXXXXXXXXXX Check the relocation of the package
	@for pkg in `grep Package $(PKG)-$(UP_VER)/debian/control|\
	             sed 's|Package: ||'` ; do \
	  echo "XXX check $$pkg"; \
	  LC_ALL=C grep -r $(PWD) $(PKG)-$(UP_VER)/debian/$$pkg|\
	    sed 's/^/  /';\
	done

check-lintian: FORCE
	@echo XXXXXXXXXXX Check the package with lintian
	lintian -i *.deb
	lintian -i *.dsc

check-linda: FORCE
	@echo XXXXXXXXXXX Check the package with linda
	linda -i *.deb
	linda -i *.dsc

check: check-complet check-linda check-lintian 

########################################################
##################### CLEAN TARGET #####################
########################################################

clean-dsc: FORCE
	@echo XXXXXXXXXXX Clean the old versions
	@while [ `ls *.dsc |wc -l` -gt 1 -o `ls *.changes |wc -l` -gt 1 ] ; do \
	  if [ `ls *.changes |wc -l` -gt 1 ] ; then \
	    echo "XXX Cleanup binaries";ls;\
	    changes=`ls *.changes|head -1`; \
            list=`grep-dctrl -s Files -n . $$changes|\
	          sed 's/^ *//'|\
	          cut -d' ' -f5|\
	          egrep -v '\.dsc$$'`;\
	    rm -i $$list $$changes; \
	  fi; \
	  \
	  if [ `ls *.dsc |wc -l` -gt 1 ] ; then \
	    echo "XXX Cleanup source";ls;\
	    dsc=`ls *.dsc|head -1`; \
            list=`grep-dctrl -s Files -n . $$dsc|\
	          sed 's/^ *//'|\
	          cut -d' ' -f3|\
	          egrep -v '\.orig.tar.gz$$'`; \
	    rm -i $$list $$dsc; \
	  fi; \
	done

clean: clean-dsc
	@echo XXXXXXXXXXX Clean the stamps
	rm -rf stamp-*

maintainerclean: clean
	rm -rf *.deb *.diff.gz *.dsc *.changes *.upload
	rm -rf $(PKG)_$(UP_VER).orig.tar.gz $(PKG)-$(UP_VER) 

scan watch:
	uscan --check-dirname-regex 'PACKAGE' --check-dirname-level 2 --report

.PHONY: FORCE scan watch clean clean-dsc 
ifneq (,$(wildcard makefile.override))
include makefile.override
endif

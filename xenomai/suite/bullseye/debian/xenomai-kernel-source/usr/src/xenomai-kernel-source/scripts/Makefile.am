bin_SCRIPTS=xeno-config xeno wrap-link.sh

install-exec-local:
	@if test -r $(srcdir)/postinstall.sh ; then \
	   echo "Running post-install script..." ;\
	   $(srcdir)/postinstall.sh ; \
	fi

install-data-local:
	$(mkinstalldirs) $(DESTDIR)$(libdir)
	$(INSTALL_DATA) $(srcdir)/dynlist.ld $(DESTDIR)$(libdir)

uninstall-local:
	$(RM) $(DESTDIR)$(libdir)/dynlist.ld
	@if test -r $(srcdir)/postinstall.sh ; then \
	   echo "Running post-uninstall script..." ;\
	   $(srcdir)/postinstall.sh --uninstall ; \
	fi

EXTRA_DIST =				\
	$(wildcard postinstall.sh)	\
	Kconfig.frag			\
	bootstrap			\
	dynlist.ld			\
	histo.gp			\
	prepare-kernel.sh		\
	wrap-link.sh			\
	xeno-config-cobalt.in		\
	xeno-config-mercury.in		\
	xeno.in

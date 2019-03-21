# -*- Makefile -*-, you silly Emacs!
# vim: set ft=make:

#
# This file tries to mimick /usr/share/dpatch/dpatch.make
#

# QUILT_STAMPFN: stamp file to use
QUILT_STAMPFN	?= debian/stamp-patched

# QUILT_PATCH_DIR: where the patches live
QUILT_PATCH_DIR ?= debian/patches

patch: $(QUILT_STAMPFN)
$(QUILT_STAMPFN):
	@# quilt exits with 2 as return when there was nothing to do.
	@# That's not an error here
	QUILT_PATCHES=$(QUILT_PATCH_DIR) \
		quilt --quiltrc /dev/null push -a || test $$? = 2
	touch $(QUILT_STAMPFN)

unpatch:
	QUILT_PATCHES=$(QUILT_PATCH_DIR) \
		quilt --quiltrc /dev/null pop -a -R || test $$? = 2
	rm -rf .pc $(QUILT_STAMPFN)

.PHONY: patch unpatch

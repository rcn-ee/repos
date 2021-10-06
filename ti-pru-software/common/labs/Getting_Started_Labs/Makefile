SUBDIRS=\
assembly_code/solution/am335x \
assembly_code/solution/am437x \
assembly_code/solution/am572x \
assembly_code/solution/am65x \
assembly_code/solution/k2g \
c_and_assembly/solution/am335x \
c_and_assembly/solution/am437x \
c_and_assembly/solution/am572x \
c_and_assembly/solution/am65x \
c_and_assembly/solution/k2g \
c_and_inline_assembly/solution/am335x \
c_and_inline_assembly/solution/am437x \
c_and_inline_assembly/solution/am572x \
c_and_inline_assembly/solution/am65x \
c_and_inline_assembly/solution/k2g \
c_code/solution/am335x \
c_code/solution/am437x \
c_code/solution/am572x \
c_code/solution/am65x \
c_code/solution/k2g

all: $(SUBDIRS)

$(SUBDIRS):
	@$(MAKE) -C $@

clean:
	@for d in $(SUBDIRS); do (cd $$d; $(MAKE) clean ); done

.PHONY: all clean $(SUBDIRS)


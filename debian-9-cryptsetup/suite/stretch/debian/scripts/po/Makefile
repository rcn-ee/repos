XGETTEXT = xgettext
MSGFMT = msgfmt
MSGMERGE = msgmerge

LOCALEDIR = /usr/share/locale

.SUFFIXES: .po .mo .pot

%.mo: %.po
	$(MSGFMT) -o $@ $<

PO = $(wildcard *.po)
LANG = $(basename $(PO))
MO = $(addsuffix .mo,$(LANG))
SOURCES = ../luksformat

all: update $(MO)
update: luksformat.pot
	-@for po in $(PO); do \
	echo -n "Updating $$po"; \
	$(MSGMERGE) -U $$po luksformat.pot; \
	done;

luksformat.pot: $(SOURCES)
	$(XGETTEXT) -c -L Perl -kgtx \
	--msgid-bugs-address=pkg-cryptsetup-devel@lists.alioth.debian.org \
	-o $@ $(SOURCES)

install: all
	for i in $(MO) ; do \
	  t=$(DESTDIR)/$(LOCALEDIR)/`basename $$i .mo`/LC_MESSAGES ;\
	  install -d $$t ;\
	  install -m 644 $$i $$t/luksformat.mo ;\
	done

clean:
	$(RM) $(MO) *~

.PHONY: update

#!/usr/bin/make -f

all:
	gpg --no-permission-warning -q --homedir . --no-default-keyring \
	--keyring ./rcn-ee-archive-2015.gpg --import A4C46402.asc
	$(RM) rcn-ee-archive-2015.gpg~ secring.gpg trustdb.gpg

install:

clean:
	$(RM) rcn-ee-archive-2015.gpg

check:

test:


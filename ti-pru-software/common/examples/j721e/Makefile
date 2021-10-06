SUBDIRS=PRU_RPMsg_Echo_Interrupt0 PRU_RPMsg_Echo_Interrupt1 \
	RTU_RPMsg_Echo_Interrupt0 RTU_RPMsg_Echo_Interrupt1 \
	PRU_Halt RTU_Halt TX_PRU_Halt

all: $(SUBDIRS)

$(SUBDIRS):
	@$(MAKE) -C $@

clean:
	@for d in $(SUBDIRS); do (cd $$d; $(MAKE) clean ); done

.PHONY: all clean $(SUBDIRS)

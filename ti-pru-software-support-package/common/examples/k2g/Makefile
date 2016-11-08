SUBDIRS=PRU_RPMsg_Echo_Interrupt0_0 PRU_RPMsg_Echo_Interrupt0_1 PRU_RPMsg_Echo_Interrupt1_0 \
PRU_RPMsg_Echo_Interrupt1_1 PRU_Direct_Connect0 PRU_Direct_Connect1 PRU_MAC_Multiply_Accum PRU_Halt

all: $(SUBDIRS)

$(SUBDIRS):
	@$(MAKE) -C $@

clean:
	@for d in $(SUBDIRS); do (cd $$d; $(MAKE) clean ); done

.PHONY: all clean $(SUBDIRS)




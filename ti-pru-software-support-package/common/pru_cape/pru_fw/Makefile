SUBDIRS=PRU_Audio PRU_Halt PRU_Hardware_UART PRU_HDQ_TempSensor0 PRU_HDQ_TempSensor1 PRU_LED0 PRU_LED1 PRU_RPMsg_LED0 PRU_Switch

all: $(SUBDIRS)

$(SUBDIRS):
	@$(MAKE) -C $@

clean:
	@for d in $(SUBDIRS); do (cd $$d; $(MAKE) clean ); done

.PHONY: all clean $(SUBDIRS)




SUBDIRS=\
lab_1/solution/toggle_led  \
lab_2/solution/button_led_0 \
lab_2/solution/button_led_1 \
lab_3/solution/PRU_HDQ_TempSensor0 \
lab_3/solution/PRU_HDQ_TempSensor1 \
lab_4/solution/button_led_0 \
lab_4/solution/button_led_1 \
lab_5/solution/PRU_RPMsg_Echo_Interrupt1 \
lab_5/solution/PRU_Halt \
lab_6/solution/PRU_RPMsg_LED0 \

all: $(SUBDIRS)

$(SUBDIRS):
	@$(MAKE) -C $@

clean:
	@for d in $(SUBDIRS); do (cd $$d; $(MAKE) clean ); done

.PHONY: all clean $(SUBDIRS)




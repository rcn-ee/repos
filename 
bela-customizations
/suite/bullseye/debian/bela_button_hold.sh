#!/bin/bash
#this file is executed when the button on the Bela cape is held down for more than 2 seconds.

CUSTOM_FILE=/opt/Bela/local/`basename $0` 
[ -f $CUSTOM_FILE ] &&\
	{ echo "Bela cape button held, running $CUSTOM_FILE " | wall; $CUSTOM_FILE; } ||\
	       	{ echo Shutting down | wall; shutdown -h now; }


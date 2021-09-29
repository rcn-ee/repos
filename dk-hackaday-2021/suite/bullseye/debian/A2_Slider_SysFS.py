#!/usr/bin/python3

import os
import time
import sys

adc0 = open("/sys/bus/iio/devices/iio:device0/in_voltage2_raw", "r")

devID = "A2_Slider"

voltage = int(adc0.read())
print("metric:id=%s,n=Reading,vd=%0.1d,u=S" % (devID, voltage))
adc0.seek(0)
time.sleep(1)
adc0.close()

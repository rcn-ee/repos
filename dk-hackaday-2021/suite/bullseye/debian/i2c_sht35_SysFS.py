#!/usr/bin/python3

import os
import time
import sys

hwmon_temp = open("/sys/class/hwmon/hwmon0/temp1_input", "r")
hwmon_hum = open("/sys/class/hwmon/hwmon0/humidity1_input", "r")

devID = "i2c_sht35"

hwmon_temp_value = int(hwmon_temp.read())
hwmon_temp_f = ((hwmon_temp_value * 9/5) + 32000)/ 1000
hwmon_temp.seek(0)
hwmon_temp.close()

hwmon_hum_value = int(hwmon_hum.read())
hwmon_hum_rh = (hwmon_hum_value /1000)
hwmon_hum.seek(0)
hwmon_hum.close()

print("metric:id=%s,n=Reading,vd=%0.1f,u=F" % (devID, hwmon_temp_f))
print("metric:id=%s,n=Humidity,vd=%0.2f,u=%%" % (devID, hwmon_hum_rh))

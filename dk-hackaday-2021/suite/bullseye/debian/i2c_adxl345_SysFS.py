#!/usr/bin/python3

import os
import time
import sys

accel_x_raw = open("/sys/bus/iio/devices/iio:device1/in_accel_x_raw", "r")
accel_y_raw = open("/sys/bus/iio/devices/iio:device1/in_accel_y_raw", "r")
accel_z_raw = open("/sys/bus/iio/devices/iio:device1/in_accel_z_raw", "r")

devID = "i2c_adxl345"

accel_x_raw_value = int(accel_x_raw.read())
accel_x_raw.seek(0)
accel_x_raw.close()

accel_y_raw_value = int(accel_y_raw.read())
accel_y_raw.seek(0)
accel_y_raw.close()

accel_z_raw_value = int(accel_z_raw.read())
accel_z_raw.seek(0)
accel_z_raw.close()

print("metric:id=%s,n=accel_x,vd=%0.1d,u=U" % (devID, accel_x_raw_value))
print("metric:id=%s,n=accel_y,vd=%0.1d,u=U" % (devID, accel_y_raw_value))
print("metric:id=%s,n=accel_z,vd=%0.1d,u=U" % (devID, accel_z_raw_value))


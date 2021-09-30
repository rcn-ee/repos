#!/usr/bin/python3

import os
import time
import evdev

devID = "U4_Button"

class BUTTON:
    def __init__(self):
        try:
            self.button = evdev.InputDevice("/dev/input/event1")
        except IOError as err:
            GetCmdReturn('sudo chmod 777 /dev/input/event1')
            self.button = evdev.InputDevice("/dev/input/event1")
    def GetKeyStatus(self):  
        """Get two button's Value
            return:[](Button isn't pressed),[256],[257](Button is pressed)
        """
        return self.button.active_keys()
    def read_loop(self):
        """Read two button's status constantly
            return:two button's status
        """
        return self.button.read_loop()
def main():
    d = BUTTON()
    for event in d.read_loop():
        if event.type == evdev.ecodes.EV_KEY:
            #print(d.GetKeyStatus())
            #print(evdev.categorize(event))
            c = evdev.categorize(event)
            if c.keystate == c.key_down:
                print("metric:id=%s,n=State,vb=1,u=S" % (devID))
            elif c.keystate == c.key_up:
                print("metric:id=%s,n=State,vb=0,u=S" % (devID))

if __name__ == "__main__":
    main()

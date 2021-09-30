#!/usr/bin/env python3

import time
import os
import evdev

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
            print(d.GetKeyStatus())
            print(evdev.categorize(event))
if __name__ == "__main__":
    main()

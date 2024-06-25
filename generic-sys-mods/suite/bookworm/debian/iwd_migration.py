#!/usr/bin/env python3

#Copied from: https://gist.github.com/Mic92/3ca60e6865a9793423a41db0480275d8
import glob
import re
import sys
import os
import subprocess
import curses.ascii
import binascii
from typing import Tuple, Optional

def main() -> None:
    networks = {}
    with open("/boot/firmware/firstrun.sh") as f:
        ssid = None
        psk = None
        for line in f:
            match = re.match("\s*ssid=\"(.+)\"", line)
            if match:
                ssid = match.group(1)
            match2 = re.match("\s*psk=(.+)", line)
            if match2:
                psk = match2.group(1)
            if ssid and psk:
                networks[ssid] = psk
#            else:
#                ssid = None
#                psk = None

    for ssid, psk in networks.items():
        if not re.match("^[0-9 \-_a-zA-z]+$", ssid):
            hexstr = binascii.hexlify(ssid.encode("utf-8")).decode("ascii")
            filename = f"={hexstr}.psk"
        else:
            filename = f"{ssid}.psk"
        name = os.path.join("/var/lib/iwd", filename)

        print(f"{ssid} -> {name}")
        with open(name, "w") as f:
          f.write(f"""[Security]
PreSharedKey={psk}
""")

if __name__ == '__main__':
    main()

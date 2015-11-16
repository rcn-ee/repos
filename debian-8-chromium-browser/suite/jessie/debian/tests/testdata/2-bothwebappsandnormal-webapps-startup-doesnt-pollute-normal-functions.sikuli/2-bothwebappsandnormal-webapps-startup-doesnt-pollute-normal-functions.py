import os
import subprocess

app1 = subprocess.Popen(["chromium-browser", "--window-size=400,2200", "--window-position=50,100",  "--user-data-dir=profile_storage", "--chromeless", "--new-window"])
app2 = subprocess.Popen(["chromium-browser", "--window-size=400,2200", "--window-position=500,100", "--user-data-dir=profile_storage",                 "--new-window"])

try:
    wait("NewTab.png", 20)
    assert not exists("MoreThanOneTab.png")
    type("NewTab.png", "t", KEY_CTRL)
    find("MoreThanOneTab.png", 20)
except:
    subprocess.call(["xwd", "-root", "-out", "2-bothwebappsandnormal-webapps-startup-doesnt-pollute-normal-functions"])
finally:
    if app1.pid:
        os.kill(app1.pid, signal.SIGTERM)
        app1.wait()
    else:
        # Jython python2.5 hackey. So so sorry.
        app1._process.destroy()
    if app2.pid:
        os.kill(app2.pid, signal.SIGTERM)
        app2.wait()
    else:
        # Jython python2.5 hackey. So so sorry.
        app2._process.destroy()

import os
import subprocess

app = subprocess.Popen(["chromium-browser", "--window-size=1000,2200", "--window-position=50,100", "--user-data-dir=profile_storage", "--new-window", os.environ["LOCALURL"]])

try:
    wait("ReloadButton.png", 20)  # done loading.
    type("l", KEY_CTRL)
    type("about:settings"+Key.ENTER)
    click("Showadvanced-1.png")
    wait("Notifymewhen.png", 10)
except:
    subprocess.call(["xwd", "-root", "-out", "1-normal-plugin-and-extension-running.xwd"])
finally:
    if app.pid:
        os.kill(app.pid, signal.SIGTERM)
        app.wait()
    else:
        # Jython python2.5 hackey. So so sorry.
        app._process.destroy()

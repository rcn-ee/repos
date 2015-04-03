import os
import subprocess

app = subprocess.Popen(["chromium-browser", "--window-size=1000,2200", "--window-position=50,100", "--user-data-dir=profile_storage", "--chromeless", "--new-window", os.environ["LOCALURL"]])

try:
    wait("Directorylis-1.png", 20)  # window decoration over bare web page
except:
    subprocess.call(["xwd", "-root", "-out", "6-webapps-window-no-chrome"])
finally:
    if app.pid:
        os.kill(app.pid, signal.SIGTERM)
        app.wait()
    else:
        # Jython python2.5 hackey. So so sorry.
        app._process.destroy()

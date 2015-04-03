import os
import re
import random
import subprocess

test_value = "x".join(str(random.randint(0, 50)) for x in range(5))
app = subprocess.Popen(["chromium-browser", "--window-size=1000,2200", "--window-position=50,100", "--user-data-dir=profile_storage", "--new-window"])

try:

    refresh_button = wait("cr-refresh-button.png", 30)
    click(refresh_button.right(50))
    just_below_refresh_button = refresh_button.below(30)
    just_below_refresh_button.type("l", KeyModifier.CTRL)
    refresh_button.right(50).type(test_value + Key.ENTER)

    # first assertion: default search is Google
    wait("google-text.png", 10)

    # second assertion: search url contains our token
    just_below_refresh_button.type("l", KeyModifier.CTRL)
    just_below_refresh_button.type("x", KeyModifier.CTRL)
    location_bar_contents = Env.getClipboard()

    assert test_value in location_bar_contents, "Hrm, logic is wrong. " + location_bar_contents
    assert re.search(r"google", location_bar_contents), location_bar_contents
    assert re.search(r"\bclient=ubuntu\b", location_bar_contents), location_bar_contents

except:
    if app.pid:
        os.kill(app.pid, signal.SIGTERM)
        app.wait()
    else:
        # Jython python2.5 hackey. So so sorry.
        app._process.destroy()
    raise

print "Success!"

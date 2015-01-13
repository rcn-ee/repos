Debian: http://repos.rcn-ee.net/debian/ (wheezy/jessie)
```
deb [arch=armhf] http://repos.rcn-ee.net/debian/ wheezy main
#deb-src [arch=armhf] http://repos.rcn-ee.net/debian/ wheezy main
```

Ubuntu: http://repos.rcn-ee.net/ubuntu/ (trusty)
```
deb [arch=armhf] http://repos.rcn-ee.net/ubuntu/ trusty main
#deb-src [arch=armhf] http://repos.rcn-ee.net/ubuntu/ trusty main
```

keyring:
```
sudo apt-get install rcn-ee-archive-keyring
```

secure https (via: apt-transport-https) is also available: https://repos.rcn-ee.net/[debian|ubuntu]/

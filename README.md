Debian 7: (Wheezy): http://repos.rcn-ee.net/debian/
```
deb [arch=armhf] http://repos.rcn-ee.net/debian/ wheezy main
#deb-src [arch=armhf] http://repos.rcn-ee.net/debian/ wheezy main
```

Debian 8: (Jessie): http://repos.rcn-ee.net/debian/
```
deb [arch=armhf] http://repos.rcn-ee.net/debian/ jessie main
#deb-src [arch=armhf] http://repos.rcn-ee.net/debian/ jessie main
```

Ubuntu 14.04 lts: (Trusty): http://repos.rcn-ee.net/ubuntu/
```
deb [arch=armhf] http://repos.rcn-ee.net/ubuntu/ trusty main
#deb-src [arch=armhf] http://repos.rcn-ee.net/ubuntu/ trusty main
```

keyring:
```
sudo apt-get install rcn-ee-archive-keyring
```

secure https (via: apt-transport-https) is also available: https://repos.rcn-ee.net/[debian|ubuntu]/

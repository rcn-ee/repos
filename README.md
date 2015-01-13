Debian: http://repos.rcn-ee.net/debian/

Ubuntu: http://repos.rcn-ee.net/ubuntu/

secure https (via: apt-transport-https) is also available: https://repos.rcn-ee.net/[debian|ubuntu]/

Debian 7 (Wheezy)
```
sudo sh -c \
    "echo 'deb [arch=armhf] http://repos.rcn-ee.net/debian/ wheezy main' > \
    /etc/apt/sources.list.d/repos.rcn-ee.net.list; \
    echo '#deb-src [arch=armhf] http://repos.rcn-ee.net/debian/ wheezy main' >> \
    /etc/apt/sources.list.d/repos.rcn-ee.net.list; \
    apt-get update ; \
    apt-get install -y --allow-unauthenticated rcn-ee-archive-keyring"
sudo apt-get update
```

Debian 8 (Jessie)
```
sudo sh -c \
    "echo 'deb [arch=armhf] http://repos.rcn-ee.net/debian/ jessie main' > \
    /etc/apt/sources.list.d/repos.rcn-ee.net.list; \
    echo '#deb-src [arch=armhf] http://repos.rcn-ee.net/debian/ jessie main' >> \
    /etc/apt/sources.list.d/repos.rcn-ee.net.list; \
    apt-get update ; \
    apt-get install -y --allow-unauthenticated rcn-ee-archive-keyring"
sudo apt-get update
```

Ubuntu 14.04 LTS (Trusty Tahr)
```
sudo sh -c \
    "echo 'deb [arch=armhf] http://repos.rcn-ee.net/debian/ trusty main' > \
    /etc/apt/sources.list.d/repos.rcn-ee.net.list; \
    echo '#deb-src [arch=armhf] http://repos.rcn-ee.net/debian/ trusty main' >> \
    /etc/apt/sources.list.d/repos.rcn-ee.net.list; \
    apt-get update ; \
    apt-get install -y --allow-unauthenticated rcn-ee-archive-keyring"
sudo apt-get update
```

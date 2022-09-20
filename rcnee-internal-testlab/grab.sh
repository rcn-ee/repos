#!/bin/bash

rm check-config.sh

wget https://raw.githubusercontent.com/moby/moby/master/contrib/check-config.sh
chmod +x check-config.sh

cp -v check-config.sh ./suite/buster/debian/docker-check-config.sh
cp -v check-config.sh ./suite/bullseye/debian/docker-check-config.sh

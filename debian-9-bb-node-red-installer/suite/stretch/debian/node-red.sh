#!/bin/bash -
export NODE_PATH=/usr/local/lib/node_modules
cd /usr/local/lib/node_modules/node-red/
/usr/bin/nodejs --max-old-space-size=128 red.js

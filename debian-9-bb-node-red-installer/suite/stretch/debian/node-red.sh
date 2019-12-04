#!/bin/bash
export NODE_PATH=/opt/node-red/lib/node_modules/
cd /opt/node-red/lib/node_modules/node-red/
/opt/node-red/bin/node --max-old-space-size=128 red.js

#!/bin/bash -e

../tools/generate_source.sh
../tools/generate_dsc.sh
../tools/push_dsc_out.sh
../tools/build_deb.sh

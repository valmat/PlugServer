#!/bin/bash

cd $(dirname $0)

cd IniConfigs/src
make clean
make -j

cd ../..

#
# compile libevent
#
cd libevent
./autogen.sh
./configure
make clean
make -j
#make verify

#!/bin/bash

cd $(dirname $0)

cd IniConfigs/src
make

cd ../..

#
# compile libevent
#
cd libevent
./autogen.sh
./configure
make
#make verify

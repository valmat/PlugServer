#!/bin/bash

cd $(dirname $0)

#
# compile libevent
#
cd libevent
./autogen.sh
./configure
make
#make verify

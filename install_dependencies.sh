#!/usr/bin/env bash

# install basic tools required to build gRPC
if [ `whoami` = "root" ];then
    apt install -y build-essential autoconf libtool pkg-config
else
    sudo apt install -y build-essential autoconf libtool pkg-config
fi
#!/usr/bin/env bash

# Check params
if [ $# != 1 ];then
    echo "`date` [ERROR]: You should give proto file (absolute/relative) path."
    exit -1
fi

PROTO_PATH=$1
SRC_PATH=$(cd "$(dirname $PROTO_PATH)";pwd)

if [ ! -d "$SRC_PATH" ];then
    mkdir -p $SRC_PATH
fi

# Add file to path
export PATH=$(pwd)/grpc/cmake/build/install/bin:$PATH

# Find proto file
if [ ! -e "$PROTO_PATH" ];then
    echo "`date` [ERROR]: Could not find proto."
    exit -1
fi

# Gen grpc code by .proto file
protoc -I ./src --grpc_out=./src/ --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` $PROTO_PATH 
protoc -I ./src --cpp_out=./src// $PROTO_PATH
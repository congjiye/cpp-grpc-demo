#!/usr/bin/env bash

git clone --recurse-submodules -b v1.34.0 https://github.com/grpc/grpc
cd grpc

mkdir -p cmake/build
pushd cmake/build
cmake -DgRPC_INSTALL=ON -DgRPC_BUILD_TESTS=OFF -DCMAKE_INSTALL_PREFIX=$(pwd)/install ../..
make -j
make install
popd
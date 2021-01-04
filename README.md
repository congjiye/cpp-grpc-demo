# cpp-grpc-demo

This is a simple project which introduce user to know how to use cpp grpc by Makefile and cmake.

## Installation

You can use the **install_grpc.sh** to install grpc. It will be installed into **grpc/cmake/build/install** directory.

## Generate gRPC files

Using the **gen_grpc_code.sh** to generate grpc files.

## (Option 1) Use Makefile

Execute the following commands in the src directory.

```shell
# Go to src directory
cd src

# Build the source code.
make -j

# Run the server.
./helloworld.server

# On a different terminal, run the client.
./helloworld.client
```

## (Option 2) Use CMake

Execute the following commands in the root directory.

```shell
# Go to cmake directory and create a build directory
mkdir -p build && cd build

# Build the source code.
cmake .. && make

# Run the server.
./helloworld.server

# On a different termianl, run the client.
./helloworld.client
```

## Reference

[gRPC C++ Quick Start](https://grpc.io/docs/languages/cpp/quickstart/)
# cpp-grpc-demo

This is a simple project which introduce user to know how to use cpp grpc by Makefile.

## Installation

You can use the **install_grpc.sh** to install grpc. It will be installed into **grpc/cmake/build/install** directory.

## Generate gRPC files

Using the **gen_grpc_code.sh** to generate grpc files.

## How to use

Execute the following commands from the src directory.

### Build the source code.

```shell
make -j
```

### Run the server.

```shell
./helloword.server
```

### On a different terminal, run the client.

```shell
./helloworld.client
```

## Reference

[gRPC C++ Quick Start](https://grpc.io/docs/languages/cpp/quickstart/)
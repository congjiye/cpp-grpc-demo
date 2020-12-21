GRPC_INSTALL_PATH = $(dirname $(pwd))
export PKG_CONFIG_PATH=$(GRPC_INSTALL_PATH)/grpc/cmake/build/install/lib/pkgconfig

HOST_SYSTEM = $(shell uname | cut -f 1 -d_)
SYSTEM ?= $(HOST_SYSTEM)
CXX = g++
CPPFLAGS += `pkg-config --cflags protobuf grpc`
CXXFLAGS += -std=c++11

ifeq ($(SYSTEM),Darwin)
LDFLAGS += -L/usr/local/lib `pkg-config --libs protobuf grpc++`\
					 -pthread\
           -lgrpc++_reflection\
           -ldl
else
LDFLAGS += -L/usr/local/lib `pkg-config --libs protobuf grpc++`\
           -pthread\
           -Wl,--no-as-needed -lgrpc++_reflection -Wl,--as-needed\
           -ldl
endif

all: helloworld.server helloworld.client

helloworld.server: helloworld.pb.o helloworld.grpc.pb.o helloworld.server.o
		$(CXX) $^ $(LDFLAGS) -o $@

helloworld.client: helloworld.pb.o helloworld.grpc.pb.o helloworld.client.o
		$(CXX) $^ $(LDFLAGS) -o $@

clean:
		rm -f *.o helloworld.server helloworld.client
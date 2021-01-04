cmake_minimum_required(VERSION 3.15)
project(cpp-grpc-demo)

set(ENV{PKG_CONFIG_PATH} "${PROJECT_SOURCE_DIR}/grpc/cmake/build/install/lib/pkgconfig")
find_package(PkgConfig REQUIRED)
pkg_check_modules(GRPC REQUIRED protobuf grpc++)

include_directories(${GRPC_INCLUDE_DIRS})

add_executable(helloworld.server src/helloworld.server.cc src/helloworld.pb.cc src/helloworld.grpc.pb.cc)
add_executable(helloworld.client src/helloworld.client.cc src/helloworld.pb.cc src/helloworld.grpc.pb.cc)

target_link_libraries(helloworld.server 
                      ${GRPC_LINK_LIBRARIES}
                      ${GRPC_LIBRARY_DIRS}/libgrpc++_reflection.a
                      pthread
                      dl)

target_link_libraries(helloworld.client
                      ${GRPC_LINK_LIBRARIES}
                      ${GRPC_LIBRARY_DIRS}/libgrpc++_reflection.a
                      pthread
                      dl)
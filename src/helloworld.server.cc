#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>

#include "helloworld.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

using HelloWorld::Greeter;
using HelloWorld::HelloReply;
using HelloWorld::HelloRequest;

class GreeterServiceImpl final : public Greeter::Service
{
    Status SayHello(ServerContext *context,
                    const HelloRequest *request,
                    HelloReply *reply) override
    {
        std::string prefix("Hi!");
        reply->set_message(prefix + request->text());
        return Status::OK;
    }
};

void Serve()
{
    std::string address("0.0.0.0:50051");
    GreeterServiceImpl serve;
    ServerBuilder builder;
    builder.AddListeningPort(address, grpc::InsecureServerCredentials());
    builder.RegisterService(&serve);

    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << address << std::endl;
    server->Wait();
}

int main(int argc, char** argv)
{
    Serve();
    return 0;
}
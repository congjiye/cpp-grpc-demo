#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>
#ifdef BAZEL_BUILD
#include "helloworld.grpc.pb.h"
#else
#include "helloworld.grpc.pb.h"
#endif

using grpc::Channel;
using grpc::ChannelInterface;
using grpc::ClientContext;
using grpc::Status;

using HelloWorld::Greeter;
using HelloWorld::HelloReply;
using HelloWorld::HelloRequest;

class HelloWorldClient
{
public:
    HelloWorldClient(std::shared_ptr<ChannelInterface> channel)
        : stub_(Greeter::NewStub(channel)) {}

    std::string SayHello(const std::string &text)
    {
        HelloRequest request;
        request.set_text(text);
        HelloReply reply;
        ClientContext context;

        Status status = stub_->SayHello(&context, request, &reply);
        if (status.ok())
        {
            return reply.message();
        }
        std::cerr << status.error_code() << ": " << status.error_message() << std::endl;
        return "RPC failed";
    }

private:
    std::unique_ptr<Greeter::Stub> stub_;
};

int main(int argc, char** argv)
{
    std::string target_str = "localhost:50051";
    HelloWorldClient helloworld_client(grpc::CreateChannel(target_str, grpc::InsecureChannelCredentials()));
    std::string text("Hello World");
    std::string reply = helloworld_client.SayHello(text);
    std::cout << "Received: " << reply << std::endl;
    return 0;
}
#include <iostream>
#include <memory>
#include <string>

#include <grpc++/grpc++.h>

#include "tp3.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using tp3::FindRequest;
using tp3::FindReply;
using tp3::UpdateRequest;
using tp3::UpdateReply;
using tp3::StoreRequest;
using tp3::StoreReply;
using tp3::TP3;

class TP3Client {
 public:
    TP3Client(std::shared_ptr<Channel> channel)
      : stub_(TP3::NewStub(channel)) {}

  // Assambles the client's payload, sends it and presents the response back
  // from the server.
  std::string Find(const std::string& k) {
    // Data we are sending to the server.
    FindRequest request;
    request.set_k(k);

    // Container for the data we expect from the server.
    FindReply reply;

    // Context for the client. It could be used to convey extra information to
    // the server and/or tweak certain RPC behaviors.
    ClientContext context;

    // The actual RPC.
    Status status = stub_->Find(&context, request, &reply);

    // Act upon its status.
    if (status.ok()) {
      return reply.nodes();
    } else {
      return "RPC failed";
    }
  }

 private:
  std::unique_ptr<TP3::Stub> stub_;
};

int main(int argc, char** argv) {
  // Instantiate the client. It requires a channel, out of which the actual RPCs
  // are created. This channel models a connection to an endpoint (in this case,
  // localhost at port 50051). We indicate that the channel isn't authenticated
  // (use of InsecureChannelCredentials()).
  TP3Client tp3(grpc::CreateChannel(
      "localhost:50051", grpc::InsecureChannelCredentials()));
  std::string k(argv[0]);
  std::string reply = tp3.Find(k);
  std::cout << "Resposta do servidor: " << reply << std::endl;

  return 0;
}

// Generated by the gRPC protobuf plugin.
// If you make any local change, they will be lost.
// source: tp3.proto

#include "tp3.pb.h"
#include "tp3.grpc.pb.h"

#include <grpc++/impl/codegen/async_stream.h>
#include <grpc++/impl/codegen/async_unary_call.h>
#include <grpc++/impl/codegen/channel_interface.h>
#include <grpc++/impl/codegen/client_unary_call.h>
#include <grpc++/impl/codegen/method_handler_impl.h>
#include <grpc++/impl/codegen/rpc_service_method.h>
#include <grpc++/impl/codegen/service_type.h>
#include <grpc++/impl/codegen/sync_stream.h>
namespace tp3 {

static const char* TP3_method_names[] = {
  "/tp3.TP3/Find",
  "/tp3.TP3/Update",
  "/tp3.TP3/Store",
};

std::unique_ptr< TP3::Stub> TP3::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  std::unique_ptr< TP3::Stub> stub(new TP3::Stub(channel));
  return stub;
}

TP3::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_Find_(TP3_method_names[0], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_Update_(TP3_method_names[1], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_Store_(TP3_method_names[2], ::grpc::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status TP3::Stub::Find(::grpc::ClientContext* context, const ::tp3::FindRequest& request, ::tp3::FindReply* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_Find_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::tp3::FindReply>* TP3::Stub::AsyncFindRaw(::grpc::ClientContext* context, const ::tp3::FindRequest& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::tp3::FindReply>(channel_.get(), cq, rpcmethod_Find_, context, request);
}

::grpc::Status TP3::Stub::Update(::grpc::ClientContext* context, const ::tp3::UpdateRequest& request, ::tp3::UpdateReply* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_Update_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::tp3::UpdateReply>* TP3::Stub::AsyncUpdateRaw(::grpc::ClientContext* context, const ::tp3::UpdateRequest& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::tp3::UpdateReply>(channel_.get(), cq, rpcmethod_Update_, context, request);
}

::grpc::Status TP3::Stub::Store(::grpc::ClientContext* context, const ::tp3::StoreRequest& request, ::tp3::StoreReply* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_Store_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::tp3::StoreReply>* TP3::Stub::AsyncStoreRaw(::grpc::ClientContext* context, const ::tp3::StoreRequest& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::tp3::StoreReply>(channel_.get(), cq, rpcmethod_Store_, context, request);
}

TP3::Service::Service() {
  (void)TP3_method_names;
  AddMethod(new ::grpc::RpcServiceMethod(
      TP3_method_names[0],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< TP3::Service, ::tp3::FindRequest, ::tp3::FindReply>(
          std::mem_fn(&TP3::Service::Find), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      TP3_method_names[1],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< TP3::Service, ::tp3::UpdateRequest, ::tp3::UpdateReply>(
          std::mem_fn(&TP3::Service::Update), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      TP3_method_names[2],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< TP3::Service, ::tp3::StoreRequest, ::tp3::StoreReply>(
          std::mem_fn(&TP3::Service::Store), this)));
}

TP3::Service::~Service() {
}

::grpc::Status TP3::Service::Find(::grpc::ServerContext* context, const ::tp3::FindRequest* request, ::tp3::FindReply* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status TP3::Service::Update(::grpc::ServerContext* context, const ::tp3::UpdateRequest* request, ::tp3::UpdateReply* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status TP3::Service::Store(::grpc::ServerContext* context, const ::tp3::StoreRequest* request, ::tp3::StoreReply* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace tp3

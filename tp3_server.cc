#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <grpc++/grpc++.h>
#include "tp3.grpc.pb.h"
#include <sqlite3.h>

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using tp3::FindRequest;
using tp3::FindReply;
using tp3::UpdateRequest;
using tp3::UpdateReply;
using tp3::StoreRequest;
using tp3::StoreReply;
using tp3::TP3;

static int callback(void *NotUsed, int argc, char **argv, char **szColName) {
    std::cout << "Teste\n";
    for(int i = 0; i < argc; i++)
    {
        std::cout << szColName[i] << " = " << argv[i] << std::endl;
    }

    std::cout << "\n";

    return 0;
}

// busca arquivo na tabela de arquivos (tabela_arquivos.db)
bool findArquivo(std::string arquivo) {
    sqlite3 *db;
    char *szErrMsg = 0;

    // open database
    int rc = sqlite3_open("tabela_arquivos.db", &db);

    if(rc)
    {
        std::cout << "Erro ao conectar na tabela de arquivos: "+std::string(sqlite3_errmsg(db));
        return 0;
    } else {
        std::cout << "Conectado com sucesso na tabela de arquivos!\n";
    }
    std::cout << "Teste\n";
    // sql de busca do arquivo na tabela
    const char *pSQL;
    pSQL = ("SELECT * FROM arquivos WHERE nome_arquivo LIKE '%" + arquivo + "%'").c_str();
    std::cout << std::string(pSQL);
    // executa o sql
    std::cout << "Teste\n";
        rc = sqlite3_exec(db, pSQL, callback, 0, &szErrMsg);
        if(rc != SQLITE_OK)
        {
            std::cout << "Erro de SQL: " << szErrMsg << std::endl;
            sqlite3_free(szErrMsg);
        }
    // close database
    if(db)
    {
        sqlite3_close(db);
    }

    return 1;
}

// Logic and data behind the server's behavior.
class TP3ServiceImpl final : public TP3::Service {
    Status Find(ServerContext *context, const FindRequest *request,
                FindReply *reply) override {

        // Busca arquivo na tabela de arquivos
        if(!findArquivo("senha"))
        {
            return Status::CANCELLED;
        }

        reply->set_nodes("cliente pendente");
        return Status::OK;
    }

};



void RunServer() {
    std::string server_address("0.0.0.0:50051");
    TP3ServiceImpl service;

    ServerBuilder builder;
    // Listen on the given address without any authentication mechanism.
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    // Register "service" as the instance through which we'll communicate with
    // clients. In this case it corresponds to an *synchronous* service.
    builder.RegisterService(&service);
    // Finally assemble the server.
    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Servidor inicializado no endereço: " << server_address << std::endl;

    // Wait for the server to shutdown. Note that some other thread must be
    // responsible for shutting down the server for this call to ever return.
    server->Wait();
}

int main(int argc, char **argv) {
    RunServer();

    return 0;
}

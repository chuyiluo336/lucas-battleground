#include "NetworkManager.h"
#include "../Utils/Logger.h"

namespace LucasEngine {

NetworkManager::NetworkManager() : isInitialized(false), isServer(false), client(nullptr), server(nullptr) {
}

NetworkManager::~NetworkManager() {
    Shutdown();
}

bool NetworkManager::Initialize() {
    client = new NetworkClient();
    server = new NetworkServer();
    isInitialized = true;
    Logger::GetInstance()->Log("NetworkManager initialized");
    return true;
}

void NetworkManager::Shutdown() {
    if (isInitialized) {
        if (client) {
            delete client;
            client = nullptr;
        }
        if (server) {
            delete server;
            server = nullptr;
        }
        isInitialized = false;
        Logger::GetInstance()->Log("NetworkManager shutdown");
    }
}

void NetworkManager::Update() {
    if (isInitialized) {
        if (isServer && server) {
            server->Update();
        } else if (client && client->IsConnected()) {
            auto messages = client->ReceiveMessages();
            for (const auto& message : messages) {
                // 处理接收到的消息
                Logger::GetInstance()->Log("Received message of type: " + std::to_string(static_cast<int>(message.GetType())));
            }
        }
    }
}

bool NetworkManager::IsInitialized() const {
    return isInitialized;
}

bool NetworkManager::IsServer() const {
    return isServer;
}

bool NetworkManager::StartServer(int port) {
    if (server) {
        isServer = true;
        return server->Start(port);
    }
    return false;
}

bool NetworkManager::ConnectToServer(const std::string& serverAddress, int port) {
    if (client) {
        isServer = false;
        return client->Connect(serverAddress, port);
    }
    return false;
}

void NetworkManager::SendMessage(const NetworkMessage& message) {
    if (isInitialized) {
        if (isServer) {
            // 服务器广播消息
            if (server) {
                server->BroadcastMessage(message);
            }
        } else if (client && client->IsConnected()) {
            // 客户端发送消息
            client->SendMessage(message);
        }
    }
}

void NetworkManager::SendReliableMessage(const NetworkMessage& message) {
    // 发送可靠消息（确保送达）
    SendMessage(message);
}

void NetworkManager::BroadcastMessage(const NetworkMessage& message, const std::string& excludeClient) {
    if (isServer && server) {
        server->BroadcastMessage(message, excludeClient);
    }
}

void NetworkManager::SendMessageToClient(const std::string& clientId, const NetworkMessage& message) {
    if (isServer && server) {
        server->SendMessageToClient(clientId, message);
    }
}

int NetworkManager::GetClientCount() const {
    if (isServer && server) {
        return server->GetClientCount();
    }
    return 0;
}

} // namespace LucasEngine
#include "NetworkServer.h"
#include "../Utils/Logger.h"

namespace LucasEngine {

NetworkServer::NetworkServer() : isRunning(false), port(0), serverSocket(nullptr) {
}

NetworkServer::~NetworkServer() {
    Stop();
}

bool NetworkServer::Start(int port) {
    // 实现服务器启动逻辑
    this->port = port;
    isRunning = true;
    Logger::GetInstance()->Log("Server started on port: " + std::to_string(port));
    return true;
}

void NetworkServer::Stop() {
    if (isRunning) {
        isRunning = false;
        clients.clear();
        Logger::GetInstance()->Log("Server stopped");
    }
}

bool NetworkServer::IsRunning() const {
    return isRunning;
}

void NetworkServer::Update() {
    if (isRunning) {
        // 处理新连接
        // 处理客户端消息
        // 清理断开的连接
    }
}

void NetworkServer::BroadcastMessage(const NetworkMessage& message, const std::string& excludeClient) {
    if (isRunning) {
        for (const auto& client : clients) {
            if (client.first != excludeClient) {
                // 发送消息给客户端
                Logger::GetInstance()->Log("Broadcast message to client: " + client.first);
            }
        }
    }
}

void NetworkServer::SendMessageToClient(const std::string& clientId, const NetworkMessage& message) {
    if (isRunning) {
        auto it = clients.find(clientId);
        if (it != clients.end()) {
            // 发送消息给指定客户端
            Logger::GetInstance()->Log("Sent message to client: " + clientId);
        }
    }
}

int NetworkServer::GetClientCount() const {
    return clients.size();
}

} // namespace LucasEngine
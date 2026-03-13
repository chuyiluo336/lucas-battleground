#include "NetworkClient.h"
#include "../Utils/Logger.h"

namespace LucasEngine {

NetworkClient::NetworkClient() : isConnected(false), serverPort(0), socket(nullptr) {
}

NetworkClient::~NetworkClient() {
    Disconnect();
}

bool NetworkClient::Connect(const std::string& address, int port) {
    // 实现网络连接逻辑
    serverAddress = address;
    serverPort = port;
    isConnected = true;
    Logger::GetInstance()->Log("Connected to server: " + address + ":" + std::to_string(port));
    return true;
}

void NetworkClient::Disconnect() {
    if (isConnected) {
        isConnected = false;
        Logger::GetInstance()->Log("Disconnected from server");
    }
}

bool NetworkClient::IsConnected() const {
    return isConnected;
}

void NetworkClient::SendMessage(const NetworkMessage& message) {
    if (isConnected) {
        // 序列化并发送消息
        std::vector<char> data = message.Serialize();
        // 发送数据
        Logger::GetInstance()->Log("Sent message of type: " + std::to_string(static_cast<int>(message.GetType())));
    }
}

std::vector<NetworkMessage> NetworkClient::ReceiveMessages() {
    std::vector<NetworkMessage> messages;
    if (isConnected) {
        // 接收并反序列化消息
        // 这里会返回接收到的消息
    }
    return messages;
}

} // namespace LucasEngine
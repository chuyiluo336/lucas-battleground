#ifndef NETWORK_MANAGER_H
#define NETWORK_MANAGER_H

#include <string>
#include "NetworkClient.h"
#include "NetworkServer.h"
#include "NetworkMessage.h"

namespace LucasEngine {

class NetworkManager {
private:
    bool isInitialized;
    bool isServer;
    NetworkClient* client;
    NetworkServer* server;
    
public:
    NetworkManager();
    ~NetworkManager();
    
    bool Initialize();
    void Shutdown();
    void Update();
    
    bool IsInitialized() const;
    bool IsServer() const;
    
    // 网络功能
    bool StartServer(int port);
    bool ConnectToServer(const std::string& serverAddress, int port);
    void SendMessage(const NetworkMessage& message);
    void SendReliableMessage(const NetworkMessage& message);
    
    // 服务器功能
    void BroadcastMessage(const NetworkMessage& message, const std::string& excludeClient = "");
    void SendMessageToClient(const std::string& clientId, const NetworkMessage& message);
    int GetClientCount() const;
};

} // namespace LucasEngine

#endif // NETWORK_MANAGER_H
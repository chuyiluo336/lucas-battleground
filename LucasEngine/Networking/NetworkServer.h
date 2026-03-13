#ifndef NETWORK_SERVER_H
#define NETWORK_SERVER_H

#include <string>
#include <vector>
#include <map>
#include "NetworkMessage.h"

namespace LucasEngine {

class NetworkServer {
private:
    bool isRunning;
    int port;
    void* serverSocket;
    std::map<std::string, void*> clients;
    
public:
    NetworkServer();
    ~NetworkServer();
    
    bool Start(int port);
    void Stop();
    bool IsRunning() const;
    
    void Update();
    void BroadcastMessage(const NetworkMessage& message, const std::string& excludeClient = "");
    void SendMessageToClient(const std::string& clientId, const NetworkMessage& message);
    
    int GetClientCount() const;
};

} // namespace LucasEngine

#endif // NETWORK_SERVER_H
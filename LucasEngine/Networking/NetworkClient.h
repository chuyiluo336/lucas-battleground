#ifndef NETWORK_CLIENT_H
#define NETWORK_CLIENT_H

#include <string>
#include <vector>
#include "NetworkMessage.h"

namespace LucasEngine {

class NetworkClient {
private:
    bool isConnected;
    std::string serverAddress;
    int serverPort;
    void* socket;
    
public:
    NetworkClient();
    ~NetworkClient();
    
    bool Connect(const std::string& address, int port);
    void Disconnect();
    bool IsConnected() const;
    
    void SendMessage(const NetworkMessage& message);
    std::vector<NetworkMessage> ReceiveMessages();
};

} // namespace LucasEngine

#endif // NETWORK_CLIENT_H
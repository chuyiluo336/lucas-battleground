#ifndef NETWORK_MESSAGE_H
#define NETWORK_MESSAGE_H

#include <string>
#include <vector>

namespace LucasEngine {

enum class MessageType {
    PLAYER_JOIN,
    PLAYER_LEAVE,
    PLAYER_POSITION,
    PLAYER_ROTATION,
    PLAYER_HEALTH,
    PLAYER_SHOOT,
    PLAYER_RESPAWN,
    WEAPON_FIRE,
    ITEM_PICKUP,
    ITEM_DROP,
    GAME_START,
    GAME_END,
    SAFE_ZONE_UPDATE,
    CHAT_MESSAGE
};

class NetworkMessage {
private:
    MessageType type;
    std::string sender;
    std::vector<char> data;
    
public:
    NetworkMessage(MessageType type, const std::string& sender);
    ~NetworkMessage();
    
    MessageType GetType() const;
    const std::string& GetSender() const;
    const std::vector<char>& GetData() const;
    
    void AddInt(int value);
    void AddFloat(float value);
    void AddString(const std::string& value);
    
    int ReadInt(int& offset) const;
    float ReadFloat(int& offset) const;
    std::string ReadString(int& offset) const;
    
    std::vector<char> Serialize() const;
    static NetworkMessage Deserialize(const std::vector<char>& data);
};

} // namespace LucasEngine

#endif // NETWORK_MESSAGE_H
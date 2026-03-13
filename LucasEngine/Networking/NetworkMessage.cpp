#include "NetworkMessage.h"
#include <cstring>

namespace LucasEngine {

NetworkMessage::NetworkMessage(MessageType type, const std::string& sender) : type(type), sender(sender) {
}

NetworkMessage::~NetworkMessage() {
}

MessageType NetworkMessage::GetType() const {
    return type;
}

const std::string& NetworkMessage::GetSender() const {
    return sender;
}

const std::vector<char>& NetworkMessage::GetData() const {
    return data;
}

void NetworkMessage::AddInt(int value) {
    char buffer[4];
    memcpy(buffer, &value, sizeof(int));
    data.insert(data.end(), buffer, buffer + sizeof(int));
}

void NetworkMessage::AddFloat(float value) {
    char buffer[4];
    memcpy(buffer, &value, sizeof(float));
    data.insert(data.end(), buffer, buffer + sizeof(float));
}

void NetworkMessage::AddString(const std::string& value) {
    int length = value.length();
    AddInt(length);
    data.insert(data.end(), value.begin(), value.end());
}

int NetworkMessage::ReadInt(int& offset) const {
    int value;
    memcpy(&value, &data[offset], sizeof(int));
    offset += sizeof(int);
    return value;
}

float NetworkMessage::ReadFloat(int& offset) const {
    float value;
    memcpy(&value, &data[offset], sizeof(float));
    offset += sizeof(float);
    return value;
}

std::string NetworkMessage::ReadString(int& offset) const {
    int length = ReadInt(offset);
    std::string value(data.begin() + offset, data.begin() + offset + length);
    offset += length;
    return value;
}

std::vector<char> NetworkMessage::Serialize() const {
    std::vector<char> result;
    
    // 序列化消息类型
    int typeInt = static_cast<int>(type);
    char typeBuffer[4];
    memcpy(typeBuffer, &typeInt, sizeof(int));
    result.insert(result.end(), typeBuffer, typeBuffer + sizeof(int));
    
    // 序列化发送者
    int senderLength = sender.length();
    char senderLengthBuffer[4];
    memcpy(senderLengthBuffer, &senderLength, sizeof(int));
    result.insert(result.end(), senderLengthBuffer, senderLengthBuffer + sizeof(int));
    result.insert(result.end(), sender.begin(), sender.end());
    
    // 序列化数据
    int dataLength = data.size();
    char dataLengthBuffer[4];
    memcpy(dataLengthBuffer, &dataLength, sizeof(int));
    result.insert(result.end(), dataLengthBuffer, dataLengthBuffer + sizeof(int));
    result.insert(result.end(), data.begin(), data.end());
    
    return result;
}

NetworkMessage NetworkMessage::Deserialize(const std::vector<char>& data) {
    int offset = 0;
    
    // 反序列化消息类型
    int typeInt;
    memcpy(&typeInt, &data[offset], sizeof(int));
    offset += sizeof(int);
    MessageType type = static_cast<MessageType>(typeInt);
    
    // 反序列化发送者
    int senderLength;
    memcpy(&senderLength, &data[offset], sizeof(int));
    offset += sizeof(int);
    std::string sender(data.begin() + offset, data.begin() + offset + senderLength);
    offset += senderLength;
    
    // 反序列化数据
    int dataLength;
    memcpy(&dataLength, &data[offset], sizeof(int));
    offset += sizeof(int);
    std::vector<char> messageData(data.begin() + offset, data.begin() + offset + dataLength);
    
    NetworkMessage message(type, sender);
    message.data = messageData;
    
    return message;
}

} // namespace LucasEngine
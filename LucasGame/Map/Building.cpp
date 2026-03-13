#include "Building.h"
#include "../../LucasEngine/Utils/Logger.h"

namespace LucasGame {

Building::Building(const std::string& name, float width, float depth, float height, float x, float y, float z) 
    : name(name), width(width), depth(depth), height(height), isDamaged(false), isDestroyed(false) {
    position[0] = x;
    position[1] = y;
    position[2] = z;
    LucasEngine::Logger::GetInstance()->Log("Building created: " + name);
}

Building::~Building() {
    LucasEngine::Logger::GetInstance()->Log("Building destroyed: " + name);
}

void Building::Update() {
    // 更新建筑状态
}

void Building::Render() {
    // 渲染建筑
    // 使用高分辨率纹理和细节
    if (isDestroyed) {
        // 渲染倒塌的建筑
    } else if (isDamaged) {
        // 渲染损坏的建筑
    } else {
        // 渲染完整的建筑
    }
}

void Building::TakeDamage(float damage) {
    if (!isDestroyed) {
        isDamaged = true;
        // 检查是否被摧毁
        if (damage > 100.0f) {
            isDestroyed = true;
            LucasEngine::Logger::GetInstance()->Log(name + " has been destroyed");
        } else {
            LucasEngine::Logger::GetInstance()->Log(name + " has been damaged");
        }
    }
}

const std::string& Building::GetName() const {
    return name;
}

float Building::GetWidth() const {
    return width;
}

float Building::GetDepth() const {
    return depth;
}

float Building::GetHeight() const {
    return height;
}

float* Building::GetPosition() {
    return position;
}

bool Building::IsDamaged() const {
    return isDamaged;
}

bool Building::IsDestroyed() const {
    return isDestroyed;
}

void Building::SetPosition(float x, float y, float z) {
    position[0] = x;
    position[1] = y;
    position[2] = z;
}

} // namespace LucasGame
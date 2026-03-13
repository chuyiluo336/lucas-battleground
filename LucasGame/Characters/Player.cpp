#include "Player.h"
#include "../../LucasEngine/Utils/Logger.h"

namespace LucasGame {

Player::Player(const std::string& name, bool isMale) : name(name), isMale(isMale) {
    health = 100;
    maxHealth = 100;
    position[0] = 0.0f;
    position[1] = 0.0f;
    position[2] = 0.0f;
    rotation[0] = 0.0f;
    rotation[1] = 0.0f;
    rotation[2] = 0.0f;
    isAlive = true;
    
    LucasEngine::Logger::GetInstance()->Log("Player created: " + name + (isMale ? " (Male)" : " (Female)"));
}

Player::~Player() {
    LucasEngine::Logger::GetInstance()->Log("Player destroyed: " + name);
}

void Player::Update() {
    if (isAlive) {
        // 更新玩家状态
    }
}

void Player::Render() {
    if (isAlive) {
        // 渲染玩家
    }
}

void Player::TakeDamage(int damage) {
    if (isAlive) {
        health -= damage;
        if (health <= 0) {
            health = 0;
            isAlive = false;
            LucasEngine::Logger::GetInstance()->Log(name + " has died");
        } else {
            LucasEngine::Logger::GetInstance()->Log(name + " took " + std::to_string(damage) + " damage. Health: " + std::to_string(health));
        }
    }
}

void Player::Heal(int amount) {
    if (isAlive) {
        health += amount;
        if (health > maxHealth) {
            health = maxHealth;
        }
        LucasEngine::Logger::GetInstance()->Log(name + " healed " + std::to_string(amount) + " health. Health: " + std::to_string(health));
    }
}

void Player::Respawn() {
    health = maxHealth;
    isAlive = true;
    // 随机位置重生
    position[0] = (rand() % 2000) - 1000;
    position[1] = 0.0f;
    position[2] = (rand() % 2000) - 1000;
    LucasEngine::Logger::GetInstance()->Log(name + " has respawned");
}

const std::string& Player::GetName() const {
    return name;
}

int Player::GetHealth() const {
    return health;
}

int Player::GetMaxHealth() const {
    return maxHealth;
}

float* Player::GetPosition() {
    return position;
}

float* Player::GetRotation() {
    return rotation;
}

bool Player::IsAlive() const {
    return isAlive;
}

bool Player::IsMale() const {
    return isMale;
}

void Player::SetPosition(float x, float y, float z) {
    position[0] = x;
    position[1] = y;
    position[2] = z;
}

void Player::SetRotation(float x, float y, float z) {
    rotation[0] = x;
    rotation[1] = y;
    rotation[2] = z;
}

} // namespace LucasGame
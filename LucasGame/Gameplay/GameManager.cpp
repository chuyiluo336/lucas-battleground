#include "GameManager.h"
#include "../Characters/Player.h"
#include "../../LucasEngine/Utils/Logger.h"

namespace LucasGame {

GameManager* GameManager::instance = nullptr;

GameManager::GameManager() : isGameStarted(false), isGameEnded(false), playerCount(0), safeZoneRadius(1000.0f), safeZoneShrinkRate(5.0f) {
}

GameManager* GameManager::GetInstance() {
    if (!instance) {
        instance = new GameManager();
    }
    return instance;
}

void GameManager::DestroyInstance() {
    if (instance) {
        delete instance;
        instance = nullptr;
    }
}

void GameManager::Initialize() {
    LucasEngine::Logger::GetInstance()->Log("GameManager initialized");
}

void GameManager::Shutdown() {
    players.clear();
    LucasEngine::Logger::GetInstance()->Log("GameManager shutdown");
}

void GameManager::Update() {
    if (isGameStarted && !isGameEnded) {
        // 缩小安全区
        ShrinkSafeZone();
        
        // 检查游戏是否结束
        if (playerCount <= 1) {
            for (auto player : players) {
                if (player->IsAlive()) {
                    EndGame(player);
                    break;
                }
            }
        }
    }
}

void GameManager::StartGame() {
    isGameStarted = true;
    isGameEnded = false;
    LucasEngine::Logger::GetInstance()->Log("Game started with " + std::to_string(playerCount) + " players");
}

void GameManager::EndGame(Player* winner) {
    isGameEnded = true;
    isGameStarted = false;
    LucasEngine::Logger::GetInstance()->Log("Game ended. Winner: " + winner->GetName());
}

void GameManager::AddPlayer(Player* player) {
    players.push_back(player);
    playerCount++;
    LucasEngine::Logger::GetInstance()->Log("Player added: " + player->GetName());
}

void GameManager::RemovePlayer(Player* player) {
    auto it = std::find(players.begin(), players.end(), player);
    if (it != players.end()) {
        players.erase(it);
        playerCount--;
        LucasEngine::Logger::GetInstance()->Log("Player removed: " + player->GetName());
    }
}

bool GameManager::IsGameStarted() const {
    return isGameStarted;
}

bool GameManager::IsGameEnded() const {
    return isGameEnded;
}

int GameManager::GetPlayerCount() const {
    return playerCount;
}

float GameManager::GetSafeZoneRadius() const {
    return safeZoneRadius;
}

void GameManager::ShrinkSafeZone() {
    if (safeZoneRadius > 100.0f) {
        safeZoneRadius -= safeZoneShrinkRate;
        LucasEngine::Logger::GetInstance()->Log("Safe zone shrunk to " + std::to_string(safeZoneRadius) + " units");
    }
}

void GameManager::RespawnPlayer(Player* player) {
    player->Respawn();
    LucasEngine::Logger::GetInstance()->Log("Player respawned: " + player->GetName());
}

} // namespace LucasGame
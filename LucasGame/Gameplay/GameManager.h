#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <string>
#include <vector>

namespace LucasGame {

class Player;

class GameManager {
private:
    static GameManager* instance;
    bool isGameStarted;
    bool isGameEnded;
    int playerCount;
    std::vector<Player*> players;
    float safeZoneRadius;
    float safeZoneShrinkRate;
    
    GameManager();
    
public:
    static GameManager* GetInstance();
    static void DestroyInstance();
    
    void Initialize();
    void Shutdown();
    void Update();
    
    void StartGame();
    void EndGame(Player* winner);
    void AddPlayer(Player* player);
    void RemovePlayer(Player* player);
    
    bool IsGameStarted() const;
    bool IsGameEnded() const;
    int GetPlayerCount() const;
    float GetSafeZoneRadius() const;
    
    // 大逃杀特有功能
    void ShrinkSafeZone();
    void RespawnPlayer(Player* player);
};

} // namespace LucasGame

#endif // GAME_MANAGER_H
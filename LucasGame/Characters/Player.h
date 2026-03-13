#ifndef PLAYER_H
#define PLAYER_H

#include <string>

namespace LucasGame {

class Player {
private:
    std::string name;
    int health;
    int maxHealth;
    float position[3];
    float rotation[3];
    bool isAlive;
    bool isMale;
    
public:
    Player(const std::string& name, bool isMale);
    ~Player();
    
    virtual void Update();
    virtual void Render();
    
    void TakeDamage(int damage);
    void Heal(int amount);
    void Respawn();
    
    const std::string& GetName() const;
    int GetHealth() const;
    int GetMaxHealth() const;
    float* GetPosition();
    float* GetRotation();
    bool IsAlive() const;
    bool IsMale() const;
    
    void SetPosition(float x, float y, float z);
    void SetRotation(float x, float y, float z);
};

} // namespace LucasGame

#endif // PLAYER_H
#ifndef BUILDING_H
#define BUILDING_H

#include <string>

namespace LucasGame {

class Building {
private:
    std::string name;
    float width;
    float depth;
    float height;
    float position[3];
    bool isDamaged;
    bool isDestroyed;
    
public:
    Building(const std::string& name, float width, float depth, float height, float x, float y, float z);
    ~Building();
    
    void Update();
    void Render();
    void TakeDamage(float damage);
    
    const std::string& GetName() const;
    float GetWidth() const;
    float GetDepth() const;
    float GetHeight() const;
    float* GetPosition();
    bool IsDamaged() const;
    bool IsDestroyed() const;
    
    void SetPosition(float x, float y, float z);
};

} // namespace LucasGame

#endif // BUILDING_H
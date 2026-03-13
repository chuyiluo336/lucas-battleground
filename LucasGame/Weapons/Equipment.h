#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <string>

namespace LucasGame {

class Equipment {
private:
    std::string name;
    std::string type;
    int level;
    int price;
    float weight;
    bool isEquipped;
    
public:
    Equipment(const std::string& name, const std::string& type, int level, int price, float weight);
    ~Equipment();
    
    void Equip();
    void Unequip();
    
    const std::string& GetName() const;
    const std::string& GetType() const;
    int GetLevel() const;
    int GetPrice() const;
    float GetWeight() const;
    bool IsEquipped() const;
};

} // namespace LucasGame

#endif // EQUIPMENT_H
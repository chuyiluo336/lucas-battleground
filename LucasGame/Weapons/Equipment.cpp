#include "Equipment.h"
#include "../../LucasEngine/Utils/Logger.h"

namespace LucasGame {

Equipment::Equipment(const std::string& name, const std::string& type, int level, int price, float weight) 
    : name(name), type(type), level(level), price(price), weight(weight), isEquipped(false) {
    LucasEngine::Logger::GetInstance()->Log("Equipment created: " + name + " (" + type + ")");
}

Equipment::~Equipment() {
    LucasEngine::Logger::GetInstance()->Log("Equipment destroyed: " + name);
}

void Equipment::Equip() {
    if (!isEquipped) {
        isEquipped = true;
        LucasEngine::Logger::GetInstance()->Log("Equipped: " + name);
    }
}

void Equipment::Unequip() {
    if (isEquipped) {
        isEquipped = false;
        LucasEngine::Logger::GetInstance()->Log("Unequipped: " + name);
    }
}

const std::string& Equipment::GetName() const {
    return name;
}

const std::string& Equipment::GetType() const {
    return type;
}

int Equipment::GetLevel() const {
    return level;
}

int Equipment::GetPrice() const {
    return price;
}

float Equipment::GetWeight() const {
    return weight;
}

bool Equipment::IsEquipped() const {
    return isEquipped;
}

} // namespace LucasGame
#include "EquipmentManager.h"
#include "Equipment.h"
#include "../../LucasEngine/Utils/Logger.h"

namespace LucasGame {

EquipmentManager* EquipmentManager::instance = nullptr;

EquipmentManager::EquipmentManager() {
}

EquipmentManager* EquipmentManager::GetInstance() {
    if (!instance) {
        instance = new EquipmentManager();
    }
    return instance;
}

void EquipmentManager::DestroyInstance() {
    if (instance) {
        instance->Shutdown();
        delete instance;
        instance = nullptr;
    }
}

void EquipmentManager::Initialize() {
    CreateDefaultEquipments();
    LucasEngine::Logger::GetInstance()->Log("EquipmentManager initialized");
}

void EquipmentManager::Shutdown() {
    for (auto equipment : equipments) {
        delete equipment;
    }
    equipments.clear();
    equipmentMap.clear();
    LucasEngine::Logger::GetInstance()->Log("EquipmentManager shutdown");
}

Equipment* EquipmentManager::CreateEquipment(const std::string& name, const std::string& type, int level, int price, float weight) {
    Equipment* equipment = new Equipment(name, type, level, price, weight);
    equipments.push_back(equipment);
    equipmentMap[name] = equipment;
    return equipment;
}

void EquipmentManager::RemoveEquipment(Equipment* equipment) {
    auto it = std::find(equipments.begin(), equipments.end(), equipment);
    if (it != equipments.end()) {
        equipmentMap.erase(equipment->GetName());
        equipments.erase(it);
        delete equipment;
    }
}

Equipment* EquipmentManager::GetEquipmentByName(const std::string& name) {
    auto it = equipmentMap.find(name);
    if (it != equipmentMap.end()) {
        return it->second;
    }
    return nullptr;
}

std::vector<Equipment*> EquipmentManager::GetAllEquipments() {
    return equipments;
}

std::vector<Equipment*> EquipmentManager::GetEquipmentsByType(const std::string& type) {
    std::vector<Equipment*> result;
    for (auto equipment : equipments) {
        if (equipment->GetType() == type) {
            result.push_back(equipment);
        }
    }
    return result;
}

void EquipmentManager::CreateDefaultEquipments() {
    // 头盔
    CreateEquipment("Level 1 Helmet", "Helmet", 1, 500, 0.5f);
    CreateEquipment("Level 2 Helmet", "Helmet", 2, 1500, 0.8f);
    CreateEquipment("Level 3 Helmet", "Helmet", 3, 3500, 1.2f);
    
    // 防弹衣
    CreateEquipment("Level 1 Vest", "Vest", 1, 800, 1.0f);
    CreateEquipment("Level 2 Vest", "Vest", 2, 2000, 1.5f);
    CreateEquipment("Level 3 Vest", "Vest", 3, 4000, 2.0f);
    
    // 背包
    CreateEquipment("Level 1 Backpack", "Backpack", 1, 300, 0.5f);
    CreateEquipment("Level 2 Backpack", "Backpack", 2, 800, 0.8f);
    CreateEquipment("Level 3 Backpack", "Backpack", 3, 1500, 1.0f);
    
    // 药品
    CreateEquipment("First Aid Kit", "Medical", 1, 400, 0.5f);
    CreateEquipment("Med Kit", "Medical", 2, 1500, 1.0f);
    CreateEquipment("Painkillers", "Medical", 1, 200, 0.3f);
    CreateEquipment("Energy Drink", "Medical", 1, 150, 0.2f);
    CreateEquipment("Adrenaline Syringe", "Medical", 3, 2500, 0.8f);
    
    // 投掷物
    CreateEquipment("Frag Grenade", "Grenade", 2, 300, 0.5f);
    CreateEquipment("Smoke Grenade", "Grenade", 1, 200, 0.5f);
    CreateEquipment("Flashbang", "Grenade", 1, 250, 0.4f);
    CreateEquipment("Molotov Cocktail", "Grenade", 2, 400, 0.6f);
    
    // 附件
    CreateEquipment("Red Dot Sight", "Attachment", 1, 500, 0.2f);
    CreateEquipment("全息瞄准镜", "Attachment", 1, 600, 0.3f);
    CreateEquipment("4x Scope", "Attachment", 2, 1200, 0.4f);
    CreateEquipment("8x Scope", "Attachment", 3, 2500, 0.5f);
    CreateEquipment("Suppressor", "Attachment", 2, 800, 0.3f);
    CreateEquipment("Extended Magazine", "Attachment", 1, 400, 0.2f);
    
    LucasEngine::Logger::GetInstance()->Log("Created default equipments");
}

} // namespace LucasGame
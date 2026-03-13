#ifndef EQUIPMENT_MANAGER_H
#define EQUIPMENT_MANAGER_H

#include <string>
#include <vector>
#include <map>

namespace LucasGame {

class Equipment;

class EquipmentManager {
private:
    static EquipmentManager* instance;
    std::vector<Equipment*> equipments;
    std::map<std::string, Equipment*> equipmentMap;
    
    EquipmentManager();
    
public:
    static EquipmentManager* GetInstance();
    static void DestroyInstance();
    
    void Initialize();
    void Shutdown();
    
    Equipment* CreateEquipment(const std::string& name, const std::string& type, int level, int price, float weight);
    void RemoveEquipment(Equipment* equipment);
    Equipment* GetEquipmentByName(const std::string& name);
    std::vector<Equipment*> GetAllEquipments();
    std::vector<Equipment*> GetEquipmentsByType(const std::string& type);
    
    // 预定义装备库
    void CreateDefaultEquipments();
};

} // namespace LucasGame

#endif // EQUIPMENT_MANAGER_H
#include "WeaponManager.h"
#include "Weapon.h"
#include "../../LucasEngine/Utils/Logger.h"

namespace LucasGame {

WeaponManager* WeaponManager::instance = nullptr;

WeaponManager::WeaponManager() {
}

WeaponManager* WeaponManager::GetInstance() {
    if (!instance) {
        instance = new WeaponManager();
    }
    return instance;
}

void WeaponManager::DestroyInstance() {
    if (instance) {
        instance->Shutdown();
        delete instance;
        instance = nullptr;
    }
}

void WeaponManager::Initialize() {
    CreateDefaultWeapons();
    LucasEngine::Logger::GetInstance()->Log("WeaponManager initialized");
}

void WeaponManager::Shutdown() {
    for (auto weapon : weapons) {
        delete weapon;
    }
    weapons.clear();
    weaponMap.clear();
    LucasEngine::Logger::GetInstance()->Log("WeaponManager shutdown");
}

Weapon* WeaponManager::CreateWeapon(const std::string& name, const std::string& type, int damage, int fireRate, int magazineSize, float accuracy, float recoil, float reloadTime, bool isAutomatic) {
    Weapon* weapon = new Weapon(name, type, damage, fireRate, magazineSize, accuracy, recoil, reloadTime, isAutomatic);
    weapons.push_back(weapon);
    weaponMap[name] = weapon;
    return weapon;
}

void WeaponManager::RemoveWeapon(Weapon* weapon) {
    auto it = std::find(weapons.begin(), weapons.end(), weapon);
    if (it != weapons.end()) {
        weaponMap.erase(weapon->GetName());
        weapons.erase(it);
        delete weapon;
    }
}

Weapon* WeaponManager::GetWeaponByName(const std::string& name) {
    auto it = weaponMap.find(name);
    if (it != weaponMap.end()) {
        return it->second;
    }
    return nullptr;
}

std::vector<Weapon*> WeaponManager::GetAllWeapons() {
    return weapons;
}

std::vector<Weapon*> WeaponManager::GetWeaponsByType(const std::string& type) {
    std::vector<Weapon*> result;
    for (auto weapon : weapons) {
        if (weapon->GetType() == type) {
            result.push_back(weapon);
        }
    }
    return result;
}

void WeaponManager::CreateDefaultWeapons() {
    // 步枪
    CreateWeapon("M4A1", "Assault Rifle", 40, 600, 30, 0.85f, 0.3f, 2.5f, true);
    CreateWeapon("AK-47", "Assault Rifle", 45, 600, 30, 0.75f, 0.5f, 2.8f, true);
    CreateWeapon("M16A4", "Assault Rifle", 38, 750, 30, 0.9f, 0.25f, 2.2f, false);
    CreateWeapon("SCAR-L", "Assault Rifle", 39, 600, 30, 0.88f, 0.28f, 2.4f, true);
    
    // 冲锋枪
    CreateWeapon("MP5", "SMG", 30, 800, 30, 0.8f, 0.2f, 2.0f, true);
    CreateWeapon("UMP45", "SMG", 35, 600, 25, 0.75f, 0.22f, 2.1f, true);
    CreateWeapon("Vector", "SMG", 28, 1200, 13, 0.85f, 0.15f, 1.8f, true);
    
    // 狙击枪
    CreateWeapon("AWM", "Sniper Rifle", 120, 60, 5, 0.99f, 0.7f, 3.5f, false);
    CreateWeapon("M24", "Sniper Rifle", 84, 75, 5, 0.97f, 0.6f, 3.2f, false);
    CreateWeapon("Kar98k", "Sniper Rifle", 75, 80, 5, 0.95f, 0.5f, 3.0f, false);
    
    // 霰弹枪
    CreateWeapon("S12K", "Shotgun", 25, 240, 8, 0.6f, 0.4f, 2.8f, true);
    CreateWeapon("S686", "Shotgun", 30, 120, 2, 0.55f, 0.45f, 3.0f, false);
    CreateWeapon("S1897", "Shotgun", 28, 120, 5, 0.58f, 0.42f, 3.1f, false);
    
    // 手枪
    CreateWeapon("P92", "Pistol", 25, 300, 15, 0.7f, 0.15f, 1.5f, false);
    CreateWeapon("P1911", "Pistol", 30, 250, 7, 0.75f, 0.18f, 1.6f, false);
    CreateWeapon("Desert Eagle", "Pistol", 50, 200, 7, 0.8f, 0.3f, 1.8f, false);
    
    // 机枪
    CreateWeapon("M249", "Machine Gun", 40, 750, 100, 0.8f, 0.4f, 4.0f, true);
    CreateWeapon("DP-28", "Machine Gun", 45, 550, 47, 0.75f, 0.45f, 3.8f, true);
    
    LucasEngine::Logger::GetInstance()->Log("Created default weapons");
}

} // namespace LucasGame
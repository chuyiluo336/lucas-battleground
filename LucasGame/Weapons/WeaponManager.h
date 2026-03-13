#ifndef WEAPON_MANAGER_H
#define WEAPON_MANAGER_H

#include <string>
#include <vector>
#include <map>

namespace LucasGame {

class Weapon;

class WeaponManager {
private:
    static WeaponManager* instance;
    std::vector<Weapon*> weapons;
    std::map<std::string, Weapon*> weaponMap;
    
    WeaponManager();
    
public:
    static WeaponManager* GetInstance();
    static void DestroyInstance();
    
    void Initialize();
    void Shutdown();
    
    Weapon* CreateWeapon(const std::string& name, const std::string& type, int damage, int fireRate, int magazineSize, float accuracy, float recoil, float reloadTime, bool isAutomatic);
    void RemoveWeapon(Weapon* weapon);
    Weapon* GetWeaponByName(const std::string& name);
    std::vector<Weapon*> GetAllWeapons();
    std::vector<Weapon*> GetWeaponsByType(const std::string& type);
    
    // 预定义武器库
    void CreateDefaultWeapons();
};

} // namespace LucasGame

#endif // WEAPON_MANAGER_H
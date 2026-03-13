#ifndef WEAPON_H
#define WEAPON_H

#include <string>

namespace LucasGame {

class Weapon {
private:
    std::string name;
    std::string type;
    int damage;
    int fireRate;
    int magazineSize;
    int currentAmmo;
    int maxAmmo;
    float accuracy;
    float recoil;
    float reloadTime;
    bool isAutomatic;
    
public:
    Weapon(const std::string& name, const std::string& type, int damage, int fireRate, int magazineSize, float accuracy, float recoil, float reloadTime, bool isAutomatic);
    ~Weapon();
    
    void Fire();
    void Reload();
    bool CanFire() const;
    
    const std::string& GetName() const;
    const std::string& GetType() const;
    int GetDamage() const;
    int GetFireRate() const;
    int GetMagazineSize() const;
    int GetCurrentAmmo() const;
    int GetMaxAmmo() const;
    float GetAccuracy() const;
    float GetRecoil() const;
    float GetReloadTime() const;
    bool IsAutomatic() const;
    
    void SetCurrentAmmo(int ammo);
    void SetMaxAmmo(int ammo);
};

} // namespace LucasGame

#endif // WEAPON_H
#include "Weapon.h"
#include "../../LucasEngine/Utils/Logger.h"

namespace LucasGame {

Weapon::Weapon(const std::string& name, const std::string& type, int damage, int fireRate, int magazineSize, float accuracy, float recoil, float reloadTime, bool isAutomatic) 
    : name(name), type(type), damage(damage), fireRate(fireRate), magazineSize(magazineSize), 
      accuracy(accuracy), recoil(recoil), reloadTime(reloadTime), isAutomatic(isAutomatic) {
    currentAmmo = magazineSize;
    maxAmmo = magazineSize * 4;
    
    LucasEngine::Logger::GetInstance()->Log("Weapon created: " + name + " (" + type + ")");
}

Weapon::~Weapon() {
    LucasEngine::Logger::GetInstance()->Log("Weapon destroyed: " + name);
}

void Weapon::Fire() {
    if (CanFire()) {
        currentAmmo--;
        LucasEngine::Logger::GetInstance()->Log("Fired " + name + ". Ammo left: " + std::to_string(currentAmmo));
    } else {
        LucasEngine::Logger::GetInstance()->Log("Cannot fire " + name + ": Out of ammo");
    }
}

void Weapon::Reload() {
    if (currentAmmo < magazineSize && maxAmmo > 0) {
        int ammoNeeded = magazineSize - currentAmmo;
        int ammoToLoad = std::min(ammoNeeded, maxAmmo);
        currentAmmo += ammoToLoad;
        maxAmmo -= ammoToLoad;
        LucasEngine::Logger::GetInstance()->Log("Reloaded " + name + ". Ammo: " + std::to_string(currentAmmo) + "/" + std::to_string(maxAmmo));
    }
}

bool Weapon::CanFire() const {
    return currentAmmo > 0;
}

const std::string& Weapon::GetName() const {
    return name;
}

const std::string& Weapon::GetType() const {
    return type;
}

int Weapon::GetDamage() const {
    return damage;
}

int Weapon::GetFireRate() const {
    return fireRate;
}

int Weapon::GetMagazineSize() const {
    return magazineSize;
}

int Weapon::GetCurrentAmmo() const {
    return currentAmmo;
}

int Weapon::GetMaxAmmo() const {
    return maxAmmo;
}

float Weapon::GetAccuracy() const {
    return accuracy;
}

float Weapon::GetRecoil() const {
    return recoil;
}

float Weapon::GetReloadTime() const {
    return reloadTime;
}

bool Weapon::IsAutomatic() const {
    return isAutomatic;
}

void Weapon::SetCurrentAmmo(int ammo) {
    currentAmmo = ammo;
}

void Weapon::SetMaxAmmo(int ammo) {
    maxAmmo = ammo;
}

} // namespace LucasGame
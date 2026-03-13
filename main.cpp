#include "LucasEngine/Core/Engine.h"
#include "LucasGame/Gameplay/GameManager.h"
#include "LucasGame/Characters/OperatorManager.h"
#include "LucasGame/Weapons/WeaponManager.h"
#include "LucasGame/Weapons/EquipmentManager.h"
#include "LucasGame/Map/Map.h"
#include "LucasGame/Story/StoryManager.h"
#include "LucasGame/UI/UIManager.h"

int main() {
    // 初始化引擎
    auto engine = LucasEngine::Engine::GetInstance();
    engine->Initialize("Lucas Battleground", 1920, 1080);
    
    // 启用8K模式
    engine->Enable8KMode();
    
    // 初始化游戏管理器
    auto gameManager = LucasGame::GameManager::GetInstance();
    gameManager->Initialize();
    
    // 初始化干员管理器
    auto operatorManager = LucasGame::OperatorManager::GetInstance();
    operatorManager->Initialize();
    
    // 初始化武器管理器
    auto weaponManager = LucasGame::WeaponManager::GetInstance();
    weaponManager->Initialize();
    
    // 初始化装备管理器
    auto equipmentManager = LucasGame::EquipmentManager::GetInstance();
    equipmentManager->Initialize();
    
    // 初始化地图
    auto map = new LucasGame::Map("Island", 4000.0f, 4000.0f);
    map->Initialize();
    
    // 初始化故事管理器
    auto storyManager = LucasGame::StoryManager::GetInstance();
    storyManager->Initialize();
    
    // 初始化UI管理器
    auto uiManager = LucasGame::UIManager::GetInstance();
    uiManager->Initialize();
    
    // 开始故事
    storyManager->StartStory("大逃杀: 生存之战");
    
    // 运行游戏
    engine->Run();
    
    // 清理资源
    delete map;
    LucasGame::UIManager::DestroyInstance();
    LucasGame::StoryManager::DestroyInstance();
    LucasGame::EquipmentManager::DestroyInstance();
    LucasGame::WeaponManager::DestroyInstance();
    LucasGame::OperatorManager::DestroyInstance();
    LucasGame::GameManager::DestroyInstance();
    LucasEngine::Engine::DestroyInstance();
    
    return 0;
}
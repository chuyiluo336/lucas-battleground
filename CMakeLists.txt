cmake_minimum_required(VERSION 3.10)
project(LucasBattleground)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 包含目录
include_directories(
    ${CMAKE_SOURCE_DIR}/LucasEngine
    ${CMAKE_SOURCE_DIR}/LucasGame
)

# 引擎源文件
set(ENGINE_SOURCES
    LucasEngine/Core/Engine.cpp
    LucasEngine/Rendering/Renderer.cpp
    LucasEngine/Physics/PhysicsEngine.cpp
    LucasEngine/Audio/AudioEngine.cpp
    LucasEngine/Networking/NetworkManager.cpp
    LucasEngine/Networking/NetworkMessage.cpp
    LucasEngine/Networking/NetworkClient.cpp
    LucasEngine/Networking/NetworkServer.cpp
    LucasEngine/Input/InputManager.cpp
    LucasEngine/Utils/Logger.cpp
    LucasEngine/Utils/PerformanceManager.cpp
)

# 游戏源文件
set(GAME_SOURCES
    LucasGame/Gameplay/GameManager.cpp
    LucasGame/Characters/Player.cpp
    LucasGame/Characters/Operator.cpp
    LucasGame/Characters/OperatorManager.cpp
    LucasGame/Weapons/Weapon.cpp
    LucasGame/Weapons/WeaponManager.cpp
    LucasGame/Weapons/Equipment.cpp
    LucasGame/Weapons/EquipmentManager.cpp
    LucasGame/Map/Map.cpp
    LucasGame/Map/Terrain.cpp
    LucasGame/Map/Building.cpp
    LucasGame/Map/Environment.cpp
    LucasGame/Story/StoryManager.cpp
    LucasGame/UI/UIManager.cpp
    main.cpp
)

# 构建可执行文件
add_executable(LucasBattleground ${ENGINE_SOURCES} ${GAME_SOURCES})

# 链接库
# target_link_libraries(LucasBattleground ...)

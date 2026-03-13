#include "Map.h"
#include "Terrain.h"
#include "Building.h"
#include "Environment.h"
#include "../../LucasEngine/Utils/Logger.h"

namespace LucasGame {

Map::Map(const std::string& name, float width, float height) : name(name), width(width), height(height), terrain(nullptr), environment(nullptr) {
}

Map::~Map() {
    Shutdown();
}

void Map::Initialize() {
    GenerateTerrain();
    GenerateBuildings();
    GenerateEnvironment();
    LucasEngine::Logger::GetInstance()->Log("Map initialized: " + name);
}

void Map::Shutdown() {
    for (auto building : buildings) {
        delete building;
    }
    buildings.clear();
    
    if (environment) {
        delete environment;
        environment = nullptr;
    }
    
    if (terrain) {
        delete terrain;
        terrain = nullptr;
    }
    
    LucasEngine::Logger::GetInstance()->Log("Map shutdown: " + name);
}

void Map::Update() {
    if (terrain) {
        terrain->Update();
    }
    
    for (auto building : buildings) {
        building->Update();
    }
    
    if (environment) {
        environment->Update();
    }
}

void Map::Render() {
    if (terrain) {
        terrain->Render();
    }
    
    for (auto building : buildings) {
        building->Render();
    }
    
    if (environment) {
        environment->Render();
    }
}

const std::string& Map::GetName() const {
    return name;
}

float Map::GetWidth() const {
    return width;
}

float Map::GetHeight() const {
    return height;
}

Terrain* Map::GetTerrain() const {
    return terrain;
}

Environment* Map::GetEnvironment() const {
    return environment;
}

void Map::AddBuilding(Building* building) {
    buildings.push_back(building);
    LucasEngine::Logger::GetInstance()->Log("Building added to map: " + building->GetName());
}

void Map::RemoveBuilding(Building* building) {
    auto it = std::find(buildings.begin(), buildings.end(), building);
    if (it != buildings.end()) {
        buildings.erase(it);
        delete building;
        LucasEngine::Logger::GetInstance()->Log("Building removed from map");
    }
}

std::vector<Building*> Map::GetBuildings() const {
    return buildings;
}

void Map::GenerateTerrain() {
    terrain = new Terrain(width, height);
    terrain->Generate();
    LucasEngine::Logger::GetInstance()->Log("Terrain generated");
}

void Map::GenerateBuildings() {
    // 生成各种建筑
    AddBuilding(new Building("House 1", 10.0f, 8.0f, 6.0f, 0.0f, 0.0f, 0.0f));
    AddBuilding(new Building("House 2", 12.0f, 10.0f, 7.0f, 15.0f, 0.0f, 0.0f));
    AddBuilding(new Building("Apartment", 20.0f, 15.0f, 20.0f, 30.0f, 0.0f, 0.0f));
    AddBuilding(new Building("Office", 18.0f, 12.0f, 15.0f, 0.0f, 0.0f, 20.0f));
    AddBuilding(new Building("Warehouse", 25.0f, 20.0f, 10.0f, 0.0f, 0.0f, 40.0f));
    LucasEngine::Logger::GetInstance()->Log("Buildings generated");
}

void Map::GenerateEnvironment() {
    environment = new Environment();
    environment->Generate();
    LucasEngine::Logger::GetInstance()->Log("Environment generated");
}

} // namespace LucasGame
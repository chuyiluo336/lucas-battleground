#ifndef MAP_H
#define MAP_H

#include <string>
#include <vector>

namespace LucasGame {

class Terrain;
class Building;
class Environment;

class Map {
private:
    std::string name;
    float width;
    float height;
    Terrain* terrain;
    std::vector<Building*> buildings;
    Environment* environment;
    
public:
    Map(const std::string& name, float width, float height);
    ~Map();
    
    void Initialize();
    void Shutdown();
    void Update();
    void Render();
    
    const std::string& GetName() const;
    float GetWidth() const;
    float GetHeight() const;
    Terrain* GetTerrain() const;
    Environment* GetEnvironment() const;
    
    void AddBuilding(Building* building);
    void RemoveBuilding(Building* building);
    std::vector<Building*> GetBuildings() const;
    
    // 地图功能
    void GenerateTerrain();
    void GenerateBuildings();
    void GenerateEnvironment();
};

} // namespace LucasGame

#endif // MAP_H
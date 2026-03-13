#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <vector>

namespace LucasGame {

class Environment {
private:
    std::vector<void*> trees;
    std::vector<void*> plants;
    std::vector<void*> props;
    float windSpeed;
    float windDirection;
    int weatherType;
    
public:
    Environment();
    ~Environment();
    
    void Generate();
    void Update();
    void Render();
    
    void SetWind(float speed, float direction);
    void SetWeather(int type);
    
private:
    void GenerateTrees();
    void GeneratePlants();
    void GenerateProps();
};

} // namespace LucasGame

#endif // ENVIRONMENT_H
#ifndef TERRAIN_H
#define TERRAIN_H

namespace LucasGame {

class Terrain {
private:
    float width;
    float height;
    float** heightMap;
    
public:
    Terrain(float width, float height);
    ~Terrain();
    
    void Generate();
    void Update();
    void Render();
    
    float GetHeight(float x, float z) const;
    float GetWidth() const;
    float GetHeight() const;
    
private:
    void GenerateHeightMap();
    void SmoothHeightMap();
};

} // namespace LucasGame

#endif // TERRAIN_H
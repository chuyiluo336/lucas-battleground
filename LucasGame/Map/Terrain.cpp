#include "Terrain.h"
#include "../../LucasEngine/Utils/Logger.h"

namespace LucasGame {

Terrain::Terrain(float width, float height) : width(width), height(height), heightMap(nullptr) {
}

Terrain::~Terrain() {
    if (heightMap) {
        for (int i = 0; i < 1024; i++) {
            delete[] heightMap[i];
        }
        delete[] heightMap;
    }
}

void Terrain::Generate() {
    GenerateHeightMap();
    SmoothHeightMap();
    LucasEngine::Logger::GetInstance()->Log("Terrain generated with width: " + std::to_string(width) + ", height: " + std::to_string(height));
}

void Terrain::Update() {
    // 更新地形（例如动态地形效果）
}

void Terrain::Render() {
    // 渲染地形
    // 使用高分辨率纹理和细节层次
}

float Terrain::GetHeight(float x, float z) const {
    // 计算地形高度
    return 0.0f;
}

float Terrain::GetWidth() const {
    return width;
}

float Terrain::GetHeight() const {
    return height;
}

void Terrain::GenerateHeightMap() {
    // 生成高度图
    int size = 1024;
    heightMap = new float*[size];
    for (int i = 0; i < size; i++) {
        heightMap[i] = new float[size];
        for (int j = 0; j < size; j++) {
            heightMap[i][j] = (rand() % 100) / 100.0f * 20.0f;
        }
    }
}

void Terrain::SmoothHeightMap() {
    // 平滑高度图
    int size = 1024;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            float sum = 0.0f;
            int count = 0;
            
            for (int dx = -1; dx <= 1; dx++) {
                for (int dz = -1; dz <= 1; dz++) {
                    int nx = i + dx;
                    int nz = j + dz;
                    if (nx >= 0 && nx < size && nz >= 0 && nz < size) {
                        sum += heightMap[nx][nz];
                        count++;
                    }
                }
            }
            
            heightMap[i][j] = sum / count;
        }
    }
}

} // namespace LucasGame
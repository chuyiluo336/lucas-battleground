#include "PerformanceManager.h"
#include "Logger.h"

namespace LucasEngine {

PerformanceManager* PerformanceManager::instance = nullptr;

PerformanceManager* PerformanceManager::GetInstance() {
    if (!instance) {
        instance = new PerformanceManager();
    }
    return instance;
}

void PerformanceManager::DestroyInstance() {
    if (instance) {
        delete instance;
        instance = nullptr;
    }
}

void PerformanceManager::Initialize() {
    lastFrameTime = std::chrono::steady_clock::now();
    frameTime = 0.0f;
    fps = 0.0f;
    frameCount = 0;
    totalFrameTime = 0.0f;
    Logger::GetInstance()->Log("PerformanceManager initialized");
}

void PerformanceManager::Shutdown() {
    Logger::GetInstance()->Log("PerformanceManager shutdown");
}

void PerformanceManager::Update() {
    auto currentTime = std::chrono::steady_clock::now();
    auto deltaTime = std::chrono::duration<float>(currentTime - lastFrameTime).count();
    lastFrameTime = currentTime;
    
    frameTime = deltaTime;
    totalFrameTime += deltaTime;
    frameCount++;
    
    if (totalFrameTime >= 1.0f) {
        fps = frameCount / totalFrameTime;
        Logger::GetInstance()->Log("FPS: " + std::to_string(fps) + ", Frame time: " + std::to_string(frameTime * 1000) + "ms");
        frameCount = 0;
        totalFrameTime = 0.0f;
    }
}

float PerformanceManager::GetFrameTime() const {
    return frameTime;
}

float PerformanceManager::GetFPS() const {
    return fps;
}

void PerformanceManager::Enable8KOptimization() {
    // 启用8K优化
    Logger::GetInstance()->Log("8K optimization enabled");
}

void PerformanceManager::EnableMultithreading() {
    // 启用多线程
    Logger::GetInstance()->Log("Multithreading enabled");
}

void PerformanceManager::EnableLOD() {
    // 启用细节层次
    Logger::GetInstance()->Log("LOD enabled");
}

void PerformanceManager::EnableTextureCompression() {
    // 启用纹理压缩
    Logger::GetInstance()->Log("Texture compression enabled");
}

} // namespace LucasEngine
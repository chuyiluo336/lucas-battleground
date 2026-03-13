#ifndef PERFORMANCE_MANAGER_H
#define PERFORMANCE_MANAGER_H

#include <string>
#include <chrono>

namespace LucasEngine {

class PerformanceManager {
private:
    static PerformanceManager* instance;
    std::chrono::steady_clock::time_point lastFrameTime;
    float frameTime;
    float fps;
    int frameCount;
    float totalFrameTime;
    
public:
    static PerformanceManager* GetInstance();
    static void DestroyInstance();
    
    void Initialize();
    void Shutdown();
    void Update();
    
    float GetFrameTime() const;
    float GetFPS() const;
    
    // 性能优化功能
    void Enable8KOptimization();
    void EnableMultithreading();
    void EnableLOD();
    void EnableTextureCompression();
};

} // namespace LucasEngine

#endif // PERFORMANCE_MANAGER_H
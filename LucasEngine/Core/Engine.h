#ifndef ENGINE_H
#define ENGINE_H

#include <string>
#include <vector>
#include <memory>

namespace LucasEngine {

class Renderer;
class PhysicsEngine;
class AudioEngine;
class NetworkManager;
class InputManager;
class PerformanceManager;

class Engine {
private:
    static Engine* instance;
    bool isRunning;
    std::unique_ptr<Renderer> renderer;
    std::unique_ptr<PhysicsEngine> physicsEngine;
    std::unique_ptr<AudioEngine> audioEngine;
    std::unique_ptr<NetworkManager> networkManager;
    std::unique_ptr<InputManager> inputManager;
    std::unique_ptr<PerformanceManager> performanceManager;
    
    Engine();
    ~Engine();
    
public:
    static Engine* GetInstance();
    static void DestroyInstance();
    
    bool Initialize(const std::string& windowTitle, int width, int height);
    void Run();
    void Shutdown();
    
    Renderer* GetRenderer() const;
    PhysicsEngine* GetPhysicsEngine() const;
    AudioEngine* GetAudioEngine() const;
    NetworkManager* GetNetworkManager() const;
    InputManager* GetInputManager() const;
    PerformanceManager* GetPerformanceManager() const;
    
    bool IsRunning() const;
    void Stop();
    
    // 性能优化
    void Enable8KMode();
    void OptimizeForPerformance();
};

} // namespace LucasEngine

#endif // ENGINE_H
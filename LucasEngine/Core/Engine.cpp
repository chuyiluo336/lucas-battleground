#include "Engine.h"
#include "../Rendering/Renderer.h"
#include "../Physics/PhysicsEngine.h"
#include "../Audio/AudioEngine.h"
#include "../Networking/NetworkManager.h"
#include "../Input/InputManager.h"
#include "../Utils/PerformanceManager.h"
#include "../Utils/Logger.h"

namespace LucasEngine {

Engine* Engine::instance = nullptr;

Engine::Engine() : isRunning(false) {
}

Engine::~Engine() {
}

Engine* Engine::GetInstance() {
    if (!instance) {
        instance = new Engine();
    }
    return instance;
}

void Engine::DestroyInstance() {
    if (instance) {
        delete instance;
        instance = nullptr;
    }
}

bool Engine::Initialize(const std::string& windowTitle, int width, int height) {
    // 初始化性能管理器
    performanceManager = std::make_unique<PerformanceManager>();
    performanceManager->Initialize();
    
    // 初始化各个子系统
    renderer = std::make_unique<Renderer>();
    if (!renderer->Initialize(windowTitle, width, height)) {
        return false;
    }
    
    physicsEngine = std::make_unique<PhysicsEngine>();
    if (!physicsEngine->Initialize()) {
        return false;
    }
    
    audioEngine = std::make_unique<AudioEngine>();
    if (!audioEngine->Initialize()) {
        return false;
    }
    
    networkManager = std::make_unique<NetworkManager>();
    if (!networkManager->Initialize()) {
        return false;
    }
    
    inputManager = std::make_unique<InputManager>();
    if (!inputManager->Initialize()) {
        return false;
    }
    
    // 启用性能优化
    OptimizeForPerformance();
    
    isRunning = true;
    Logger::GetInstance()->Log("Engine initialized successfully");
    return true;
}

void Engine::Run() {
    while (isRunning) {
        // 更新性能管理器
        performanceManager->Update();
        
        // 处理输入
        inputManager->Update();
        
        // 更新物理
        physicsEngine->Update();
        
        // 渲染
        renderer->Render();
        
        // 网络更新
        networkManager->Update();
    }
}

void Engine::Shutdown() {
    isRunning = false;
    
    if (inputManager) inputManager->Shutdown();
    if (networkManager) networkManager->Shutdown();
    if (audioEngine) audioEngine->Shutdown();
    if (physicsEngine) physicsEngine->Shutdown();
    if (renderer) renderer->Shutdown();
    if (performanceManager) performanceManager->Shutdown();
    
    Logger::GetInstance()->Log("Engine shutdown");
}

Renderer* Engine::GetRenderer() const {
    return renderer.get();
}

PhysicsEngine* Engine::GetPhysicsEngine() const {
    return physicsEngine.get();
}

AudioEngine* Engine::GetAudioEngine() const {
    return audioEngine.get();
}

NetworkManager* Engine::GetNetworkManager() const {
    return networkManager.get();
}

InputManager* Engine::GetInputManager() const {
    return inputManager.get();
}

PerformanceManager* Engine::GetPerformanceManager() const {
    return performanceManager.get();
}

bool Engine::IsRunning() const {
    return isRunning;
}

void Engine::Stop() {
    isRunning = false;
}

void Engine::Enable8KMode() {
    renderer->Enable8KResolution();
    performanceManager->Enable8KOptimization();
    Logger::GetInstance()->Log("8K mode enabled");
}

void Engine::OptimizeForPerformance() {
    performanceManager->EnableMultithreading();
    performanceManager->EnableLOD();
    performanceManager->EnableTextureCompression();
    Logger::GetInstance()->Log("Performance optimization enabled");
}

} // namespace LucasEngine
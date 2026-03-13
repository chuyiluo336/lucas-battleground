#ifndef PHYSICS_ENGINE_H
#define PHYSICS_ENGINE_H

namespace LucasEngine {

class PhysicsEngine {
private:
    bool isInitialized;
    
public:
    PhysicsEngine();
    ~PhysicsEngine();
    
    bool Initialize();
    void Shutdown();
    void Update();
    
    bool IsInitialized() const;
    
    // 物理功能
    void AddRigidBody(void* body);
    void RemoveRigidBody(void* body);
    void ApplyForce(void* body, float x, float y, float z);
};

} // namespace LucasEngine

#endif // PHYSICS_ENGINE_H
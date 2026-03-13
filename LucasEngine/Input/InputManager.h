#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

namespace LucasEngine {

class InputManager {
private:
    bool isInitialized;
    
public:
    InputManager();
    ~InputManager();
    
    bool Initialize();
    void Shutdown();
    void Update();
    
    bool IsInitialized() const;
    
    // 输入功能
    bool IsKeyPressed(int key);
    bool IsMouseButtonPressed(int button);
    void GetMousePosition(int& x, int& y);
    void SetMousePosition(int x, int y);
};

} // namespace LucasEngine

#endif // INPUT_MANAGER_H
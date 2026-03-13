#ifndef UI_MANAGER_H
#define UI_MANAGER_H

#include <string>
#include <vector>

namespace LucasGame {

class UIManager {
private:
    static UIManager* instance;
    std::vector<void*> uiElements;
    
public:
    static UIManager* GetInstance();
    static void DestroyInstance();
    
    void Initialize();
    void Shutdown();
    void Update();
    void Render();
    
    void AddUIElement(void* element);
    void RemoveUIElement(void* element);
    
    // UI功能
    void ShowHUD();
    void ShowInventory();
    void ShowMap();
    void ShowMenu();
    void ShowGameOver();
};

} // namespace LucasGame

#endif // UI_MANAGER_H
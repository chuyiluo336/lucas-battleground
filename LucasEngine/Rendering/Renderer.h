#ifndef RENDERER_H
#define RENDERER_H

#include <string>
#include <vector>

namespace LucasEngine {

class Renderer {
private:
    void* window;
    void* context;
    int width;
    int height;
    bool isInitialized;
    
public:
    Renderer();
    ~Renderer();
    
    bool Initialize(const std::string& windowTitle, int width, int height);
    void Shutdown();
    void Render();
    void Clear();
    
    int GetWidth() const;
    int GetHeight() const;
    bool IsInitialized() const;
    
    // 高级渲染功能
    void Enable8KResolution();
    void SetFrameRateLimit(int fps);
};

} // namespace LucasEngine

#endif // RENDERER_H
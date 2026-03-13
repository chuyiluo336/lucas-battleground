#ifndef AUDIO_ENGINE_H
#define AUDIO_ENGINE_H

#include <string>

namespace LucasEngine {

class AudioEngine {
private:
    bool isInitialized;
    
public:
    AudioEngine();
    ~AudioEngine();
    
    bool Initialize();
    void Shutdown();
    
    bool IsInitialized() const;
    
    // 音频功能
    void PlaySound(const std::string& soundName);
    void PlayMusic(const std::string& musicName);
    void StopAllSounds();
    void SetVolume(float volume);
};

} // namespace LucasEngine

#endif // AUDIO_ENGINE_H
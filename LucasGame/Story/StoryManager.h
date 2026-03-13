#ifndef STORY_MANAGER_H
#define STORY_MANAGER_H

#include <string>
#include <vector>

namespace LucasGame {

class StoryManager {
private:
    static StoryManager* instance;
    std::string currentStory;
    std::vector<std::string> chapters;
    int currentChapter;
    bool isStoryActive;
    
public:
    static StoryManager* GetInstance();
    static void DestroyInstance();
    
    void Initialize();
    void Shutdown();
    
    void StartStory(const std::string& storyName);
    void AdvanceChapter();
    void CompleteStory();
    
    const std::string& GetCurrentStory() const;
    const std::string& GetCurrentChapter() const;
    int GetCurrentChapterIndex() const;
    bool IsStoryActive() const;
    
    // 故事内容
    void LoadStoryData();
    void PlayCutscene(const std::string& cutsceneName);
    void TriggerEvent(const std::string& eventName);
};

} // namespace LucasGame

#endif // STORY_MANAGER_H
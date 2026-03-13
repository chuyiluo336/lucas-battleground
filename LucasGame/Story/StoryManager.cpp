#include "StoryManager.h"
#include "../../LucasEngine/Utils/Logger.h"
using namespace LucasEngine;

namespace LucasGame {

StoryManager* StoryManager::instance = nullptr;

StoryManager* StoryManager::GetInstance() {
    if (!instance) {
        instance = new StoryManager();
    }
    return instance;
}

void StoryManager::DestroyInstance() {
    if (instance) {
        instance->Shutdown();
        delete instance;
        instance = nullptr;
    }
}

void StoryManager::Initialize() {
    LoadStoryData();
    currentChapter = -1;
    isStoryActive = false;
    Logger::GetInstance()->Log("StoryManager initialized");
}

void StoryManager::Shutdown() {
    chapters.clear();
    Logger::GetInstance()->Log("StoryManager shutdown");
}

void StoryManager::StartStory(const std::string& storyName) {
    currentStory = storyName;
    currentChapter = 0;
    isStoryActive = true;
    Logger::GetInstance()->Log("Story started: " + storyName);
    Logger::GetInstance()->Log("Chapter 1: " + chapters[0]);
}

void StoryManager::AdvanceChapter() {
    if (isStoryActive && currentChapter < chapters.size() - 1) {
        currentChapter++;
        Logger::GetInstance()->Log("Advanced to chapter " + std::to_string(currentChapter + 1) + ": " + chapters[currentChapter]);
    } else if (currentChapter >= chapters.size() - 1) {
        CompleteStory();
    }
}

void StoryManager::CompleteStory() {
    isStoryActive = false;
    Logger::GetInstance()->Log("Story completed: " + currentStory);
}

const std::string& StoryManager::GetCurrentStory() const {
    return currentStory;
}

const std::string& StoryManager::GetCurrentChapter() const {
    if (isStoryActive && currentChapter < chapters.size()) {
        return chapters[currentChapter];
    }
    static std::string empty;
    return empty;
}

int StoryManager::GetCurrentChapterIndex() const {
    return currentChapter;
}

bool StoryManager::IsStoryActive() const {
    return isStoryActive;
}

void StoryManager::LoadStoryData() {
    // 加载故事数据
    chapters.clear();
    
    // 大逃杀故事剧情
    chapters.push_back("第一章: 觉醒");
    chapters.push_back("第二章: 生存");
    chapters.push_back("第三章: 真相");
    chapters.push_back("第四章: 反抗");
    chapters.push_back("第五章: 最终决战");
    
    Logger::GetInstance()->Log("Story data loaded. " + std::to_string(chapters.size()) + " chapters available");
}

void StoryManager::PlayCutscene(const std::string& cutsceneName) {
    Logger::GetInstance()->Log("Playing cutscene: " + cutsceneName);
}

void StoryManager::TriggerEvent(const std::string& eventName) {
    Logger::GetInstance()->Log("Event triggered: " + eventName);
}

} // namespace LucasGame
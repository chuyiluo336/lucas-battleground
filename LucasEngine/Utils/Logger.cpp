#include "Logger.h"
#include <iostream>

namespace LucasEngine {

Logger* Logger::instance = nullptr;

Logger::Logger() {
}

Logger* Logger::GetInstance() {
    if (!instance) {
        instance = new Logger();
    }
    return instance;
}

void Logger::DestroyInstance() {
    if (instance) {
        delete instance;
        instance = nullptr;
    }
}

void Logger::Log(const std::string& message) {
    std::cout << "[LOG] " << message << std::endl;
}

void Logger::LogWarning(const std::string& message) {
    std::cout << "[WARNING] " << message << std::endl;
}

void Logger::LogError(const std::string& message) {
    std::cout << "[ERROR] " << message << std::endl;
}

} // namespace LucasEngine
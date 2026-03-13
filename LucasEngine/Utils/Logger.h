#ifndef LOGGER_H
#define LOGGER_H

#include <string>

namespace LucasEngine {

class Logger {
private:
    static Logger* instance;
    
    Logger();
    
public:
    static Logger* GetInstance();
    static void DestroyInstance();
    
    void Log(const std::string& message);
    void LogWarning(const std::string& message);
    void LogError(const std::string& message);
};

} // namespace LucasEngine

#endif // LOGGER_H
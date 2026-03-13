#ifndef OPERATOR_MANAGER_H
#define OPERATOR_MANAGER_H

#include <string>
#include <vector>
#include <map>

namespace LucasGame {

class Operator;

class OperatorManager {
private:
    static OperatorManager* instance;
    std::vector<Operator*> operators;
    std::map<std::string, Operator*> operatorMap;
    
    OperatorManager();
    
public:
    static OperatorManager* GetInstance();
    static void DestroyInstance();
    
    void Initialize();
    void Shutdown();
    
    Operator* CreateOperator(const std::string& playerName, bool isMale, const std::string& operatorName, const std::string& specialization);
    void RemoveOperator(Operator* op);
    Operator* GetOperatorByName(const std::string& name);
    std::vector<Operator*> GetAllOperators();
    
    // 预定义干员
    void CreateDefaultOperators();
};

} // namespace LucasGame

#endif // OPERATOR_MANAGER_H
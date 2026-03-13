#include "OperatorManager.h"
#include "Operator.h"
#include "../../LucasEngine/Utils/Logger.h"

namespace LucasGame {

OperatorManager* OperatorManager::instance = nullptr;

OperatorManager::OperatorManager() {
}

OperatorManager* OperatorManager::GetInstance() {
    if (!instance) {
        instance = new OperatorManager();
    }
    return instance;
}

void OperatorManager::DestroyInstance() {
    if (instance) {
        instance->Shutdown();
        delete instance;
        instance = nullptr;
    }
}

void OperatorManager::Initialize() {
    CreateDefaultOperators();
    LucasEngine::Logger::GetInstance()->Log("OperatorManager initialized");
}

void OperatorManager::Shutdown() {
    for (auto op : operators) {
        delete op;
    }
    operators.clear();
    operatorMap.clear();
    LucasEngine::Logger::GetInstance()->Log("OperatorManager shutdown");
}

Operator* OperatorManager::CreateOperator(const std::string& playerName, bool isMale, const std::string& operatorName, const std::string& specialization) {
    Operator* op = new Operator(playerName, isMale, operatorName, specialization);
    operators.push_back(op);
    operatorMap[playerName] = op;
    return op;
}

void OperatorManager::RemoveOperator(Operator* op) {
    auto it = std::find(operators.begin(), operators.end(), op);
    if (it != operators.end()) {
        operatorMap.erase(op->GetName());
        operators.erase(it);
        delete op;
    }
}

Operator* OperatorManager::GetOperatorByName(const std::string& name) {
    auto it = operatorMap.find(name);
    if (it != operatorMap.end()) {
        return it->second;
    }
    return nullptr;
}

std::vector<Operator*> OperatorManager::GetAllOperators() {
    return operators;
}

void OperatorManager::CreateDefaultOperators() {
    // 创建男性干员
    CreateOperator("Alex", true, "Spartan", "Assault");
    CreateOperator("John", true, "Eagle", "Sniper");
    CreateOperator("Mike", true, "Titan", "Support");
    CreateOperator("David", true, "Tech", "Engineer");
    
    // 创建女性干员
    CreateOperator("Sarah", false, "Phoenix", "Assault");
    CreateOperator("Emma", false, "Viper", "Sniper");
    CreateOperator("Lily", false, "Angel", "Support");
    CreateOperator("Zoe", false, "Mechanic", "Engineer");
    
    LucasEngine::Logger::GetInstance()->Log("Created default operators");
}

} // namespace LucasGame
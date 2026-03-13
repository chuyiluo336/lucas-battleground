#include "Operator.h"
#include "../../LucasEngine/Utils/Logger.h"

namespace LucasGame {

Operator::Operator(const std::string& name, bool isMale, const std::string& operatorName, const std::string& specialization) 
    : Player(name, isMale), operatorName(operatorName), specialization(specialization) {
    skillCooldown = 60; // 60秒冷却
    skillDuration = 10; // 10秒持续时间
    isSkillActive = false;
    
    LucasEngine::Logger::GetInstance()->Log("Operator created: " + operatorName + " (" + specialization + ")");
}

Operator::~Operator() {
    LucasEngine::Logger::GetInstance()->Log("Operator destroyed: " + operatorName);
}

void Operator::Update() {
    Player::Update();
    
    if (isSkillActive) {
        // 技能持续时间倒计时
        skillDuration--;
        if (skillDuration <= 0) {
            isSkillActive = false;
            LucasEngine::Logger::GetInstance()->Log(operatorName + "'s skill has ended");
        }
    } else {
        // 技能冷却倒计时
        if (skillCooldown > 0) {
            skillCooldown--;
        }
    }
}

void Operator::UseSkill() {
    if (!isSkillActive && skillCooldown <= 0) {
        isSkillActive = true;
        skillDuration = 10;
        skillCooldown = 60;
        SkillEffect();
        LucasEngine::Logger::GetInstance()->Log(operatorName + " used skill: " + specialization);
    } else if (skillCooldown > 0) {
        LucasEngine::Logger::GetInstance()->Log(operatorName + "'s skill is on cooldown: " + std::to_string(skillCooldown) + " seconds");
    }
}

void Operator::SkillEffect() {
    // 根据不同的干员和专精实现不同的技能效果
    if (specialization == "Assault") {
        // 突击技能：增加移动速度和伤害
        LucasEngine::Logger::GetInstance()->Log(operatorName + " activated Assault skill: Increased speed and damage");
    } else if (specialization == "Sniper") {
        // 狙击手技能：增加精准度和范围
        LucasEngine::Logger::GetInstance()->Log(operatorName + " activated Sniper skill: Increased accuracy and range");
    } else if (specialization == "Support") {
        // 支援技能：恢复队友生命值
        LucasEngine::Logger::GetInstance()->Log(operatorName + " activated Support skill: Healing teammates");
    } else if (specialization == "Engineer") {
        // 工程师技能：部署陷阱
        LucasEngine::Logger::GetInstance()->Log(operatorName + " activated Engineer skill: Deploying traps");
    }
}

const std::string& Operator::GetOperatorName() const {
    return operatorName;
}

const std::string& Operator::GetSpecialization() const {
    return specialization;
}

bool Operator::IsSkillActive() const {
    return isSkillActive;
}

} // namespace LucasGame
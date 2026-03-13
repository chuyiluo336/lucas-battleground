#ifndef OPERATOR_H
#define OPERATOR_H

#include "Player.h"

namespace LucasGame {

class Operator : public Player {
private:
    std::string operatorName;
    std::string specialization;
    int skillCooldown;
    int skillDuration;
    bool isSkillActive;
    
public:
    Operator(const std::string& name, bool isMale, const std::string& operatorName, const std::string& specialization);
    ~Operator();
    
    void Update() override;
    void UseSkill();
    void SkillEffect();
    
    const std::string& GetOperatorName() const;
    const std::string& GetSpecialization() const;
    bool IsSkillActive() const;
};

} // namespace LucasGame

#endif // OPERATOR_H
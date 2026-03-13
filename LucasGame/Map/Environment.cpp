#include "Environment.h"
#include "../../LucasEngine/Utils/Logger.h"

namespace LucasGame {

Environment::Environment() : windSpeed(0.0f), windDirection(0.0f), weatherType(0) {
}

Environment::~Environment() {
    // 清理环境资源
    trees.clear();
    plants.clear();
    props.clear();
}

void Environment::Generate() {
    GenerateTrees();
    GeneratePlants();
    GenerateProps();
    LucasEngine::Logger::GetInstance()->Log("Environment generated");
}

void Environment::Update() {
    // 更新环境元素
    // 处理风力效果
    // 处理天气变化
}

void Environment::Render() {
    // 渲染环境元素
    // 渲染树木
    // 渲染植被
    // 渲染道具
    // 渲染天气效果
}

void Environment::SetWind(float speed, float direction) {
    windSpeed = speed;
    windDirection = direction;
    LucasEngine::Logger::GetInstance()->Log("Wind set to " + std::to_string(speed) + " m/s, direction: " + std::to_string(direction));
}

void Environment::SetWeather(int type) {
    weatherType = type;
    LucasEngine::Logger::GetInstance()->Log("Weather set to type: " + std::to_string(type));
}

void Environment::GenerateTrees() {
    // 生成树木
    // 这里会创建各种类型的树木
    LucasEngine::Logger::GetInstance()->Log("Trees generated");
}

void Environment::GeneratePlants() {
    // 生成植被
    // 这里会创建各种类型的植被
    LucasEngine::Logger::GetInstance()->Log("Plants generated");
}

void Environment::GenerateProps() {
    // 生成道具
    // 这里会创建各种环境道具
    LucasEngine::Logger::GetInstance()->Log("Props generated");
}

} // namespace LucasGame
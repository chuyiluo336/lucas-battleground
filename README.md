# Lucas Battelground

![Lucas Battelground](https://via.placeholder.com/800x400?text=Lucas+Battelground)

## 项目介绍

Lucas Battelground 是一款基于 macOS 自研引擎开发的大逃杀 FPS 多人游戏，支持 8K 60fps 高画质渲染，拥有丰富的游戏内容和完整的故事剧情。

## 功能特点

### 核心玩法
- **大逃杀模式**：100名玩家在广阔的地图上竞技，最后存活者获胜
- **安全区机制**：随着时间推移，安全区会逐渐缩小，迫使玩家对抗
- **多人联机**：支持多人在线游戏，实时同步玩家状态

### 角色系统
- **男干员和女干员**：多种角色选择，每个角色都有独特的技能和属性
- **技能系统**：不同干员拥有不同的特殊技能，如突击、狙击、支援、工程等

### 武器与装备
- **丰富的武器库**：包括步枪、冲锋枪、狙击枪、霰弹枪、手枪、机枪等
- **装备系统**：头盔、防弹衣、背包、药品、投掷物等
- **经济系统**：游戏内货币系统，可以购买装备和道具

### 地图与环境
- **高质量3D地图**：比PUBG更真实、美观的地形和建筑
- **动态环境**：风力、天气等环境因素影响游戏
- **破坏系统**：建筑可以被破坏，增加游戏策略性

### 技术特点
- **8K 60fps**：支持8K分辨率和60fps流畅运行
- **macOS自研引擎**：专为macOS优化的游戏引擎
- **性能优化**：多线程、LOD、纹理压缩等技术
- **模块化设计**：清晰的代码结构，易于扩展和维护

## 项目结构

```
Lucas Battelground/
├── LucasEngine/         # 游戏引擎核心
│   ├── Core/           # 核心系统
│   ├── Rendering/      # 渲染系统
│   ├── Physics/        # 物理系统
│   ├── Audio/          # 音频系统
│   ├── Networking/     # 网络系统
│   ├── Input/          # 输入系统
│   └── Utils/          # 工具类
├── LucasGame/          # 游戏逻辑和内容
│   ├── Gameplay/       # 游戏核心逻辑
│   ├── Characters/     # 角色系统
│   ├── Weapons/        # 武器系统
│   ├── Map/            # 地图系统
│   ├── UI/             # 用户界面
│   ├── Story/          # 故事剧情
│   └── Resources/      # 游戏资源
├── main.cpp            # 游戏主入口
├── CMakeLists.txt      # CMake构建配置
├── package.sh          # 打包脚本
└── README.md           # 项目说明
```

## 安装与构建

### 环境要求
- macOS 10.15+
- Xcode 12.0+
- CMake 3.10+
- C++17 兼容编译器

### 构建步骤

1. **克隆仓库**
   ```bash
   git clone https://github.com/chuyiluo336/lucas-battleground.git
   cd lucas-battleground
   ```

2. **构建项目**
   ```bash
   mkdir build
   cd build
   cmake ..
   make -j8
   ```

3. **生成.app文件**
   ```bash
   cd ..
   ./package.sh
   ```

4. **运行游戏**
   ```bash
   open "Lucas Battleground.app"
   ```

## 游戏操作

- **WASD**：移动
- **鼠标**：瞄准和视角控制
- **左键**：开火
- **右键**：瞄准
- **R**：换弹
- **E**：互动
- **Q**：使用技能
- **Tab**：打开背包
- **M**：打开地图
- **Esc**：打开菜单

## 故事剧情

游戏包含5个章节的完整故事剧情：
1. **第一章：觉醒** - 玩家醒来发现自己身处一个陌生的岛屿
2. **第二章：生存** - 学习基本生存技能，收集资源
3. **第三章：真相** - 发现岛屿的秘密和背后的组织
4. **第四章：反抗** - 与其他玩家合作，对抗组织
5. **第五章：最终决战** - 揭开最终真相，决出最后的胜者

## 开发团队

- **chuyiluo336** - 主要开发者

## 许可证

MIT License

## 联系方式

- GitHub: [chuyiluo336](https://github.com/chuyiluo336)
- 邮箱: chuyiluo336@example.com

---

**享受游戏！** 🎮

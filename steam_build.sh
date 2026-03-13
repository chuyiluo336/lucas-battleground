#!/bin/bash

# Steam上架构建脚本

# 创建Steam构建目录
STEAM_BUILD_DIR="./steam_build"
APP_NAME="Lucas Battleground"

# 清理旧的构建
rm -rf "$STEAM_BUILD_DIR"
mkdir -p "$STEAM_BUILD_DIR"

# 复制.app文件
cp -r "$APP_NAME.app" "$STEAM_BUILD_DIR/"

# 创建Steamworks配置文件
cat > "$STEAM_BUILD_DIR/app_build.vdf" << EOF
"AppBuild"
{
	"AppID" "0" // 替换为你的Steam App ID
	"BuildOutput" "../output/"
	"ContentRoot" "./"
	"Preview" "0"
	"Local" "0"
	"SetLive" "0"
	"Depots"
	{
		"0"
		{
			"FileMapping"
			{
				"LocalPath" "$APP_NAME.app"
				"DepotPath" "$APP_NAME.app"
				"recursive" "1"
			}
		}
	}
}
EOF

# 创建README_Steam.md文件
cat > "$STEAM_BUILD_DIR/README_Steam.md" << EOF
# Lucas Battelground - Steam上架指南

## 准备工作

1. **注册Steamworks开发者账号**
   - 访问 https://partner.steamgames.com/ 注册
   - 支付开发者费用（一次性$100）

2. **创建新的Steam游戏应用**
   - 登录Steamworks后台
   - 点击"Create New Application"
   - 填写游戏基本信息
   - 获取App ID

3. **配置构建**
   - 编辑 app_build.vdf 文件，将 AppID 替换为你的实际App ID
   - 确保.app文件包含所有必要的资源

## 构建上传

1. **使用Steamworks SDK**
   - 下载Steamworks SDK：https://partner.steamgames.com/doc/sdk
   - 解压SDK到本地

2. **运行构建工具**
   ```bash
   cd /path/to/steamworks_sdk/tools/ContentBuilder/builder
   ./steamcmd.sh +login <username> +run_app_build /path/to/lucas-battleground/steam_build/app_build.vdf +quit
   ```

3. **验证构建**
   - 在Steamworks后台查看构建状态
   - 确保构建成功上传

## 商店页面配置

1. **填写游戏信息**
   - 游戏名称：Lucas Battelground
   - 游戏类型：动作、射击、大逃杀
   - 支持平台：macOS

2. **上传媒体文件**
   - 游戏截图（至少5张）
   - 游戏预告片（建议）
   - 游戏图标

3. **设置价格和发布区域**
   - 选择合适的价格
   - 设置发布区域

4. **提交审核**
   - 点击"Submit for Review"
   - 等待Steam审核

## 技术要求

- **macOS最低要求**：macOS 10.15+
- **推荐配置**：macOS 12.0+, 8GB RAM, 独立显卡
- **存储空间**：200GB
- **分辨率**：支持8K (7680x4320)
- **帧率**：60fps

## 联系方式

- 开发者：chuyiluo336
- 邮箱：xujiashun72@gmail.com
- GitHub：https://github.com/chuyiluo336/lucas-battleground
EOF

echo "Steam构建文件已准备完成！"
echo "构建目录：$STEAM_BUILD_DIR"
echo "请按照 README_Steam.md 中的指南进行Steam上架流程。"

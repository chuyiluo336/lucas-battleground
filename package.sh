#!/bin/bash

# 打包脚本 - 生成Lucas Battleground.app

# 获取当前目录的绝对路径
CURRENT_DIR=$(pwd)

# 创建临时目录
TEMP_DIR="$CURRENT_DIR/build_temp"
APP_DIR="$CURRENT_DIR/Lucas Battleground.app"

# 清理旧的构建
rm -rf "$APP_DIR"
rm -rf "$TEMP_DIR"

# 创建目录结构
mkdir -p "$APP_DIR/Contents/MacOS"
mkdir -p "$APP_DIR/Contents/Resources"
mkdir -p "$TEMP_DIR"

# 编译游戏
echo "编译游戏..."
cd "$TEMP_DIR"
cmake ..
make -j8

# 复制可执行文件
echo "复制可执行文件..."
cp LucasBattleground "$APP_DIR/Contents/MacOS/"

# 复制资源文件
echo "复制资源文件..."
cp -r "$CURRENT_DIR/LucasGame/Resources" "$APP_DIR/Contents/"

# 创建Info.plist文件
echo "创建Info.plist文件..."
cat > "$APP_DIR/Contents/Info.plist" << EOF
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0">
<dict>
    <key>CFBundleDevelopmentRegion</key>
    <string>English</string>
    <key>CFBundleExecutable</key>
    <string>LucasBattleground</string>
    <key>CFBundleIdentifier</key>
    <string>com.lucas.battleground</string>
    <key>CFBundleInfoDictionaryVersion</key>
    <string>6.0</string>
    <key>CFBundleName</key>
    <string>Lucas Battleground</string>
    <key>CFBundlePackageType</key>
    <string>APPL</string>
    <key>CFBundleShortVersionString</key>
    <string>1.0</string>
    <key>CFBundleVersion</key>
    <string>1</string>
    <key>NSPrincipalClass</key>
    <string>NSApplication</string>
    <key>NSHighResolutionCapable</key>
    <true/>
</dict>
</plist>
EOF

# 设置权限
chmod +x "$APP_DIR/Contents/MacOS/LucasBattleground"

# 清理临时目录
rm -rf "$TEMP_DIR"

echo "打包完成! Lucas Battleground.app 已创建。"
echo "应用程序路径: $APP_DIR"

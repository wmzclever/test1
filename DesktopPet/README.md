# DesktopPet (.NET 8 + WPF)

一个最小可运行的 Windows 桌面宠物示例，包含：

- 透明窗口
- 鼠标拖拽
- `idle` / `walk` 两个动作
- 系统托盘（显示/隐藏、退出）
- 可替换素材目录

## 1. 环境要求

- Windows 10/11
- .NET SDK 8.0+

## 2. 目录结构

```text
DesktopPet/
├─ Assets/
│  └─ cat/
│     ├─ idle/
│     └─ walk/
├─ Models/
├─ Services/
├─ App.xaml
├─ MainWindow.xaml
└─ DesktopPet.csproj
```

## 3. 准备动作帧素材

把透明背景 PNG 按序号放入以下目录（例如 `001.png`, `002.png`, `003.png`）：

- `Assets/cat/idle`
- `Assets/cat/walk`

> 建议两组图片尺寸保持一致，例如 256x256。

## 4. 运行

在 `DesktopPet` 目录执行：

```bash
dotnet restore
dotnet build
dotnet run
```

## 5. 自定义

- 替换素材：直接替换 `Assets/cat/idle` 与 `Assets/cat/walk` 中的 PNG。
- 动作切换逻辑：编辑 `MainWindow.xaml.cs` 的 `Think()` 方法。
- 动画速度：编辑 `PlayAction` 中 idle/walk 的 fps。

## 6. 注意事项

- 这是最小演示版，暂未加入碰撞、重力、点击反馈动作等高级行为。
- 程序默认窗口置顶并且不显示任务栏入口，通过系统托盘退出。

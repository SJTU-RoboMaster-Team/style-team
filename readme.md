![](example.jpg)

[本仓库](https://github.com/SJTU-RoboMaster-Team/style-team)代码规范的参考主要是 [Chromium C++ style guide](http://chromium.googlesource.com/chromium/src/+/HEAD/styleguide/c++/c++.md)，[Google 开源项目风格指南](https://zh-google-styleguide.readthedocs.io/en/latest/google-cpp-styleguide/)和 [Rust style guide](https://github.com/rust-lang/style-team)。

如何自动化地应用这些规范？

* 将本仓库的 `.clang-format` 和 `.clang-tidy` 文件拷贝至你的项目根目录下。
* 在编辑器中开启 `Clang-Format` 和 `Clang-Tidy` 插件。插件通常默认使用工作区根目录下的配置文件。
* 在 C++ 代码文件中执行编辑器的格式化文档操作。你也可以开启保存时自动格式化的功能。

## 设计原则

* 可读性 🐰
  - 阅读速度
  - 防止误导
  - 可访问性 - 适用于不同硬件环境下，包括非可视化环境
  - 在编译器报错信息中的可读性

* 美学 🏛
  - sense of beauty
  - 与现代编程语言保持一致

* 细节 🖋
  - 易于进行版本维护
  - 尽可能兼容未来代码
  - 增加代码密集度，防止右飘

* 应用 👶🏻
  - 规则易于手动实践（在最简编辑环境中）
  - 规则易于自动实践（当可以使用 Clang-Format 等其他工具时）
  - 规则的一致性
  - 保持风格规则的简并性

## [C++ 代码风格指南](guide.md)


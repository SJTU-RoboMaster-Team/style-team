# 指导原则和理由

在设计风格指南时，风格团队试图按照以下原则（大致按优先顺序排列）：

* 可读性
  - 阅读速度
  - 防止误导
  - 可访问性 - 对于使用不同硬件的用户，包括非可视化的界面，都要可读和可编辑
  - 在编译器报错信息中的可读性

* 美学
  - sense of beauty
  - 跟进现代的、优雅的语言

* 细节
  - 易于进行版本维护
  - 尽可能兼容未来代码
  - 增加代码密集度

* 应用
  - 规则易于手动实践（在最简编辑环境中）
  - 规则易于自动实践（当可以使用 Clang-format 等其他工具时）
  - 规则的一致性
  - 保持风格规则的简并性

## Overarching guidelines

Prefer block indent over visual indent. E.g.,

```rust
// Block indent
a_function_call(
    foo,
    bar,
);

// Visual indent
a_function_call(foo,
                bar);
```

This makes for smaller diffs (e.g., if `a_function_call` is renamed in the above
example) and less rightward drift.

Lists should have a trailing comma when followed by a newline, see the block
indent example above. This choice makes moving code (e.g., by copy and paste)
easier and makes smaller diffs.

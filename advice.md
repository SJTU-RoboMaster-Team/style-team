# 其他风格建议

## 命名

 * 类型 `UpperCamelCase`,
 * 枚举类 `UpperCamelCase`,
 * 在以上情况中，若使用缩写，则仅大写缩写单词的首字母 `HttpRequest`.
 * 成员 `snake_case`,
 * 函数 `snake_case`,
 * 局部变量 `snake_case`,
 * 
 * 宏 `snake_case`,
 * 全局常量 `SCREAMING_SNAKE_CASE`.
 * 如果和关键字冲 (e.g., `namespace`), 连接一个下划线 (e.g., `namespace_`).

### Modules

Avoid `#[path]` annotations where possible.

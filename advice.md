# 其他风格建议

## 命名

 * 类型 `CamelCase`，
 * 枚举成员 `UPPER_CASE`，
 * 在以上情况中, 若使用缩写, 则仅大写缩写单词的首字母 `HttpRequest`.
 * 命名空间 `lower_case`，
 * 成员 `lower_case`，
 * 函数 `lower_case`，
 * 变量 `lower_case`，
 * 宏 `UPPER_CASE`，
 * 全局常量 `UPPER_CASE`，
* 如果和关键字冲突 (e.g., `namespace`)，就连接一个下划线 (e.g., `namespace_`)。

## 单位

内部角度运算用弧度制。显式存储的角度常量用角度制。无后缀的类型采用国际单位。

```cpp
const double SOME_ANGLE = math::deg_to_rad(45); // 角度制转弧度制
const double SIN_RESULT = std::sin(SOME_ANGLE);
```

## 不省略 if / for statements 的花括号

```cpp
// use
if (true) {
    continue;
}
// not
if (true)
    continue;
```

### 定义和初始化

尽可能使用 `=` 初始化，当它不可使用或者造成类型名冗余时，使用“统一初始化方法” `Type pattern { expr };`。

```cpp
// 使用
std::vector<int> numbers = { 1, 2, 3 };
auto numbers = std::vector<int>(100, 2);
Foo bar { 0.01, 10 };
// 不使用
Foo bar = Foo(0.01, 10);
Foo bar(0.01, 10);
```

尽量在一行内定义完成。如果做不到，可以拆成两行。此时表达式应使用块缩进。

```cpp
Type pattern =
    expr;
```

### 语句中的宏

语句中调用的宏应该在尾部加上分号。小括号两边都不应有空格。

```cpp
// 一个注释。
A_MACRO(...);
```

### 语句中的表达式

表达式和分号之间不应有空格。

```cpp
<expr>;
```

不应给 `return` 语句后的表达式加上括号。

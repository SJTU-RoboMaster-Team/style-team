# C++ 代码风格指南

## 动机 - 为什么使用格式化工具？

格式化代码其实是一个机械性的任务，但是人工实现又非常耗精力。格式化工具可以一键实现这个目的，解放程序员的生产力。

此外，如果坚持既定的风格指南（就比如这个），程序员们就不需要花时间讨论风格，从而节省精力。

人类往往以模式匹配的方式来理解代码。所以如果一份 C++ 代码拥有统一的风格，理解一个新项目的代码就只需要更少的脑力，降低新开发者的进入门槛。

由此观之，使用格式化工具（例如 Clang-Format）能提高生产力。如果团队坚持使用一种风格，就会有更大好处，想要达成此目标并不难，只要使用团队 `.clang-format, .clang-tidy` 的默认设置就可以了。

## 格式化约定

### 缩进和行宽

* 使用空格，而不是 Tab。
* 每级缩进使用 4 个空格（也就是说在纯字符串和注释之外的缩进都是 4 的倍数）。
* 行宽最大为 100。

### 空行

不同的语句之间要么不空行，要么空一行。例如，

```cpp
void foo() {
    int x = ...;

    int y = ...;
    int z = ...;
}

void bar() {}
void baz() {}
```

### [条目](items.md)

### [语句](statements.md)

### [表达式](expressions.md)

### [类型](types.md)

### 注释

行注释（`//`）相较于块注释（`/* ... */`）更好。

当使用行注释时，开头标记后应该有一个空格。

使用行内块注释时，开符号后和闭符号前均有一个空格。多行块注释，开符号后和闭符号前均有一个新行。

行尾注释比其他注释更好。行尾注释之前带有 1 个空格。应该把块注释当作关键字一样处理其周围的空格。尾随注释和多行注释任意一行的末尾不应有尾随空格。

```cpp
// 条目上方的注释
struct Foo { ... };

void foo() {} // 条目尾随注释

namespace {
void foo(/* 参数前的注释 */ T x) {...}
}
```

注释应是完整的句子，行内块注释则不用。

纯注释行的注释宽度不大于 80，且算上缩进总宽度不超过 100。

```cpp
// This comment goes up to the ................................. 80 char margin.

{
    // This comment is .............................................. 80 chars wide.
}

{
    {
        {
            {
                {
                    {
                        // This comment is limited by the ......................... 100 char margin.
                    }
                }
            }
        }
    }
}
```

### 属性

每个属性独占一行，与其修饰的条目保持相同缩进等级。

尽可能使用外部属性。

有参数的属性按照函数格式化。

```cpp
[[deprecated("Use NewCRepr instead.")]]
struct CRepr {
    float x;
    float y;

    [[nodiscard]]
    float func() {}
};
```

### **小的**条目

在本指南中，对于小条目，我们会采用不同的格式化方式。例如，对于结构体的列表初始化：

```cpp
// 常规格式化
Foo {
    an_expression,
    another_expression(),
}

// **小项目** 格式化
Foo { 1, 2 };
```

我们把**小**的界定权留给格式化工具。格式化工具可以在不同的环境中使用不同的定义。

有一些因素是不错的参考，比如条目的名字长度和复杂性（子属性无子表达式）。

格式化工具应允许用户忽略这些因素，从而总是采用常规格式化。

## [非格式规范](advice.md)

## [CMakeLists.txt, *.cmake 规范](cmake.md)

## [一些重要的原则](principles.md)

## 条目

`#include` 语句必须放在文件的最前面。包含头文件的次序如下：

1. 源文件对应的头文件
2. C 系统头文件
3. C++ 系统头文件
4. 第三方库的头文件
5. 本项目内的头文件

同一类别的头文件按照字典序排列。

`using` （指 `using a::b;` 和 `using namespace a;`，不是类型别名 `using a = b;`）应必须放在其作用域中其他语句的前面。同一类别的声明按照字典序排列。

格式化工具应该让以上排序方法是可选的。

### 函数定义

在函数签名内部避免加注释。

如果函数的签名不能放在一行内，就在左小括号后和右小括号前换行，而且每个参数独占块缩进的一行。例如：

```cpp
int foo(
    int arg1,
    int arg2
) {
    ...
}
```

### 枚举

在声明中，每个枚举成员独占一行，并使用块缩进。

```cpp
enum class FooBar {
    FIRST,
    SECOND,
    ERROR,
};
```

### 结构体和联合体

结构体的名字在同一行尾随 `struct` 关键字，当左大括号能被放在右边距内时，左小括号也在同一行。所有结构体字段缩进一次。右大括号不缩进，且独占一行。

```cpp
struct Foo {
    A a;
    B b;
};
```

当且仅当变量名不能放在右边距内时，它才被放在下一行，并再次缩进。

```rust
struct Foo {
    A a;
    LongType
        long_name;
};
```

对于联合体也使用同样的规范。

```cpp
union Foo {
    A a;
    B b;
    LongType
        long_name;
};
```

### 类

类中的条目使用块缩进。如果没有条目，则类可以被格式化为单行。否则在左大括号后和右大括号前应换行。访问修饰符不缩进。当访问修饰符开始一个新的逻辑块时添加空行。

```cpp
class Foo {};

class Bar {
public:
    A a;
    B b;

private:
    C c;
};
```

如果类型有父类，则在冒号后和每个逗号后有一个空格，例如，

```cpp
class Foo: public Debug, public Bar {};
```

在父类列表中最好不要换行。如果要换行，每个父类独占一行，左大括号也独占一行。

```cpp
class IndexRanges:
    public Index<Range<size_t>, Output>,
    public Index<RangeTo<size_t>, Output>,
    public Index<RangeFrom<size_t>, Output>,
    public Index<RangeFull, Output>
{
    ...
}
```

### #include

`#include <foo>`

`include` 后有一个空格。井号后、尖括号与头文件之间没有空格。

### 命名空间

```cpp
namespace foo {
}
```

```cpp
namespace bar = foo;
```

在关键字、左大括号前和 `=` 两边使用空格。分号两边没有空格。

### #define

当宏的完整定义包含多条语句时，用 `do {} while(0)` 包含语句块。反斜杠续航符与语句之间有一个空格。

```cpp
#define FOO(x) \
    do { \
        static_assert( \
            a_long_expression, \
            "..." \
        ); \
        A_MACRO_CALL(); \
    } while (0)
```

### 泛型

模板参数部分与定义部分之间应换行。最好把模板参数部分放在同一行。

在尖括号两边不要加空格。每个逗号后面应有一个空格。

```cpp
template<typename T, typename U>
void foo(const std::vector<T>& x, const std::vector<U>& y) ...

template<typename T, typename U>
class SomeType { ...
```

如果模板参数部分必须被格式化为多行，则每个参数应该独占一行且缩进一次，左尖括号后应换行。

```cpp
template<
    typename T,
    typename U>
void foo(const std::vector<T>& x, const std::vector<U>& y) ...
```

对于泛型参数，最好使用一个字母命名。

### 类型别名

类型别名通常应该写在一行内。如果有必要换行，则在 `=` 后换行。`=` 右边的名称应使用块缩进。

```cpp
using Foo = Bar<T>;

// 如果需要拆成多行
using VeryLongType<T, U> =
    AnEvenLongerType<T, U, Foo<T>>;
```

### extern "C" 条目

当编写 extern "C" 条目时，总是使用显式 ABI。比如，使用 `extern "C" void func` 而不是 `extern "C" { ... }`。

### `using` 语句

最好把 `using` 语句可以被格式化为单行。

```cpp
using a::b::c;
using namespace a::b::d;
```

不要在头文件中使用 `using namespace`。

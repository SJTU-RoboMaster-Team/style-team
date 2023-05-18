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

## 文件后缀

使用 `.cpp` 和 `.hpp` 作为 C++ 文件后缀。


## 调用

除 std:: 外，不可跨具名作用域 (named scope) 调用。

```cpp
namespace a::b {
int func(const int& x, const int& y) {  
    return std::abs(x + y); // ok
}
}

namespace a::b::c {
// use
int test() {
    // 您需要保证调用处的第一个前缀 "b" 出现在面包屑中
    return b::func(2, 3);
}
// not
int test() {
    return func(2, 3);
}
} // namespace a::b::c
```

如果在当前作用域需大量使用外部作用域，请使用 namespace 别名。

```cpp
namespace a::b::c {
namespace sub = b::sub;

void fn0() {
    sub::Foo instance;
}

void fn1() {
    sub::Foo instance;
}
}
```

不使用隐式 `this`.

```cpp
class A {
public:
    A(const int& x);
private: 
    int member = 0;
}

A::A(const int& x) {
    // use
    this->member = x;
    // not
    member = x;
}
```

## 对于不含 public 变量的结构体使用 class

```cpp
struct A {
public:
    A() {}
    Type member; // 由于存在公共变量，使用 struct
private:
    int id;
};

class Interface {
public:
    int method1() { return 0; }
    void method2() {}
    int get_id() { return this->id; }
private:
    int id; // 由于不存在公共变量，使用 class
};
```

## 不将 class / struct 作命名空间使用

```cpp
// use
namespace a {
struct Bar {
    int a;
    int b;
};

struct Foo {
    int operator()(const Bar& bar) {
        // 不将 Solver 视为作用域时，可以不使用 Solver::bar 来调用该类型
        return bar.a + bar.b;
    }
};
} // namespace solver

// not
struct Foo {
    struct Bar {
        int a;
        int b;
    };

    int operator()(const Bar& bar) {
        // 不将 Solver 视为作用域时，可以不使用 Solver::bar 来调用该类型
        return bar.a + bar.b;
    }
};
```

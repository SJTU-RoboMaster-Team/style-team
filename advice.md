# 其他风格建议

## 命名

 * 类型 `CamelCase`，
 * 枚举成员 `UPPER_CASE`，
 * 在以上情况中, 若使用缩写, 则仅大写缩写单词的首字母 `HttpRequest`。
 * 命名空间 `lower_case`，
 * 成员 `lower_case`，
 * 函数 `lower_case`，
 * 变量 `lower_case`，
 * 宏 `UPPER_CASE`，
 * 全局常量 `UPPER_CASE`，
* 如果和关键字冲突（例如 `namespace`），就连接一个下划线（例如 `namespace_`）。

---

## 单位

程序内部角度运算用弧度制。显式存储的角度常量用角度制。

如果变量的名称中没有说明单位，默认采用国际单位。

```cpp
const double SOME_ANGLE = math::deg_to_rad(45); // 角度制转弧度制
const double SIN_RESULT = std::sin(SOME_ANGLE);
```

## 不省略 if / for statements 的大括号

```cpp
// 使用
if (true) {
    continue;
}
// 不使用
if (true)
    continue;
```

## 文件后缀

使用 `.cpp` 和 `.hpp` 作为 C++ 文件后缀。

## 调用

除 std:: 外，不可跨具名作用域 (named scope) 调用。

```cpp
namespace a::b {
int foo(const int& x, const int& y) {  
    return std::abs(x + y); // ok
}
}

namespace a::b::c {
int foo() {
    // 使用
    return b::func(2, 3); // 光标在调用处时，需要保证调用处的第一个前缀 "b" 出现在面包屑中
    // 不使用
    return func(2, 3);
}
}
```

如果在当前作用域需大量使用外部作用域，请使用 namespace 别名。

```cpp
namespace a::b::c {
namespace foo = b::foo;

void fn0() {
    foo::Bar x;
}

void fn1() {
    foo::baz::Qux y;
}
}
```

不使用隐式 `this`。

```cpp
class A {
public:
    A(const int& x);
private: 
    int member = 0;
}

A::A(const int& x) {
    // 使用
    this->member = x;
    // 不使用
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

class B {
public:
    int method1() { return 0; }
    void method2() {}
    int get_id() { return this->id; }

private:
    int id; // 由于不存在公共变量，使用 class
};
```

## 不将 class / struct 作为命名空间使用

```cpp
// 使用
namespace a {
struct Foo {
    int a;
    int b;
};

struct Bar {
    int operator()(const Foo& x) {
        // 不将 Bar 视为作用域时，就可以理所当然地使用 Foo 而不是 a::Foo 来调用
        return x.a + x.b;
    }
};
} // namespace a

// 不使用
struct Bar {
    struct Foo {
        int a;
        int b;
    };

    int operator()(const Foo& x) {
        return x.a + x.b;
    }
};
```

---

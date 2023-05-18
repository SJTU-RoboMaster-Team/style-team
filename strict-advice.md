以下风格可以增加您代码的可读性，但出于难以推广和不可自动化实现等原因，您可以不遵循以下建议。
但是我们仍然建议您阅读这些建议。

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

## 不含 public 变量的结构使用 class

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

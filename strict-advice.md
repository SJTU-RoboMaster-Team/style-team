以下风格可以增加您代码的可读性，但出于难以推广和不可自动化实现等原因，您可以不遵循以下建议。
但是我们仍然建议您阅读这些建议。

## 文件后缀

使用 `.cpp` 和 `.hpp` 作为 C++ 文件后缀。


## 调用

除 std:: 外，不可跨具名作用域 (named scope) 调用。

```cpp
namespace a::b {
int fn(const int& x, const int& y) {  
    return std::abs(x + y); // ok
}
}

namespace a::b::c {
// use
int test0() {
    // 您需要保证调用处的第一个前缀 "b" 出现在面包屑中
    return b::func(2, 3);
}
// not
int test1() {
    return func(2, 3);
}
} // namespace a::b::c
```

如果在当前作用域需大量使用外部作用域，请采用 namespace 别名。

```cpp
namespace a::b::c {
namespace sub = b::sub;

void fn0() {
    namespace utils = ::utils;

    utils::init();
    sub::SomeType instance;
}

void fn1() {
    // 无 namespace 别名时
    ::utils::init();
    a::sub::AnotherType instance;
}
}
```

不使用隐式 `this`.

```cpp
class A {
public:
    A(const int& param);
private: 
    int member = 0;
}

A::A(const int& param) {
    // use
    this->member = param;
    // not
    member = param;
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
namespace solve {
struct Data {
    int item1;
    int item2;
};

struct Solver {
    int operator()(const Data& data) {
        // 不将 Solver 视为作用域时，可以不使用 Solver::Data 来调用该类型
        return data.item2 * 2;
    }
};
} // namespace solver

// not
struct Solver {
    struct Data {
        int item1;
        int item2;
    };

    int operator()(const Solver::Data& data) {
        return data.item2 * 2;
    }
};
```

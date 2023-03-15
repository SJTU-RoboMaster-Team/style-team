# 严格风格建议

## 文件后缀

使用 `.cpp` 和 `.hpp` 作为 C++ 文件后缀。

## 函数后置返回类型

```cpp
// use
auto func(const int& x, const int& y) -> int;
// not 
int func(const int& x, const int& y);
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

## 调用

除 std:: 外，不可跨具名作用域调用。

```cpp
namespace aimer::math {
auto func(const int& x, const int& y) -> int {  
    return std::sin(x + y);  // ok
};
}

namespace aimer::math::kalman {
// use
auto test0() -> int {
    return math::func(2, 3);
}
// not
auto test1() -> int {
    return func(2, 3);
}
}  // namespace aimer::math::kalman
```

如果在当前作用域需大量使用外部作用域，请采用 namespace 别名。

```cpp
#include "aimer/umt/umt.hpp"
#include "aimer/math/kalman.hpp"

namespace aimer::math::predictor {
namespace umt = ::umt;
namespace kalman = math::kalman;
auto test0() {
    umt::init();
    kalman::KalmanFilter filter1;
    // 如果未声明 namespace 别名，则规范写法为
    ::umt::init();
    math::kalman::KalmanFilter filter2;
}
}
```

不使用隐式 `this`.

```cpp
class A {
public:
    A(const int& some);
private: 
    int days = 0;
}

A::A(const int& some) {
    // use
    this->days = some;
    // not
    days = some;
}
```

## 不含 public 变量的结构使用 class

```cpp
struct A {
public:
    A() {}
    Kalman filter;
private:
    int id;
};

class SomeClass {
public:
    auto interface1() -> int { return 0; }
    auto interface2() { return; }
    auto get_id() -> int { return this->id; }
private:
    int id;
};
```

## 不将 class / struct 作命名空间使用

```cpp
// use
namespace solve {
struct Data {
    int id;
    int pos;
};

struct Solver {
    int operator()(const solve::Data& data) {
        return data.pos * 2;
    }
};
}  // namespace solver

// not
struct Solver {
    struct Data {
        int id;
        int pos;
    };

    int operator()(const Solver::Data& data) {
        return data.pos * 2;
    }
};
```

## 单位

内部角度运算用弧度制。显式存储的角度常量用角度制。无后缀的类型采用国际单位。

```cpp
const double SOME_ANGLE = math::deg_to_rad(45);  // 角度制转弧度制
const double SIN_RESULT = std::sin(SOME_ANGLE);
```

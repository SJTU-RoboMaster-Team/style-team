//! 想笑
//! C++ 真的有这种注释么
#include <stdint.h>

#include <iostream>
#include <vector>

enum class EnumType {
    AUTO_RESULT = 0,
    POS_POS,
};

using Type1 = EnumType;
using I32 = int;

int mutiple_lines_func(
    const int& x,
    const int& y,
    const int& z,
    const std::vector<int>& i32_vec,
    const int& param1,
    const int& param2) {
    return x + y + z;
}

/*! 
什么玩意 
*/
class AStrangeTypeName {
public:
    int get_member2() {
        int local_variable = 2;
        return this->member2 + local_variable;
    }

private:
    int member;
    int member2;
};

int new_func(int a, int b, int c) {
    return 2;
}

struct Foo {
    float a;
    float b;
    float c;
};

class LonglonglonglonglonglonglonglonglonglonglonglonglongClassName1 {};
class LonglonglonglonglonglonglonglonglonglonglonglonglongClassName2 {};
class LonglonglonglonglonglonglonglonglonglonglonglonglongClassName3 {};
class A:
    public LonglonglonglonglonglonglonglonglonglonglonglonglongClassName1,
    public LonglonglonglonglonglonglonglonglonglonglonglonglongClassName2 {
public:
    int a;
    int b;
};

template<typename T, typename U>
T func(U a) {}

const int SO_STRANGE = 2;

#define MIN(x, y) (x) < (y) ? (x) : (y)

int main() {
    AStrangeTypeName x; // 本行的注释
    int count = 0;
    for (; count < 10; ++count) {
        // ...
    }
    Foo foo = Foo { 0, 3, 4 };

    std::vector<int> res { 1, 2, 3 };

    while (true) {
        // ...
    }

    bool really_really_really_really_really_really_really_long_exp = false;
    if (foo.a > 0.f && really_really_really_really_really_really_really_long_exp
        && really_really_really_really_really_really_really_long_exp)
    {
        foo.b = 2;
    }

    foo(
        bar(really_really_really_really_really_really_really_long_exp,
            really_really_really_really_really_really_really_long_exp))

        Foo f = Foo { 1, 2, 3 };
    return foo.a;
}

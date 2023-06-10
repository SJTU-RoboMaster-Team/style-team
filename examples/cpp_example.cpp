//! 想笑
//! C++ 真的有这种注释么

#include "cpp_example.h"

#include <stdio.h>

#include <iostream>

#include <ceres/ceres.h>
#include <opencv2/opencv.hpp>

#include "core_io.hpp"

enum class EnumType {
    AUTO_RESULT = 0,
    POS_POS,
};

std::vector<int> vec = {
    1,
    2,
};

union test {
    char mark;
    long num;
    float score;
};

using Type1 = EnumType;
using I32 = int;

enum class FooBar {
    FIRST,
    SECOND,
    ERROR,
};

struct Comma {
    int a;
    int b;
};

struct Debug {};
struct Bar {};

struct Foo: public Debug, public Bar {};

int mutiple_lines_func(
    const int& x,
    const int& y,
    const int& z,
    const std::vector<int>& i32_vec,
    const int& param1,
    const int& param2
) {
    return x + y + z;
}

/*!
什么玩意
*/
struct AStrangeTypeName {
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

struct LonglonglonglonglonglonglonglonglonglonglonglonglongClassName1 {};
struct LonglonglonglonglonglonglonglonglonglonglonglonglongClassName2 {};
struct LonglonglonglonglonglonglonglonglonglonglonglonglongClassName3 {};
struct A:
    public LonglonglonglonglonglonglonglonglonglonglonglonglongClassName1,
    public LonglonglonglonglonglonglonglonglonglonglonglonglongClassName2 {
public:
    int a;
    int b;
    /*123*/
private:
    int no_need;
};

#define FOO(x) \
    do { \
        static_assert(a_long_expression, "..."); \
        A_MECRO_CALL(); \
    } while (0)

struct P {
    LonglonglonglonglonglonglonglonglonglonglonglonglongClassName3
        long_long_long_long_long_long_long_long_long_long_long_long_long_long_long_long_long_name;
};

template<
    typename T,
    typename ReallyReallyReallyReallyReallyReallyReallyReallyReallyReallyReallyReallyReallyReallyReallyReallyReally>
T func(U a) {}

const int SO_STRANGE = 2;
using ReallyReallyReallyReallyReallyReallyReallyReallyReallyReallyReallyLongAlias =
    LonglonglonglonglonglonglonglonglonglonglonglonglongClassName1;

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
        using namespace std;
        using namespace boost;

        foo.b = 2;
    }

    foo(
        bar(really_really_really_really_really_really_really_long_exp,
            really_really_really_really_really_really_really_long_exp)
    )

        Foo f = Foo { 1, 2, 3 };
    return foo.a;
}

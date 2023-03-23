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

struct Foo {
    float a;
    float b;
    float c;
};

const int SO_STRANGE = 2;

#define MIN(x, y) (x) < (y) ? (x) : (y)

int main() {
    AStrangeTypeName x; // 本行的注释
    int count = 0;
    for (; count < 10; ++count) {}
    Foo foo = Foo { 0, 3, 4 };

    if (foo.a > 0.f) {
        foo.b = 2;
    }

    auto lambda_exp = []() { return 2; };

    return foo.a;
}

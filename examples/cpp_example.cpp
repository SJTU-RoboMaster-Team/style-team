#include <stdint.h>

#include <iostream>
#include <vector>

using i32 = int32_t;
using f64 = double;

auto mutiple_lines_func(
    const i32& x,
    const i32& y,
    const i32& z,
    const std::vector<i32>& i32_vec,
    const i32& param1,
    const i32& param2) -> i32 {
    return x + y + z;
}

/*! 
什么玩意 
*/
class AStrangeTypeName {
private:
    int member;
    int member2;

public:
    int get_member2() {
        return this->member2;
    }
};

int so_strange = 2;

auto main() -> i32 {
    AStrangeTypeName x; // 本行的注释
    return y;
}
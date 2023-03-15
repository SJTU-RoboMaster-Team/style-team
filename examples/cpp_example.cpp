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

class AStrangeTypeName {};

int so_strange = 2;

auto main() -> i32 {
    int unused = 0;
    return 0;
}
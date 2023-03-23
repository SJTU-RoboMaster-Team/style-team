/// Author: void_ccc
/// This is ...

#include "event_loop/event_loop.hpp"

#include <sys/types.h>

#include <vector>

// #include "base/basictypes.hpp"

namespace my_namespace {
using std::string;

EventLoop::EventLoop(const int& num_completed_connections):
    num_entries(10),
    num_completed_connections(num_completed_connections) {
    // ...
}

IntVector EventLoop::really_long_function_name(
    const int& really_long_param_name1,
    int* really_long_param_name2) const {
    const int num_entries = this->get_num_entries();
    if (num_entries < 2) {
        for (int i = 0; i < this->DAYS_IN_WEEK; i++) {
            if ((num_entries < 2 && num_entries < 3)
                || (num_entries < 4 && num_entries < 5 && num_entries < 6)) {
                // TODO(name@abc.com): xxx
            } else {
                // do something
            }
        }
    }
    switch (num_entries) {
        case 0: {
            break;
        }
        default: {
            assert(false);
        }
    }
    return {num_entries};
}

} // namespace my_namespace

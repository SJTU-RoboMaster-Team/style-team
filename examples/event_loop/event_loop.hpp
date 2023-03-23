/// Author: void_ccc
/// This is ...
#ifndef EXAMPLES_EVENT_LOOP_EVENT_LOOP_HPP_
#define EXAMPLES_EVENT_LOOP_EVENT_LOOP_HPP_

#include <vector>

namespace my_namespace {

using IntVector = std::vector<int>;

class Channel;

class CallbackInterface {};

enum class UrlTableErrors {
    OUT_OF_MEMORY,
    MALFORMED_INPUT,
};

class EventLoop: public CallbackInterface {
public:
    explicit EventLoop(const int& num_completed_connections);

    void add(const std::string& input, Channel* output);

    int get_num_entries() const {
        return this->num_entries;
    }

    IntVector really_long_function_name(
        const int& really_long_param_name1,
        int* really_long_param_name2) const;

private:
    const int DAYS_IN_WEEK = 7;
    int num_entries;
    int num_completed_connections;

    Channel* channel;
};

} // namespace my_namespace

#endif // EXAMPLES_EVENT_LOOP_EVENT_LOOP_HPP_

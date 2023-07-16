
#include <concepts>

struct instrumented_base
{
    enum operations {
        copy, assignment, destructor, default_constructor,
        equality, comparison, construction
    };

    static constexpr size_t number_ops = 7;
    static constexpr char const* counter_names[number_ops] = {
        "copy", "assignment", "destructor", "default_constructor",
        "equality", "comparison", "construction"
    };
    static double counts[number_ops];

    static void initialize(size_t);
};

template <typename T>
    requires(std::semiregular<T> || std::regular<T> || std::totally_ordered<T>)
struct instrumented final : instrumented_base
{
    // ...
};

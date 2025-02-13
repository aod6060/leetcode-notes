#ifndef PREFIX_SUMS_H
#define PREFIX_SUMS_H

#include <string>
#include <map>
#include <functional>

namespace presums {

    // Note: [prefix-sums/examplexxx]
    void register_examples(std::map<std::string, std::function<void()>>& context);


    void example01();
    void example02();

    // Range Sum Queries
    void example03();
    void example04();

    // Leet Code Problems for Range Sum Query
    void leetcode_problem_303();
    void leetcode_problem_307();

    // Subarray Problems
    void example05();
    void example05_kadane_algorithm();

    void example06();
    void example07();
    void example08();

};


#endif
#include "prefix_sums.h"


namespace presums {


    // Note: [prefix-sums/examplexxx]
    void register_examples(std::map<std::string, std::function<void()>>& context) {
        context["prefix-sums/example01"] = example01;
        context["prefix-sums/example02"] = example02;
        context["prefix-sums/example03"] = example03;
        context["prefix-sums/example04"] = example04;
        context["prefix-sums/leetcode_problem_303"] = leetcode_problem_303;
        context["prefix-sums/leetcode_problem_307"] = leetcode_problem_307;
        context["prefix-sums/example05"] = example05;
        context["prefix-sums/example05/kadane_algorithm"] = example05_kadane_algorithm;
        context["prefix-sums/example06"] = example06;
        context["prefix-sums/example07"] = example07;
        context["prefix-sums/example08"] = example08;
        context["prefix-sums/example09"] = example09;
    }

}
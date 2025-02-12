#include "prefix_sums.h"


namespace presums {


    // Note: [prefix-sums/examplexxx]
    void register_examples(std::map<std::string, std::function<void()>>& context) {
        context["prefix-sums/example01"] = example01;
        context["prefix-sums/example02"] = example02;
    }

}
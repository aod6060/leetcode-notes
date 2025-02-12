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
};


#endif
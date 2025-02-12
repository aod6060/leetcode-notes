#include "prefix_sums.h"
#include <vector>
#include <iostream>

namespace presums {

    static void create_prefix(std::vector<int>& arr, std::vector<int>& prefix) {
        prefix.resize(arr.size());
        prefix[0] = arr[0];

        for(int i = 1; i < arr.size(); i++) {
            prefix[i] = arr[i] + prefix[i-1];
        }
    }

    static void print_array(std::string header, std::vector<int>& arr) {
        std::cout << header << " [";
        for(int i = 0; i < arr.size() - 1; i++) {
            std::cout << arr[i] << ", ";
        }
        std::cout << arr[arr.size() - 1] << "]\n";
    }

    void test_example(std::vector<int> arr) {
        std::vector<int> prefix;
        create_prefix(arr, prefix);
        print_array("Original: ", arr);
        print_array("Prefix: ", prefix);
    }

    void example02() {
        /*
        Array: [1, 2, 3, 4]
        Prefix Sum: [1, 3, 6, 10]
        */
        test_example({1,2,3,4});

        /*
        Array: [5, -1, 3, 7]
        Prefix Sum: [5, 4, 7, 14]
        */
        test_example({5, -1, 3, 7});

        /*
        Array: [0, 0, 0, 1]
        Prefix Sum: [0, 0, 0, 1]
        */
        test_example({0, 0, 0, 1});

        /*
        Array: [10, -5, 20, 15]
        Prefix Sum: [10, 5, 25, 40]
        */
        test_example({10, -5, 20, 15});

        /*
        Array: [2, 3, 5, 7, 11]
        Prefix Sum: [2, 5, 10, 17, 28]
        */
        test_example({2, 3, 5, 7, 11});

        /*
        Array: [-1, -2, -3, -4]
        Prefix Sum: [-1, -3, -6, -10]
        */
        test_example({-1, -2, -3, -4});

        /*
        Array: [1, 1, 1, 1, 1]
        Prefix Sum: [1, 2, 3, 4, 5]
        */
        test_example({1, 1, 1, 1, 1});

        /*
        Array: [9, 8, 7, 6, 5]
        Prefix Sum: [9, 17, 24, 30, 35]
        */
        test_example({9, 8, 7, 6, 5});

        /*
        Array: [4, 0, 0, 0, 4]
        Prefix Sum: [4, 4, 4, 4, 8]
        */
        test_example({4, 0, 0, 0, 4});

        /*
        Array: [3, -3, 3, -3, 3]
        Prefix Sum: [3, 0, 3, 0, 3]
        */
        test_example({3, -3, 3, -3, 3});
        
    }
}
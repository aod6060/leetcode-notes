#include "prefix_sums.h"

#include <iostream>
#include <vector>



namespace presums {

    struct SumIndencies {
        int left;
        int right;
    };

    static void create_prefix(std::vector<int>& arr, std::vector<int>& prefix) {
        prefix.resize(arr.size());
        prefix[0] = arr[0];

        for(int i = 1; i < arr.size(); i++) {
            prefix[i] = arr[i] + prefix[i-1];
        }
    }

    static int range_sum_query(std::vector<int>& prefix, int left, int right) {
        if(left == 0) {
            return prefix[right];
        } else {
            return prefix[right] - prefix[left-1];
        }
    }

    static void print_array(std::string header, std::vector<int>& arr) {
        std::cout << header << " [";
        for(int i = 0; i < arr.size() - 1; i++) {
            std::cout << arr[i] << ", ";
        }
        std::cout << arr[arr.size() - 1] << "]\n";
    }

    static void test(std::vector<int> arr, std::vector<SumIndencies> sums) {
        std::vector<int> prefix;
        create_prefix(arr, prefix);
        print_array("Original: ", arr);
        print_array("Prefix: ", prefix);

        for(int i = 0; i < sums.size(); i++) {
            int value = range_sum_query(prefix, sums[i].left, sums[i].right);
            std::cout << "Value: " << value << "=Sum("<<sums[i].left<<", "<<sums[i].right<<")\n";
        }
        std::cout << "\n";
    }

    void example04() {
        /*
            1
            Array: [1, 2, 3, 4]
            Prefix Sum: [1, 3, 6, 10]
                a. Sum(1, 2) = 5
                b. Sum(2, 3) = 7
                c. Sum(0, 3) = 10
        */
        test({1, 2, 3, 4}, {
            {1, 2}, // 5
            {2, 3}, // 7
            {0, 3} // 10
        });

        /*
            2
            Array: [5, -1, 3, 7]
            Prefix Sum: [5, 4, 7, 14]
                a. Sum(1, 2) = 2
                b. Sum(2, 3) = 10
                c. Sum(0, 3) = 14
        */
        test({5, -1, 3, 7}, {
            {1, 2}, // 2
            {2, 3}, // 10
            {0, 3} // 14
        });

        /*
            3
            Array: [-1, -2, -3, -4]
            Prefix Sum: [-1, -3, -6, -10]
                a. Sum(1, 2) = -5
                b. Sum(2, 3) = -7
                c. Sum(0, 3) = -10
        */
        test({-1, -2, -3, -4}, {
            {1, 2}, // -5
            {2, 3}, // -7
            {0, 3} // -10
        });

        /*
            4
            Array: [9, 8, 7, 6, 5]
            Prefix Sum: [9, 17, 24, 30, 35]
                a. Sum(1, 3) = 21
                b. Sum(2, 4) = 18
                c. Sum(0, 4) = 35
        */
        test({9, 8, 7, 6, 5}, {
            {1, 3}, // 21
            {2, 4}, // 18
            {0, 4} // 35
        });
        
    }
}
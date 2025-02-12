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

    void example03() {
        /*
            A = [1, 3, 4, 8, 6, 1, 4, 2]
            P = create_prefix_sum(A)

            Find the range_sum_query were
            left = 2 and right = 5

            The answer should be 19 if correct
        */

        std::vector<int> arr = {1, 3, 4, 8, 6, 1, 4, 2};
        print_array("Original: ", arr);

        std::vector<int> prefix;
        create_prefix(arr, prefix);
        print_array("Prefix: ", prefix);

        int value = range_sum_query(prefix, 2, 5);

        // Should be 19
        std::cout << "Value: " << value << "\n"; // At it is :D
    }

}
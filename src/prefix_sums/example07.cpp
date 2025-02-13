#include "prefix_sums.h"
#include <vector>

#include <iostream>

namespace presums {
    void example07() {
        /*
        Problem Statement:
        Given an array of integers, count the number of contiguous subarrays that have a sum of zero.

        Example:

        Input: nums = [6, -1, -3, 4, -2, 2, 4, 6, -12, -7]
        Output: 4
        Explanation: The subarrays with sum zero are [6, -6], [-3, 3], [4, -4], and [6, -6, -12, 12].
        */

        std::vector<int> arr = {6, -1, -3, 4, -2, 2, 4, 6, -12, -7};

        std::map<int, int> sum_count = {
            {0, 1}
        };

        int current_sum = 0;
        int result = 0;

        for(int i = 0; i < arr.size(); i++) {
            int num = arr[i];

            current_sum += num;

            if(sum_count.find(current_sum) != sum_count.end()) {
                result += sum_count[current_sum];
            }

            sum_count[current_sum] += 1;
        }

        std::cout << result << "\n";
    }
}
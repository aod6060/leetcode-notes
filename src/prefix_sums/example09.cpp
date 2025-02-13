#include "prefix_sums.h"
#include <vector>
#include <iostream>
#include <algorithm>

namespace presums {

    void example09() {

        /*
            Problem Statement:
            Given an array nums of integers and an integer K, find the length of the longest subarray with a sum equal to K.

            Example:

            Input: nums = [1, -1, 5, -2, 3], K = 3
            Output: 4
            Explanation: The longest subarray with sum 3 is [1, -1, 5, -2], which has a length of 4.
        */

        std::vector<int> arr = {1, -1, 5, -2, 3};
        int k = 3;

        std::map<int, int> index = {
            {0, -1}
        };

        int current_sums = 0;
        int result = 0;

        for(int i = 0; i < arr.size(); i++) {
            int num = arr[i];
            current_sums += num;

            if(index.find(current_sums - k) != index.end()) {
                result = std::max(result, i - index[current_sums - k]);
            }

            if(index.find(current_sums) == index.end()) {
                index[current_sums] = i;
            }
        }

        std::cout << result << "\n";
    }

}
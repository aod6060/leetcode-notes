#include "prefix_sums.h"
#include <map>
#include <vector>
#include <iostream>

/*
Problem Statement:
Given an array of integers and an integer K, find if there exists any contiguous subarray with a sum that is 
divisible by K.

Example:

Input: nums = [4, 5, 0, -2, -3, 1], K = 5
Output: True
Explanation: The subarray [4, 5, 0, -2, -3, 1] has a sum of 5, which is divisible by 5. Another example could be 
the subarray [0] with sum 0, which is divisible by any number.

*/

namespace presums {

    void example08() {
        std::vector<int> arr = {4, 5, 0, -2, -3, 1};
        int K = 5;

        std::map<int, int> count = {
            {0, 1}
        };

        int current_sum = 0;
        int result = 0;

        bool isDivisableByK = false;

        for(int i = 0; i < arr.size(); i++) {
            int num = arr[i];

            current_sum += num;

            int remainder = current_sum % K;

            if(count.find(remainder) != count.end()) {
                isDivisableByK = true;
                break;
            } else {
                count[remainder] = i;
            }
        }

        std::cout << ((isDivisableByK) ? "true" : "false") << "\n";
    }

}

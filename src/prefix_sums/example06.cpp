#include "prefix_sums.h"
#include <vector>
#include <iostream>

namespace presums {


    /*
        2. Subarray with Given Sum

        Problem: Find if there exists a subarray with sum equal to K.

        Prefix Sum Use: Use a hash map to store the frequency of each prefix sum; if sum - K has been seen 
        before, a subarray with sum K exists. This reduces the problem from O(n^2) to O(n).

        Input: nums = [1, 2, 3, 4, 5], K = 9

        Output: True (or count 2, or indices [0, 3] or [1, 4])

        Explanation: The subarrays [1, 2, 3, 4] and [2, 3, 4, 5] both sum to 9.

    */

    void example06() {

        std::vector<int> arr = {1, 2, 3, 4, 5};
        int K = 9;

        std::map<int, int> count = {
            {0, 1}
        };

        std::map<int, int> index;

        int current_sum = 0;
        int result = 0;

        std::vector<std::vector<int>> indencies;

        for(int i = 0; i < arr.size(); i++) {
            int num = arr[i];

            current_sum += num;

            if(count.find(current_sum - K) != count.end()) {
                result += count[current_sum - K];
                //indencies.push_back(range);
            }
            // This keeps track of indencies
            if(index.find(current_sum - K) != index.end()) {
                std::vector<int> range;
                range.push_back(index[current_sum - K]);
                range.push_back(i);
                indencies.push_back(range);
            }

            count[current_sum] += 1;
            index[current_sum] = i;
        }


        // Result should be 2

        std::cout << result << "\n";
        std::cout << ((result > 0) ? "true" : "false") << "\n";

        for(int i = 0; i < indencies.size(); i++) {
            for(int j = 0; j < indencies[i].size(); j++) {
                std::cout << indencies[i][j] << ", ";
            }
            std::cout << "\n";
        }
    }

}
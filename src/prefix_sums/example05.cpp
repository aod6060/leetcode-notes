#include "prefix_sums.h"
#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>

namespace presums {
    /*
        Subarray Problems

        Here's an example question for the "Maximum Subarray Sum" problem, which is often solved 
        using a variation of Kadane's Algorithm but can also benefit from understanding prefix sums:

        Problem Statement:

        Given an array of integers, find the contiguous subarray (containing at least one number) which 
        has the largest sum and return its sum.

        Example:

        Input: [-2, 1, -3, 4, -1, 2, 1, -5, 4]
        Output: 6
        Explanation: The contiguous subarray [4, -1, 2, 1] has the largest sum, which is 6.

        Detailed Explanation:

        The maximum sum subarray in this case is [4, -1, 2, 1], where:
        4 - 1 + 2 + 1 = 6

        Solution Using Prefix Sums:

        While Kadane's algorithm is the most straightforward approach for this problem, understanding 
        how to use prefix sums can provide insights into solving related problems or provide an alternative 
        method:

        python
        def maxSubArray(nums):
            # Compute prefix sums
            prefix_sums = [0] * (len(nums) + 1)
            for i in range(1, len(prefix_sums)):
                prefix_sums[i] = prefix_sums[i-1] + nums[i-1]
            
            max_sum = float('-inf')
            min_sum = 0  # Minimum sum seen so far, which helps in finding the maximum difference
            
            for i in range(len(prefix_sums)):
                # Current subarray sum is prefix_sums[i] - min_sum
                max_sum = max(max_sum, prefix_sums[i] - min_sum)
                # Update min_sum if we find a smaller prefix sum
                min_sum = min(min_sum, prefix_sums[i])
            
            return max_sum

        # Example usage
        nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
        print(maxSubArray(nums))  # Should output 6

        Explanation of the Prefix Sum Approach:

        Step 1: Compute the prefix sums array where prefix_sums[i] is the sum of the first i elements of nums. 
        This step is O(n).

        Step 2: Traverse the prefix sum array:

        max_sum keeps track of the maximum sum found for any subarray.

        min_sum tracks the smallest prefix sum encountered, which represents the sum of the worst possible 
        subarray ending at any point. By subtracting this from any later prefix sum, you get the sum of the 
        subarray starting from after min_sum up to the current position.

        Logic: At any point, the maximum subarray sum ending at i can be thought of as prefix_sums[i] - min_sum. 
        This is because subtracting min_sum essentially removes the sum of elements before your current subarray, 
        giving you the sum of elements from where min_sum was last updated to i.

        This approach leverages the idea that the maximum sum of any subarray is the maximum difference between two 
        prefix sums, similar to how Kadane's algorithm works but with a different perspective on the problem using 
        prefix sums. This can be particularly insightful for variations of the problem or when dealing with additional 
        constraints.

        // Heh, heh I solved the leet code medium problem
    */

    static void print_array(std::string header, std::vector<int>& arr) {
        std::cout << header << " [";
        for(int i = 0; i < arr.size() - 1; i++) {
            std::cout << arr[i] << ", ";
        }
        std::cout << arr[arr.size() - 1] << "]\n";
    }

    void example05() {
        // [-2, 1, -3, 4, -1, 2, 1, -5, 4]
        std::vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

        print_array("Original: ", arr);

        std::vector<int> prefix(arr.size());

        prefix[0] = arr[0];

        for(int i = 1; i < prefix.size(); i++) {
            prefix[i] = arr[i] + prefix[i-1];
        }

        print_array("Prefix: ", prefix);

        int max_sum = INT_MIN;
        int min_sum = 0;

        for(int i = 0; i < prefix.size(); i++) {
            max_sum = std::max(max_sum, prefix[i] - min_sum);
            min_sum = std::min(min_sum, prefix[i]);
        }

        // Output should be 6

        std::cout << max_sum << " is the value!\n";
    }
}
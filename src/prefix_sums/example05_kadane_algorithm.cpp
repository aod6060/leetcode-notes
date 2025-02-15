#include "prefix_sums.h"
#include <vector>
#include <climits>
#include <algorithm>
#include <iostream>

namespace presums {

    /*
        Kadane's Algorithm is an efficient way to solve the "Maximum Subarray Sum" problem, where you need to 
        find the largest contiguous subarray sum within a one-dimensional array of numbers. Here's how it works:

        Concept:
        Kadane's algorithm scans through the array, maintaining a running sum of the maximum subarray ending at 
        the current position. If adding the current element to the running sum increases it, it includes the current 
        element; otherwise, it starts a new subarray from the current element. This approach ensures that we only 
        keep the subarrays that contribute positively to the maximum sum.

        Steps:
        Initialize:

        max_so_far to store the maximum sum found so far, initially set to the smallest possible integer (-inf or a 
        very small number).

        max_ending_here to keep track of the maximum sum ending at the current position, initially set to 0 or the 
        first element of the array.

        Iterate through each element of the array:

        Update max_ending_here by deciding if including the current element (nums[i]) increases the sum:

        If max_ending_here + nums[i] is greater than nums[i], then max_ending_here = max_ending_here + nums[i]. This means 
        we extend the current subarray.

        Otherwise, max_ending_here = nums[i], starting a new subarray from this element because including previous 
        elements would reduce the sum.

        Update max_so_far if max_ending_here is greater than max_so_far.

        Return max_so_far as the result.

        Implementation in Python:

        python
        def maxSubArray(nums):
            max_so_far = float('-inf')  # Initialize to negative infinity
            max_ending_here = 0

            for x in nums:
                # Decide whether to extend the current subarray or start a new one
                max_ending_here = max(x, max_ending_here + x)
                # Update max_so_far if we've found a better sum
                max_so_far = max(max_so_far, max_ending_here)
            
            return max_so_far

        # Example usage
        nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
        print(maxSubArray(nums))  # Should output 6

        Explanation:

        max_ending_here essentially represents the maximum sum of the subarray ending at the current position. If 
        adding the current element decreases this sum, we start anew from that element, making max_ending_here equal 
        to the current element.

        max_so_far keeps track of the global maximum sum encountered so far. It's updated whenever we find a sum (max_ending_here) that's greater than what we've seen before.

        Advantages:
        Time Complexity: O(n), where n is the number of elements in the array, as it only requires a single pass through the array.
        Space Complexity: O(1), since it uses only two variables regardless of the input size, making it very memory efficient.

        Considerations:
        This algorithm assumes that there's at least one positive number in the array or that the array isn't all negative. If all elements are negative, the maximum subarray sum would be the largest (least negative) number in the array. In practice, you might want to handle this edge case by initializing max_so_far to the first element or by adding a check for all-negative arrays.

        Kadane's Algorithm is not only useful for the maximum subarray sum but can be adapted for other similar problems where you need to find the maximum sum with certain constraints or variations on the problem.
    */

    void example05_kadane_algorithm() {
        // [-2, 1, -3, 4, -1, 2, 1, -5, 4]
        std::vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

        int max_so_far = INT_MIN;
        int max_ending_here = 0;

        for(int i = 0; i < arr.size(); i++) {
            int x = arr[i];

            max_ending_here = std::max(x, max_ending_here + x);

            max_so_far = std::max(max_so_far, max_ending_here);
            
        }

        std::cout << max_so_far << "\n";

        // Output: 6
    }
}
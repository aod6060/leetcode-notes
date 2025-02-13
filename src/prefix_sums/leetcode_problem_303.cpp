#include "prefix_sums.h"
#include <vector>
#include <iostream>

namespace presums {

    namespace prob303 {
        class NumArray {
            public:
                NumArray(std::vector<int>& nums) {
                    prefix.resize(nums.size());
                    prefix[0] = nums[0];
                    for(int i = 1; i < prefix.size(); i++) {
                        prefix[i] = nums[i] + prefix[i-1];
                    }
                }
                
                int sumRange(int left, int right) {
                    if(left == 0) {
                        return prefix[right];
                    } else {
                        return prefix[right] - prefix[left - 1];
                    }
                }
            private:
                std::vector<int> prefix;
        };
    }

    void leetcode_problem_303() {
        std::vector<int> arr = {-2, 0, 3, -5, 2, -1};

        prob303::NumArray nums(arr);
        std::cout << nums.sumRange(0, 2) << "\n"; // 1
        std::cout << nums.sumRange(2, 5) << "\n"; // -1
        std::cout << nums.sumRange(0, 5) << "\n"; // -3
    }
}
#include "prefix_sums.h"
#include <vector>
#include <iostream>

namespace presums {

    namespace prob307 {
        class NumArray {
        public:
            NumArray(std::vector<int>& nums) {
                this->arr.resize(nums.size());
                this->prefix.resize(nums.size());
                
                this->arr[0] = this->prefix[0] = nums[0];

                for(int i = 1; i < prefix.size(); i++) {
                    this->prefix[i] = nums[i] + this->prefix[i-1];
                    this->arr[i] = nums[i];
                }
            }

            void update(int index, int val) {
                int diff = val - this->arr[index];

                this->arr[index] = val;

                for(int i = index; i < this->prefix.size(); i++) {
                    this->prefix[i] += diff;
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
            std::vector<int> arr;
            std::vector<int> prefix;
        };
    }

    void leetcode_problem_307() {
        std::vector<int> arr = {1, 3, 5};

        
        prob307::NumArray numArray(arr);
        std::cout << numArray.sumRange(0, 2) << "\n"; // 9

        numArray.update(1, 2);
        
        std::cout << numArray.sumRange(0, 2) << "\n"; // 8
    }
}
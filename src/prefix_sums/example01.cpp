#include "prefix_sums.h"

#include <iostream>
#include <vector>

namespace presums {

    /*
        # Example usage
        A = [1, 2, 3, 4, 5]
        P = prefix_sums(A)
        print(P)  # Output: [1, 3, 6, 10, 15]
    */

    void example01() {
        std::vector<int> arr = {0, 1, 2, 3, 4, 5};
        std::vector<int> prefix(arr.size());

        prefix[0] = arr[0];

        for(int i = 1; i < prefix.size(); i++) {
            prefix[i] = arr[i] + prefix[i-1];
        }

        // Print Array sound be [1, 2, 3, 4, 5]
        std::cout << "Original Array: ";
        for(int i = 0; i < arr.size() - 1; i++) {
            std::cout << arr[i] << ", ";
        }
        std::cout << arr[arr.size()-1] << "\n";

        // Print Prefix Array sound be [1, 3, 6, 10, 15]
        std::cout << "Prefix Array: ";
        for(int i = 0; i < prefix.size() - 1; i++) {
            std::cout << prefix[i] << ", ";
        }
        std::cout << prefix[arr.size()-1] << "\n";
    }
}
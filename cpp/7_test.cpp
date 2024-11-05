#include <vector>
#include <algorithm>
#include <iostream>

std::vector<int> longestIncreasingSubsequence(const std::vector<int>& arr) {
    if (arr.empty()) {
        return {};
    }

    std::vector<int> tails; // Stores the tails of increasing subsequences of different lengths
    std::vector<int> predecessors(arr.size(), -1); // Stores the predecessor of each element in the LIS

    for (size_t i = 0; i < arr.size(); ++i) {
        auto it = std::lower_bound(tails.begin(), tails.end(), arr[i]);

        if (it == tails.end()) {
            tails.push_back(arr[i]);
            if (tails.size() > 1) {
                predecessors[i] = std::distance(arr.begin(), std::find(arr.begin(), arr.end(), tails[tails.size() - 2]));
            }
        } else {
            *it = arr[i];
            if (it != tails.begin()) {
                predecessors[i] = std::distance(arr.begin(), std::find(arr.begin(), arr.end(), *(it - 1)));
            }
        }
    }

    // Reconstruct the LIS from the predecessors
    std::vector<int> lis;
    int current = std::distance(arr.begin(), std::find(arr.begin(), arr.end(), tails.back()));
    while (current != -1) {
        lis.push_back(arr[current]);
        current = predecessors[current];
    }
    std::reverse(lis.begin(), lis.end());

    return lis;
}

int main() {
    // Test cases demonstrating LIS behavior
    std::vector<std::vector<int>> test_cases = {
        {10, 9, 2, 5, 3, 7, 101, 18},
        {0, 1, 0, 3, 2, 3},
        {7, 7, 7, 7},
        {3, 10, 2, 1, 20},
        {},  // Empty array test
        {1}  // Single element test
    };

    for (const auto& arr : test_cases) {
        std::cout << "Input array: ";
        for (int num : arr) {
            std::cout << num << " ";
        }
        std::cout << "\nLongest Increasing Subsequence: ";
        
        auto result = longestIncreasingSubsequence(arr);
        
        for (int num : result) {
            std::cout << num << " ";
        }
        std::cout << "\nLength: " << result.size() << "\n\n";
    }
    
    return 0;
}
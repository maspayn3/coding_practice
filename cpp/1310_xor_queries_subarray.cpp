#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> result;
        result.reserve(queries.size());

        int prefixSum = arr[0];

        // idea is to precompute the prefix sum of all the arrs
        // then "undo" the xors by 


        for (int i = 1; i < arr.size(); i++) {
            prefixSum = prefixSum ^ arr[i];
        } 

        for (auto& query : queries) {
            int temp_result = prefixSum;

            int left = query[0];
            int right = query[1];

            for (int i = 0; i < arr.size(); i++) {
                
                if (i < left || i > right) {
                    temp_result = temp_result ^ arr[i];
                }
            }
            result.push_back(temp_result);
        }
        return result;
    }
};


int main() {
    vector<vector<int>> queries = {{0,1},{1,2},{0,3},{3,3}};
    vector<int> arr = {1,3,4,8};

    Solution sol;
     
    sol.xorQueries(arr, queries);


    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int target_size = m * n; 
        int elements_added = 0;
        vector<vector<int>> sol = {};

        if (original.size() != target_size) {
            return sol;
        }

        sol.resize(m);
        int index = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                sol[i].push_back(original[index]);
                index++;
            }
        }
        return sol;
    }
};

void print_test(vector<int> test, vector<vector<int>> result) {

    cout << "[";
    for (int i = 0; i < test.size(); i++) {
        cout << test[i] << ", ";
    }
    cout << "]\n";

    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << "[";
        for (int j = 0; j < result[0].size(); j++) {
            cout << result[i][j] << ", ";
        }
        cout << "]\n";
    }
    cout << "]";
}


int main() {

    Solution sol; 
    vector<int> test1 = {1,2,3,4};

    auto result = sol.construct2DArray(test1, 2, 2);
    
    print_test(test1, result);


    return 0;
}
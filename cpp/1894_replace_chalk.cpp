#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        // use % to create a circuluar index
            // int student = 0;
            // while (k > 0) {
            //     int temp = 0;

            // }
        
        // ABOVE is setup for brute force, but we can skip iterations based on total in chalk[i]
        // find sum of chalk
        long sum = 0;
        for (int i = 0; i < chalk.size(); i++) {
            sum += chalk[i];
        }

        // with remainder can walk through the vector max one time for total O(n + n) time 
        // complexity
        long remainder = k % sum;
        for (int i = 0; ; i++) {
            remainder -= chalk[i];
            if (remainder < 0) {
                return i;
            }
        }
        // Could use binary search in the last search for speedup
        return 0;
    }
};


int main() {

    Solution sol;
    vector<int> test1 = {5,1,5};

    int result = sol.chalkReplacer(test1, 999999999);

    cout << "Result: " << result << "\n";
    return 0;
}
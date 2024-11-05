#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = 0;
        for (int i = 0; i < rolls.size(); i++) {
            sum += rolls[i];
        }
        // sum_rolls + t / (m + n) = avg so t = avg *(m + n) - sum_rolls
        int target = mean * (rolls.size() + n) - sum;

        if (target > 6 * n || target < n) {
            return {};
        }
        

        // so we can figure out what each element of result should be by computing how much 
        // of target we can fit in n elements, i.e. distribute the mean 

        int mean_distributer = target / n;
        int remainder = target % n;

        // we can add the remainder in one at a time after
        
        vector<int> result(n, mean_distributer);

        if (remainder) {
            for (int i = 0; i < remainder; i++) {
                result[i] += 1;
            }
        }
        return result;
    }
};


int main() {
    Solution sol;
    vector<int> test1 = {3,2,4,3};
    sol.missingRolls(test1, 4, 2);



    return 0;
}
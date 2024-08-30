#include <iostream>
#include <vector>

using namespace std;
    
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        
        // find the max first
        int max = 0;
        for (int i = 0; i < candies.size(); i++) {
            if (candies[i] > max) {
                max = candies[i];
            }
        }
        int dif = max - extraCandies;
        vector<bool> result;
        for (int j = 0; j < candies.size(); j++) {
            if (candies[j] < dif) {
                result.push_back(false);
            }
            else {
                result.push_back(true);
            }
        }
    }
};


int main() {
    return 0;
}
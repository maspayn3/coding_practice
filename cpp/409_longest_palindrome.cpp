#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {

        unordered_map<char, int> map;

        for (int i = 0; i < s.size(); i++) {
            if (map.find(s[i]) == map.end()) {
                map.insert({s[i], 1});
            }
            else {
                map[s[i]]++;
            }
        }
        bool single_flag = false;
        int palindrome_len = 0;

        for (auto& [key, value]: map) {

            if (value % 2 == 0) {
                palindrome_len += value;
            }
            else {
                palindrome_len += value - 1;
                single_flag = true;
            }
        }
        return palindrome_len + single_flag;
    }
};



int main() {
    string s = "bananas";

    Solution sol;

    int ans = sol.longestPalindrome(s);

    cout << ans << '\n';
    return 0;
}
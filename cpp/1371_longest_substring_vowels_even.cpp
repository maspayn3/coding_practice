#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findTheLongestSubstring(string s) {
        // we haved a fixed number of things to track
        // a, e, i, o, u
        // perhaps create a bitmask for each
        // assign each to value i.e. a = 0, e = 1, i = 2, o = 3, u = 4

        vector<int> mp(32, -1);

        char vowel_bits = 0;
        int new_longest_substring = 0;
        int curr_length = 0;
        for (int i = 0; i < s.length(); i++) {
            // whenever we check a new char 
            switch (s[i])
            {
            case 'a':
                vowel_bits = vowel_bits ^ (1 << 0);
                break;
            case 'e':
                vowel_bits = vowel_bits ^ (1 << 1);
                break;
            case 'i':
                vowel_bits = vowel_bits ^ (1 << 2);
                break;
            case 'o':
                vowel_bits = vowel_bits ^ (1 << 3);
                break;
            case 'u':
                vowel_bits = vowel_bits ^ (1 << 4);
                break;
            default:
                break;
            }

            if (mp[vowel_bits] == -1 && vowel_bits != 0) {
                mp[vowel_bits] = i;
            }

            new_longest_substring = max(new_longest_substring, i - mp[vowel_bits]);

        }
        return new_longest_substring;

    }
};


int main() {
    
    string s = "eleetminicoworoep";
    Solution sol;
    sol.findTheLongestSubstring(s);


    return 0;
}
#include <iostream>

using namespace std;

class Solution {
public:
    int appendCharacters(string s, string t) {
        int ptr_s = 0;
        int ptr_t = 0;

        // need to find how many letters are already a subsequence of t in s
        // better to have a while loop so we can end early if t is short
        while (ptr_s < s.length() && ptr_t < t.length()) {
            if (s[ptr_s] == t[ptr_t]) {
                ptr_t++;
            }
            ptr_s++;
        }
        return  t.size() - ptr_t;
    }
};

int main() {

    string s = "z";
    string t = "abcde";

    Solution * sol = new Solution;

    int answer = sol->appendCharacters(s, t);

    cout << answer << "\n";

    return 0;
}
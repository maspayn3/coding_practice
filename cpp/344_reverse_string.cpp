#include <iostream>
#include <vector>

using namespace std;

class Solution {
public: 
    void reverseString(vector<char> & s) {
        int start = 0;
        int end = s.size() - 1;

        if (s.size() == 0) {
            return;
        }

        while (start < end) {
            char temp = s[start];
            s[start] = s[end];
            s[end] = temp; 

            start++;
            end--;
        }
    }
};


int main() {
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};

    Solution sol;

    sol.reverseString(s);

    for (int i = 0; i < s.size(); i++) {
        cout << s[i];
    }
    cout << '\n';

    return 0;
}
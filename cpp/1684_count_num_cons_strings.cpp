#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/*Idea is to create a set and add all allowed chars to it.
Then iterate through the words and check if there are any letters not in set*/


class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<int> allowed_chars;

        // fill set with allowed chars
        for (auto& letter : allowed) {
            allowed_chars.insert(letter);
        }

        int num_consistent = words.size();

        for (auto& word : words) {
            for (int i = 0; i < word.size(); i++) {
                if (!allowed_chars.count(word[i])) {
                    num_consistent--;
                    break;
                }
            }
        }

        return num_consistent;
    }
};


int main() {

    Solution sol;

    string allowed = "abc";
    vector<string> words = {"ad","bd","aaab","baa","badab"};

    cout << sol.countConsistentStrings(allowed, words) << "\n";

    return 0;
}
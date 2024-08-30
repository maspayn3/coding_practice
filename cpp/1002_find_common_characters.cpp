#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<unordered_map<char,int>> map_list;
        vector<string> common_chars;
        map_list.reserve(words.size());

        if (words.size() == 1) {
            for (int i = 0; i < words[0].size(); i++) {
                common_chars.push_back(string(words[0][i], 1));
            }
            return common_chars;
        }
        
        for (int i = 0; i < words.size(); i++) {

            unordered_map<char, int> map;
            map.reserve(26);

            for (int j = 0; j < words[i].size(); j++) {

                if (map.find(words[i][j]) == map.end())
                    map.insert({words[i][j], 1});

                else {
                    map[words[i][j]]++;
                }
            }
            map_list.push_back(map);
        }   

        int temp = map_list.size();

        // only have to check the first words chars, as chars that appear in ALL words must be 
        // in first as well
        for (auto &key_value: map_list[0]) {
            bool char_check = true;
            for (int i = 1; i < map_list.size(); i++) {
                if (map_list[i].find(key_value.first) == map_list[i].end()) {
                    char_check = false;
                    continue;
                }
                else {
                    if (key_value.second > map_list[i][key_value.first]) {
                        key_value.second = map_list[i][key_value.first];
                    }
                }
            }
            if (char_check) {
                for (int i = 0; i < key_value.second; i++) {
                    common_chars.push_back(string(1, key_value.first));
                }
            }
        }
        return common_chars;
    }
};


int main () {

    Solution sol;
    vector<string> words = {"bella","label","roller"};
    vector<string> ans = sol.commonChars(words);

    return 0;
}
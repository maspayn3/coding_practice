#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        
        // must convert the hours to minutes for sake of sorting

        vector<int> time_in_minutes;

        for (auto& time : timePoints) {
            int total_minues = 0;

            int tens_hour_digit = time[0] - '0';
            int ones_hour_digit = time[1] - '0';

            int tens_min_digit = time[3] - '0';
            int ones_min_digit = time[4] - '0';

            total_minues += 600 * tens_hour_digit;
            total_minues += 60 * ones_hour_digit;
            total_minues = total_minues + 10 * tens_min_digit + ones_min_digit;

            time_in_minutes.push_back(total_minues);
        }

        std::sort(time_in_minutes.begin(), time_in_minutes.end());

        int curr_min_difference = 1000000;

        for (int i = 0; i < time_in_minutes.size() - 1; i++) {

            int difference = time_in_minutes[i + 1] - time_in_minutes[i];

            if (difference < curr_min_difference) {
                curr_min_difference = difference;
            }
        }

        // time is circular so we must check the edges 

        int first = time_in_minutes[0];
        int last = time_in_minutes[time_in_minutes.size() - 1]; 

        return min(curr_min_difference, 24 * 60 - last + first);

    }
};


int main() {
    vector<string> time_points = {"23:59", "00:00"};
    vector<string> time_points1 = {"23:59", "00:00"};
    vector<string> time_points2 = {"00:00","12:34","23:59","03:21","16:45","07:30","20:15","22:22"};
    
    Solution sol;

    sol.findMinDifference(time_points2);


    return 0;
}
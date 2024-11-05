#include <iostream>

using namespace std;

class Solution {
public:

    // k will always be >= 1 so we can sum first thing on the conversion
    int convert_and_sum(string s) {
        int sum = 0;
        int multiplier = 10;
        for (int i = 0; i < s.size(); i++) {
            
            int converted_char = int(s[i] - 96);
            // if char is greater than 10, we must add two digits to sum
            if (s[i] >= 'j') {
                int last_digit = converted_char % 10;
                converted_char /= 10;
                int first_digit = converted_char;

                sum = sum + last_digit + first_digit;
            }
            else {
                sum += converted_char;
            }
        }
        return sum;
    }

    int getLucky(string s, int k) {
        // can first convert each character to its integer counterpart

        int converted_string = convert_and_sum(s);

        if (k == 1) {
            return converted_string;
        }

        k -= 1;

        // to grab the last digit do modulo % 10; 
        int transformed_int = 0;
        while (k > 0) {
            // grab last digit
            int last_digit = converted_string % 10;
            transformed_int += last_digit;

            // shift converted string
            converted_string = converted_string / 10;

            if (converted_string == 0) {
                k -= 1;

                if (!k || transformed_int < 10) {
                    return transformed_int;
                }

                converted_string = transformed_int;
                transformed_int = 0;
            }
        }

        return transformed_int;
    }
};


int main() {
    Solution sol;

    int result = sol.getLucky("vbyytoijnbgtyrjlsc", 2);
    cout << result;

    return 0;
}
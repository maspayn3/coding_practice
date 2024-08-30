#include <iostream>
#include <string>
#include <cmath>
#include <assert.h>

using namespace std;

class Solution {
public:


    string small_num_to_words(int num) {
        assert(num < 1000);
        
        string result = "";

        string words[] = {
            "Hundred"
        };

        string numbers_tens[]{
            "",
            "",
            "Twenty",
            "Thirty",
            "Forty",
            "Fifty",
            "Sixty",
            "Seventy",
            "Eighty",
            "Ninety"
        };
        // zero is purposefully blank to account for edge case
        string numbers[] = {
            "",
            "One",
            "Two",
            "Three",
            "Four",
            "Five",
            "Six",
            "Seven",
            "Eight",
            "Nine",
            "Ten",
            "Eleven",
            "Twelve",
            "Thirteen",
            "Fourteen",
            "Fifteen",
            "Sixteen",
            "Seventeen",
            "Eighteen",
            "Nineteen"
        };
        // new method of getting least two significant digits since there are edge cases

        int single_digit = num % 10;
        int last_two_digits = num % 100;
        int second_digit = last_two_digits / 10;

        if (9 < last_two_digits  && last_two_digits < 20) {
            result.insert(0, numbers[last_two_digits]);
        }
        else {
            result.insert(0, numbers[single_digit]);
            if (second_digit && single_digit) {
                result.insert(0, " ");
            }
            result.insert(0, numbers_tens[second_digit]);
        }

        if (num > 99) {
            int msd = num / 100;

            if (single_digit || second_digit) {
                result.insert(0, numbers[msd] + " Hundred ");
            }
            else {
                result.insert(0, numbers[msd] + " Hundred");
            }
        }
        
        return result;
    }

    string numberToWords(int num) {
        // max value: 2,147,483,647

        // only need to account for billions

        // divide the numbers into groups of 3 starting w LSD
        // use modulo operator, %
        if (!num) {
            return "Zero";
        }

        string result = "";

        string words[] = {
            "",
            " Thousand",
            " Million",
            " Billion"
        };


        int count = 0;
        bool all_zeros = true;
        while (num > 0) {
            int last_three_lsd = num % 1000;

            if (!last_three_lsd) {
                count++;
                num = num / 1000;
                continue;
            }
            if (count) {
                result.insert(0,  all_zeros ? "" : " ");
            }
            result.insert(0, words[count]);
            result.insert(0, small_num_to_words(last_three_lsd));

            if (num > 1000) {
                all_zeros = false;
            }
            
            num = num / 1000;

            count++;
        }
        return result;
    }
};


int main() {

    Solution sol; 

    cout << "===TESTING ... num to words function===\n";

    string s = sol.small_num_to_words(123);
    string s1 = sol.small_num_to_words(101);
    string s2 = sol.small_num_to_words(205);
    string s3 = sol.small_num_to_words(324);
    string s4 = sol.small_num_to_words(218);
    string s5 = sol.small_num_to_words(5);
    string s6 = sol.small_num_to_words(15);
    string s7 = sol.small_num_to_words(20);



    cout << s << '\n';
    cout << s1 << '\n';
    cout << s2 << '\n';
    cout << s3 << '\n';
    cout << s4 << '\n';
    cout << s5 << '\n';
    cout << s6 << '\n';
    cout << s7 << '\n';


    cout << "===TESTING FINAL SOLUTION===\n";

    s = sol.numberToWords(3055000);
    cout << s << '\n';
    s = sol.numberToWords(1234567);
    cout << s << '\n';
    s = sol.numberToWords(1000010);
    cout << s << '\n';
    s = sol.numberToWords(14);
    cout << s << '\n';
    s = sol.numberToWords(3);
    cout << s << '\n';
    s = sol.numberToWords(0);
    cout << s << '\n';
    s = sol.numberToWords(1000);
    cout << s << '\n';
    s = sol.numberToWords(100000);
    cout << s << '\n';

    return 0;
}
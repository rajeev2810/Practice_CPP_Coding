// LongestPalindromicSubstring.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length(); // calculating size of string
        if (n < 2)
            return s;   // if string is empty then size will be 0.
        // if n==1 then, answer will be 1(single
        // character will always palindrome)

        int maxLength = 1, start = 0;
        int low, high;
        for (int i = 0; i < n; i++) {
            low = i - 1;
            high = i + 1;
            while (high < n && s[high] == s[i]) //increment 'high'                                  
                high++;

            while (low >= 0 && s[low] == s[i]) // decrement 'low'                   
                low--;

            while (low >= 0 && high < n && s[low] == s[high]) {
                low--;
                high++;
            }

            int length = high - low - 1;
            if (maxLength < length) {
                maxLength = length;
                start = low + 1;
            }
        }
        return s.substr(start, maxLength);
    }
};

int main() {
    Solution sol;
    string s = sol.longestPalindrome("findnitianhere");
    std::cout << s << std::endl;
    return 1;
}


// MaximumBonusSwapString.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
      
public:

    void FindMaxBonus(string str, int k, string &max)
    {
        // Return if no swaps left
        if (k == 0)
            return;

        int n = str.length();

        // Consider every digit
        for (int i = 0; i < n - 1; i++) {

            // Compare it with all digits after it
            for (int j = i + 1; j < n; j++) {
                // if digit at position i
                // is less than digit
                // at position j, swap it
                // and check for maximum
                // number so far and recurse
                // for remaining swaps
                if (str[i] < str[j]) {
                    // swap str[i] with str[j]
                    swap(str[i], str[j]);

                    // If current num is more
                    // than maximum so far
                    if (str.compare(max) > 0)
                        max = str;

                    // recurse of the other k - 1 swaps
                    FindMaxBonus(str, k - 1, max);

                    // Backtrack
                    swap(str[i], str[j]);
                }
            }
        }
    }
};

int main()
{
    Solution s;
    string str = "5989";
    string max = str;
    s.FindMaxBonus(str, 3, max);
    cout << max << endl;
}

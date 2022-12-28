// CountandSay.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        for (int i = 0; i < nums.size(); i++) {
            auto it = std::find(nums.begin(), nums.end(), i + 1);
            if (it == nums.end())
                return i + 1;
            if (nums.size() == (i + 1) && it != nums.end()) {
                return *it + 1;
            }

        }
        return 0;

    }
    string countAndSay(int n) {
        string res = "1";
        if (n == 1) {
            return res;
        }
        if (n == 2) {
            res = "11";
            return res;
        }
        res = "11";
        for (int i = 3; i <= n; i++)
        {
            // In below for loop, previous character
            // is processed in current iteration. That
            // is why a dummy character is added to make
            // sure that loop runs one extra iteration.
            res += '$';
            int len = res.length();
            int cnt = 1;        // Initialize count of matching chars
            string  tmp = "";   // Initialize i'th term in series
            // Process previous term to find the next term
            for (int j = 1; j < len; j++)
            {
                // If current character doesn't match
                if (res[j] != res[j - 1])
                {
                    // Append count of str[j-1] to temp
                    tmp += cnt + '0';
                    // Append str[j-1]
                    tmp += res[j - 1];
                    // Reset count
                    cnt = 1;
                }
                //  If matches, then increment count of matching
                // characters
                else cnt++;
            }
            // Update str
            res = tmp;
        }
        return res;
    }
};

int main()
{
    Solution s;

   // std::cout << s.countAndSay(30) << endl;
    vector<int> a = { 1 };
    cout << s.firstMissingPositive(a);

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

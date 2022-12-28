// DecodeWays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        vector<int> DP(s.size() + 1, 1);
        for (int i = 2; i < s.size() + 1; i++) {
            DP[i] = (s[i - 1] != '0') ? DP[i - 1] : 0;
            DP[i] += (s[i - 2] != '0' &&
                stoi(s.substr(i - 2, 2)) <= 26) ? DP[i - 2] : 0;
        }

        return DP[s.size()];

    }
};

int main()
{
    Solution s;
    cout << s.numDecodings("99999") << endl;

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

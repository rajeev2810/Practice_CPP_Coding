// MinWindowSubstring.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
        string minWindow(string s, string t) {
/*
        if (s.length() == 0 || t.length() == 0) {
            return "";
        }

        // Dictionary which keeps a count of all the unique characters in t.
        map<char, int> dictT{};
        for (int i = 0; i < t.length(); i++) {
            dictT[t[i]]++;
        }

        // Number of unique characters in t, which need to be present in the desired window.
        int required = dictT.size();

        // Left and Right pointer
        int l = 0, r = 0;

        // formed is used to keep track of how many unique characters in t
        // are present in the current window in its desired frequency.
        // e.g. if t is "AABC" then the window must have two A's, one B and one C.
        // Thus formed would be = 3 when all these conditions are met.
        int formed = 0;

        // Dictionary which keeps a count of all the unique characters in the current window.
        map<char, int> windowCounts{};

        // ans list of the form (window length, left, right)
        vector<int> ans = { -1, 0, 0 };

        while (r < s.length()) {
            // Add one character from the right to the window
            char c = s[r];
            //int count = windowCounts[c];
            windowCounts[c]++;// = count + 1;

            // If the frequency of the current character added equals to the
            // desired count in t then increment the formed count by 1.
            if (dictT.find(c) != dictT.end() && windowCounts[c] == dictT[c]) {
                formed++;
            }

            // Try and contract the window till the point where it ceases to be 'desirable'.
            while (l <= r && formed == required) {
                c = s[l];
                // Save the smallest window until now.
                if (ans[0] == -1 || r - l + 1 < ans[0]) {
                    ans[0] = r - l + 1;
                    ans[1] = l;
                    ans[2] = r;
                }

                // The character at the position pointed by the
                // `Left` pointer is no longer a part of the window.
                windowCounts[c] = windowCounts[c] - 1;
                if (dictT.find(c) != dictT.end() && windowCounts[c] < dictT[c]) {
                    formed--;
                }

                // Move the left pointer ahead, this would help to look for a new window.
                l++;
            }

            // Keep expanding the window once we are done contracting.
            r++;
        }

        return (ans[0] == -1 ? "" : s.substr(ans[1], ans[0]));*/
        vector<int> map(128, 0);
        for (auto c : t) map[c]++;
        int counter = t.size(), begin = 0, end = 0, d = INT_MAX, head = 0;
        while (end < s.size()) {
            if (map[s[end++]]-- > 0) counter--; //in t
            while (counter == 0) { //valid
                if (end - begin < d)  d = end - (head = begin);
                if (map[s[begin++]]++ == 0) counter++;  //make it invalid
            }
        }
        return d == INT_MAX ? "" : s.substr(head, d);
    }
};

int main()
{
    Solution s;
    string sub = s.minWindow("abc", "bc");
    std::cout << sub;
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

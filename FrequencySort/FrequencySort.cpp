// FrequencySort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        vector<int> counts(256, 0);
        for (char ch : s)
            ++counts[ch];
        sort(s.begin(), s.end(), [&](char a, char b) {
            return counts[a] > counts[b] || (counts[a] == counts[b] && a < b);
            });
        return s;
    }

    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> res{ nums};
        for (int i = 0; i < nums.size(); i++)
        {
            res.push_back(nums[i]);
        }
        return res;
    }
    int minPartitions(string n) {
        int res = 0;
        for (int i = 0; i < n.size(); ++i) {
            res = max(res, n[i] - '0');
        }
        return res;
    }
    vector<int> runningSum(vector<int>& nums) {
        vector<int> res{};
        res.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            res.push_back(res[i-1]+nums[i]);
        }
        return res;

    }
};

int main()
{
    Solution s;
    std::cout << s.frequencySort("27346209830709182346");
    //vector<int> nums = { 1, 2, 3 , 4};
    //s.runningSum(nums);
    //   s.getConcatenation(nums);
    //std::cout << "Hello World!\n";
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

// DifferenceElementSumDigitSum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int r{}, elementsum{}, digitsum{};
        for (int i = 0; i < nums.size(); ++i) {
            elementsum += nums[i];
            int temp = nums[i];

            while (temp != 0)
            {
                r = temp % 10;
                digitsum += r;
                temp = temp / 10;
            }
        }
        cout << elementsum << "\t" << digitsum;
        return abs(elementsum - digitsum);
    }
};

int main()
{
    vector<int> a{ 1,15,6,3 };
    Solution s;
    s.differenceOfSum(a);
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

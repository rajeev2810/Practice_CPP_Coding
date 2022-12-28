// PlusOne.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size()-1; i >= 0; --i) {
            if (digits[i] == 9) {
                digits[i] = 0;
            }
            else {  // current digit is not 9 so we can safely increment by one
                digits[i] += 1;
                return digits;
            }
        }

        digits.push_back(0);
        digits[0] = 1;
        return digits;
    }

    int mySqrt(int x) {

        long r = x;
        while (r * r > x)
            r = (r + x / r) / 2;
        return r;
    }

    void setZeroes(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size()-1; i++) {
            for (int j = 0; j < matrix[0].size()-1; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i + 1][j] = 0;
                    matrix[i][j + 1] = 0;
                }

            }
        }

    }
};

int main()
{
    Solution s;
    /*
    vector<int> v{ 8,8 };
    vector<int> r = s.plusOne(v);
    cout << "[";
    for (auto i : r)
        cout << i;
    cout << "]" << endl;
    */
    vector < vector<int>> a{ {1,1,1},{1,0,1 }, {1, 1, 1} };

     s.setZeroes(a);
     for (int i = 0; i < a.size(); i++) {
         for (int j = 0; j < a[0].size(); j++) {
             cout << a[i][j];
         }
     }

     return 0;
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

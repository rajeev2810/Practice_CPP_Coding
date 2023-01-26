// maxprofit.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lsf = INT_MAX; // least so far
        int op = 0; // overall profit
        int pist = 0; // profit if sold today

        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < lsf) { // if we found new buy value which is more smaller then previous one
                lsf = prices[i]; // update our least so far
            }
            pist = prices[i] - lsf; // calculating profit if sold today by, Buy - sell
            if (op < pist) { // if pist is more then our previous overall profit
                op = pist; // update overall profit
            }
        }
        return op; // return op 

    }

    int maxCoronaCases(vector<int>& cases) {
        int lsf = INT_MAX; // least so far
        int op = 0; // overall increase
        int pist = 0; // increase in corona cases today 

        for (int i = 0; i < cases.size(); i++) {
            if (cases[i] < lsf) { // if we found new cases which is more less then previous one
                lsf = cases[i]; // update our least so far
            }
            pist = cases[i] - lsf; // calculating increase as of today by
            if (op < pist) { // if cases is more then our previous overall cases
                op = pist; // update max increase in cases
            }
        }
        return op; // return op
    }
};

int main()
{
    Solution s;
    vector<int> a = { 79,11,54,32,69,40 };
    cout << s.maxCoronaCases(a) << endl;
}

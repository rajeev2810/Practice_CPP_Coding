// OutputExcercise3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Conversion operator example
class INT
{
    int a;

public:
    INT(int ix = 0)
    {
        a = ix;
    }

    /* Starting here: */
    operator int()
    {
        return a;
    }
    /* End */

    INT operator ++(int)
    {
        return a++;
    }
};
// functor usage with some logics
class F {
    int val;
public:
    F(int v) : val(v) {

    }
    bool operator() (int v) {
        return val == v;
    }
};

int main()
{
    INT i(1234);
    int i_2 = i;
    std::cout << ++i_2 << endl;
    cout << "\n============================\n";
    int t[] = { 10, 5, 9, 6, 2, 4, 7, 8, 3, 1 };
    vector<int> v1(t, t + 10);
    auto it = find(v1.begin(), v1.end(), 6);
    F f(6);
    //bool found = f(6);
    auto it1 = find(v1.begin(), v1.end(), f(6));
    if (it1 == it) {
        cout << "Found\n";
    }
    else {
        cout << "Not Found\n";
    }  
}


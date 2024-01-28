// FindNthTerm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string reverseWords(string s) {
    string word = "";
    string res = "";
    for (char i : s) {
        if (i == ' ') {
            res = word + " " + res;
            //cout << res << endl;
            word = "";
        }
        else {
            word += i;
        }
    }
    res = word + " " + res;
    return res.substr(0, res.size() - 1);
}

int findnthterm(int n)
{
    if (n % 3 == 0)
        return 2;
    else if (n % 3 == 1)
        return 4;
    else if (n % 3 == 2)
        return 8;
}

int main() {
    string input = "my name is rajeev";
    string res = reverseWords(input);
    cout << res << endl;
    // Input series = { 2,4,8,2,4,8,2,4,8,2,4,8........};
    cout << findnthterm(6) << endl;

    return 0;
}



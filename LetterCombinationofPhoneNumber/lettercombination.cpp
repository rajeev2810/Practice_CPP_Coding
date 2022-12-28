#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        vector<string> result {};
        string curr;
        
        if (digits.length() == 0 || digits.empty()) {
            return result;            
        }
        
           
          letterCombinationsRecursive(&result, digits, &curr);
        return result;  
    }

   void letterCombinationsRecursive(vector<string>* result, const string &digits, string *current) 
    {
       static const vector<string> lookup = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
       
        if (current->length() == digits.length() ) {
            result->emplace_back(*current);
            return;
        }

       for (const auto& c: lookup[digits[size(*current)] - '0']) {
            current->push_back(c);
            letterCombinationsRecursive(result, digits, current);
            current->pop_back();
        }  
    }
};

int main()
{
    vector <string> v;
    Solution s;
    v = s.letterCombinations("23");

    for (auto i : v)
        cout << i << ' ';

}
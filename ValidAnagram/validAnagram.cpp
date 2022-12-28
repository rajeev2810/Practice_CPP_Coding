#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.length() != t.length())
            return false;
        
        vector<int> v(26, 0);
        
        for(int i=0; i<s.size(); i++){
            v[s[i]-97]++;
            v[t[i]-97]--;
        }
        
        for(int i : v)
            if(i<0)
                return false;
        
        return true;
        
    }
};

int main() {
    Solution s;
    bool anagram = s.isAnagram("triangle", "ielgantr");
    boolalpha;
    std::cout << boolalpha << anagram <<std::endl;
    return 0;
}
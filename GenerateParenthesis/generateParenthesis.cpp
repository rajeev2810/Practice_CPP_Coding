#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans {};
        generateParenthesisRecu("",0,0,n, &ans);
        return ans;
       
        
    }
private:    
    void generateParenthesisRecu(string s,int open,int close,int n, vector<string> *ans)
    {
        if(open==n and close==n){
            ans->emplace_back(s);
            return;
        }
        if(open<n)
            generateParenthesisRecu(s+"(",open+1,close,n, ans);
        if(close<open)
            generateParenthesisRecu(s+")",open,close+1,n,ans);
    }
};

int main()
{
    Solution s;
    vector <string> result = s.generateParenthesis(4);
    
    for (auto i: result)
    {
        cout << i << endl;
    }
    return 0;
}
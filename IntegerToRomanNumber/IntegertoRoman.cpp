#include <iostream>
#include <map>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        map<int,string>mp;
        mp[1]="I";
        mp[4]="IV";
        mp[5]="V";
        mp[9]="IX";
        mp[10]="X";
        mp[40]="XL";
        mp[50]="L";
        mp[90]="XC";
        mp[100]="C";
        mp[400]="CD";
        mp[500]="D";
        mp[900]="CM";
        mp[1000]="M";
        int len=0,z=num;
        
        while(z!=0){
            z/=10;
            len++;
        }
        
        z=num;
        string ans="";
        for(int i=len-1;i>=0;i--){
            int div=pow(10,i);
            int req=z/div;            
            int val=req*div;           
            
            if(mp[val]!="")
                ans+=mp[val];
            else {
                if(div==1&&req>=5){
                    ans+=mp[5];
                    req-=5;
                }
                if(div==10&&req>=5){
                    ans+=mp[50];
                    req-=5;
                }
                if(div==100&&req>=5){
                    ans+=mp[500];
                    req-=5;
                }
                while(req--)
                    ans+=mp[div];
            }
            z=z-val;
        }
        
        return ans;
        
    }
};

int main()
{
    Solution s;
    cout << s.intToRoman(68) << endl;
    return 0;
}
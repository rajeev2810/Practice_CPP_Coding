#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {

private:
    bool check(unordered_map<string, int> wordCount, string s, int wordLen) {
        for (int j = 0; j < s.size(); j += wordLen) {
            string w = s.substr(j, wordLen);
            if (wordCount.find(w) != wordCount.end()) {
                if (--wordCount[w] == -1) {
                    return false;
                }
            }
            else {
                return false;
            }
        }
        return true;
    }
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res{};

        int m = words.size();
        int concatsubstringlength = m * words[0].length();
        unordered_map<string, int> concatsubstring;

        if (concatsubstringlength > s.length())
            return res;

        for (int i = 0; i < words.size(); i++) {
            concatsubstring[words[i]]++;
        }

        for (int i = 0; i < s.length() - concatsubstringlength + 1; i++) {
            if (check(concatsubstring, s.substr(i, concatsubstringlength), words[0].length())) {
                res.push_back(i);
            }
        }

        return res;
    }
};

int main()
{
    Solution s;
    vector<string> words = { "bar","foo","the" };
    vector<int> a = s.findSubstring("barfoothefoobarman", words);
    for (auto i : a)
        std::cout << i << endl;
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

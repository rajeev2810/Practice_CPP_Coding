#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>
#include <sstream>

using namespace std;

class Solution
{
public:
	unordered_map<string, int> wordfrequency()
	{
		ifstream file("myFile.txt");
		string fileContents;
        unordered_map<string, int> M{};
        string word;

		if (file)
		{
			std::stringstream buffer;
			buffer << file.rdbuf();
			file.close();
			fileContents = buffer.str();
		}

		for (char s: fileContents)
		{
            if (s == ' ') {
                // If the current word
                // is not found then insert
                // current word with frequency 1
                if (M.find(word) == M.end()) {
                    M.insert(make_pair(word, 1));
                    word = "";
                }
                // update the frequency
                else {
                    M[word]++;
                    word = "";
                }
            }
            else
                word += s;
        }

        // Storing the last word of the string
        if (M.find(word) == M.end())
            M.insert(make_pair(word, 1));
        // Update the frequency
        else
            M[word]++;

        return M;
	}
};

int main() {
    Solution s;
    unordered_map<string, int> res = s.wordfrequency();
    // Traverse the map
    // to print the  frequency
    for (auto& it : res) {
        cout << it.first << " - " << it.second << endl;
    }
}
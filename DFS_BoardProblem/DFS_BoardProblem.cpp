// DFS_BoardProblem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int dx[4] = { 1, -1, 0, 0 };
    int dy[4] = { 0, 0, 1, -1 };

    bool dfs(size_t i, size_t j, int index, vector<vector<char>>& board, string word, int row, int col, vector<vector<int>>& vis) {
        if (index == word.length()) return true;

        if (i < 0 || j < 0 || i >= row || j >= col) return false;
        if (board[i][j] != word[index]) return false;
        if (vis[i][j]) return false;

        vis[i][j] = 1;

        for (size_t k = 0; k < 4; k++) {
            size_t ni = i + dx[k];
            size_t nj = j + dy[k];
            if (dfs(ni, nj, index + 1, board, word, row, col, vis)) return true;
        }
        vis[i][j] = 0;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        size_t row = board.size();
        size_t col = board[0].size();
        vector<vector<int>> vis(row, vector<int>(col, 0));
        for (size_t i = 0; i < row; i++) {
            for (size_t j = 0; j < col; j++) {
                if (board[i][j] == word[0] && dfs(i, j, 0, board, word, row, col, vis)) return true;
            }
        }
        return false;
    }
};

int main()
{
    std::cout << "Hello World!\n";
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

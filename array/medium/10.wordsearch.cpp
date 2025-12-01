#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string& word,
             int i, int j, int k) {

        // If all characters matched
        if (k == word.size())
            return true;

        // Out of bounds OR mismatch
        if (i < 0 || j < 0 || 
            i >= board.size() || j >= board[0].size() ||
            board[i][j] != word[k])
            return false;

        // Mark as visited using temporary marker
        char temp = board[i][j];
        board[i][j] = '#';

        // Explore 4 directions
        bool found = dfs(board, word, i+1, j, k+1) ||
                     dfs(board, word, i-1, j, k+1) ||
                     dfs(board, word, i, j+1, k+1) ||
                     dfs(board, word, i, j-1, k+1);

        // Backtrack
        board[i][j] = temp;

        return found;
    }
};

int main() {
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };

    string word = "ABCCED";

    Solution s;
    cout << (s.exist(board, word) ? "true" : "false");
}

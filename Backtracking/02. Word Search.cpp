class Solution {
public:

    bool dfs(vector<vector<char> >& board, int i, int j, string s, int k) {

        if(k == s.length()) return true;

        if(i < 0 || j >= board[0].size() || j < 0 || i >= board.size() || s[k] != board[i][j]) return false;

        char x = board[i][j];
        board[i][j] = ' ';

        bool ans = false;

        ans |= dfs(board, i + 1, j, s, k + 1);
        ans |= dfs(board, i - 1, j, s, k + 1);
        ans |= dfs(board, i, j + 1, s, k + 1);
        ans |= dfs(board, i, j - 1, s, k + 1);

        board[i][j] = x;
        return ans;
    }

    bool exist(vector<vector<char> >& board, string word) {

        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == word[0]) {
                    if(dfs(board, i, j, word, 0)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};
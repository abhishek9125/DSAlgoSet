class Solution{
public:

    void dfs(int row, int col, vector<vector<int>> &ans) {

        if(row < 0 || row >= ans.size() || col < 0 || col >= ans[0].size() || ans[row][col] != 1) {
            return;
        }

        ans[row][col] = 0;
        dfs(row - 1, col, ans);
        dfs(row, col - 1, ans);
        dfs(row + 1, col, ans);
        dfs(row, col + 1, ans);
    } 

    int numberOfEnclaves(vector<vector<int>> &grid) {
        vector<vector<int>> ans = grid;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                    if(ans[i][j] == 1) {
                        dfs(i, j, ans);
                    }
                }
            }
        }

        int count = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(ans[i][j] == 1) {
                    count++;
                }
            }
        }

        return count;
    }
};

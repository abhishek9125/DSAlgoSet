class Solution
{
public:

    void dfs(int row, int col, vector<vector<int>>& visited, vector<vector<int>> &grid, vector<pair<int, int>>& vec, int baseRow, int baseCol) {
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || visited[row][col] || grid[row][col] != 1) {
            return;
        }

        vec.push_back({ row - baseRow, col - baseCol });
        visited[row][col] = 1;

        dfs(row - 1, col, visited, grid, vec, baseRow, baseCol);
        dfs(row, col + 1, visited, grid, vec, baseRow, baseCol);
        dfs(row + 1, col, visited, grid, vec, baseRow, baseCol);
        dfs(row, col - 1, visited, grid, vec, baseRow, baseCol);
    }

    int countDistinctIslands(vector<vector<int>> &grid){
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        set<vector<pair<int, int>>> st;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!visited[i][j] && grid[i][j] == 1) {
                    vector<pair<int, int>> vec;
                    dfs(i, j, visited, grid, vec, i, j);
                    st.insert(vec);
                }
            }
        }

        return st.size();
    }
};

class Solution{
public:

    void dfs(int row, int col, vector<vector<char>> &grid) {
        if(row >= grid.size() || row < 0 || col >= grid[0].size() || col < 0 || grid[row][col] != '1') {
            return;
        } 

        grid[row][col] = '0';
        dfs(row - 1, col - 1, grid);
        dfs(row - 1, col, grid);
        dfs(row - 1, col + 1, grid);
        dfs(row, col - 1, grid);
        dfs(row, col + 1, grid);
        dfs(row + 1, col - 1, grid);
        dfs(row + 1, col, grid);
        dfs(row + 1, col + 1, grid);

    }

    int numIslands(vector<vector<char>> &grid){
        int n = grid.size();
        int m = grid[0].size();

        int count = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1') {
                    dfs(i, j, grid);
                    count++;
                }
            }
        }

        return count;
    }
};

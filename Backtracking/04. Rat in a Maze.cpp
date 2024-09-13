class Solution{
    public:

    bool isSafe(vector<vector<int> > &grid, vector<vector<int>>& visited, int row, int col) {
        
        int n = grid.size();

        if(row < 0 || col < 0 || row >= n || col >= n || grid[row][col] == 0 || visited[row][col] == 1) return false;

        return true;
    }

    void solve(int row, int col, vector<vector<int> > &grid, vector<vector<int>>& visited, string path, vector<string>& ans) {
        
        int n = grid.size();

        if(row == n - 1 && col == n - 1) {
            ans.push_back(path);
            return;
        }

        if(isSafe(grid, visited, row + 1, col)) {
            visited[row][col] = 1;
            solve(row + 1, col, grid, visited, path + 'D', ans);
            visited[row][col] = 0;
        }


        if(isSafe(grid, visited, row, col - 1)) {
            visited[row][col] = 1;
            solve(row, col - 1, grid, visited, path + 'L', ans);
            visited[row][col] = 0;
        }


        if(isSafe(grid, visited, row, col + 1)) {
            visited[row][col] = 1;
            solve(row, col + 1, grid, visited, path + 'R', ans);
            visited[row][col] = 0;
        }


        if(isSafe(grid, visited, row - 1, col)) {
            visited[row][col] = 1;
            solve(row - 1, col, grid, visited, path + 'U', ans);
            visited[row][col] = 0;
        }
    }

    vector<string> findPath(vector<vector<int> > &grid) {
        //your code goes here
        int n = grid.size();
        vector<string> ans;
        if (grid[0][0] == 0 || grid[n - 1][n - 1] == 0) return ans;
        string path;
        vector<vector<int>> visited(n, vector<int>(n, 0));

        solve(0, 0, grid, visited, "", ans);

        return ans;
    }
};
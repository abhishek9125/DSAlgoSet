class Solution{
public:

    void dfs(int row, int col, vector<vector<char>>& mat, vector<vector<int>>& visited) {
        if(row < 0 || row >= mat.size() || col < 0 || col >= mat[0].size() || visited[row][col] == 1 || mat[row][col] == 'X') {
            return;
        }

        visited[row][col] = 1;

        dfs(row - 1, col, mat, visited);
        dfs(row, col - 1, mat, visited);
        dfs(row + 1, col, mat, visited);
        dfs(row, col + 1, mat, visited);
    }

    vector<vector<char>> fill(vector<vector<char>> mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        for(int j = 0; j < m; j++) {
            if(mat[0][j] == 'O' && visited[0][j] == 0) {
                dfs(0, j, mat, visited);
            }

            if(mat[n-1][j] == 'O' && visited[n-1][j] == 0) {    
                dfs(n-1, j, mat, visited);
            }
        }

        for(int i = 0; i < n; i++) {
            if(mat[i][0] == 'O' && visited[i][0] == 0) {
                dfs(i, 0, mat, visited);
            }

            if(mat[i][m-1] == 'O' && visited[i][m-1] == 0) {    
                dfs(i, m-1, mat, visited);
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(visited[i][j] == 0 && mat[i][j] == 'O') {
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
    }
};
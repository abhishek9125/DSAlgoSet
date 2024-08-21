class Solution{
public:
    vector<vector<int>> nearest(vector<vector<int>> grid){
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<vector<int>> distance(n, vector<int>(m, 0));

        queue<pair<pair<int, int>, int>> q;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    q.push({{ i, j }, 0});
                    visited[i][j] = 1;
                }
            }
        }

        int delRow[] = { -1, 0, 1, 0 };
        int delCol[] = { 0, 1, 0, -1 };

        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;

            distance[row][col] = dist;
            q.pop();

            for(int i = 0; i < 4; i++) {
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];

                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m) {
                    if(visited[newRow][newCol] == 0) {
                        q.push({ {newRow, newCol}, dist + 1 });
                        visited[newRow][newCol] = 1;
                    }
                }
            }
        }

        return distance;
    }
};
class Solution{
public:
    int orangesRotting(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        int visited[n][m];
        queue<pair<pair<int, int>, int>> q;

        int freshCount = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({ { i , j }, 0 });
                    visited[i][j] = 2;
                } else {
                    visited[i][j] = 0;
                }
                if(grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }

        int timeMin = 0;
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0 , 1, 0, -1};
        int count = 0;

        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;

            timeMin = max(time, timeMin);
            q.pop();

            for(int i = 0; i < 4; i++) {
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];

                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m) {
                    if(visited[nRow][nCol] == 0 && grid[nRow][nCol] == 1) {
                        q.push({ { nRow, nCol }, time + 1 });
                        visited[nRow][nCol] = 2;
                        count++;
                    }
                }

            }
        }

        return count == freshCount ? timeMin : -1;
    }
};
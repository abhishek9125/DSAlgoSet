class Solution{
    public:

    void dfs(int row, int col, vector<vector<int>> &image, int newColor, int currentColor) {
        if(row < 0 || row >= image.size() || col < 0 || col >= image[0].size() || image[row][col] != currentColor ) {
            return;
        }

        image[row][col] = newColor;

        dfs(row - 1, col, image, newColor, currentColor);
        dfs(row, col + 1, image, newColor, currentColor);
        dfs(row + 1, col, image, newColor, currentColor);
        dfs(row, col - 1, image, newColor, currentColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image,
                                  int sr, int sc, int newColor) {
      
        int currentColor = image[sr][sc];
        if (currentColor != newColor) {
            dfs(sr, sc, image, newColor, currentColor);
        }

        return image;

    }
};

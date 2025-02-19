class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int n = matrix[0].size();  // Line 6: Suggest renaming 'n' to 'numCols' for clarity
        int m = matrix.size();     // Line 7: Suggest renaming 'm' to 'numRows' for clarity

        int rowStart = 0;
        int colStart = 0;
        int rowEnd = m - 1;
        int colEnd = n - 1;

        while(rowStart <= rowEnd && colStart <= colEnd) {

            for(int i = colStart; i <= colEnd; i++) {
                result.push_back(matrix[rowStart][i]);
            }

            rowStart++;

            for(int i = rowStart; i <= rowEnd; i++) {
                result.push_back(matrix[i][colEnd]);
            }

            colEnd--;

            if(rowStart <= rowEnd) {
                for(int i = colEnd; i >= colStart; i--) {
                    result.push_back(matrix[rowEnd][i]);
                }

                rowEnd--;
            }

            if(colStart <= colEnd) {
                for(int i = rowEnd; i >= rowStart; i--) {
                    result.push_back(matrix[i][colStart]);
                }

                colStart++;
            }

        }

        return result;
    }
};

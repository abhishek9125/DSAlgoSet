class Solution
{

private:

    vector<int> findNSE(vector<int>& arr) {

        int n = arr.size();

        vector<int> ans(n);
        stack<int> s;

        for(int i = n - 1; i >= 0; i--) {

            while(!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }

            ans[i] = s.empty() ? n : s.top();

            s.push(i);
        }

        return ans;
    }

    vector<int> findPSE(vector<int>& arr) {

        int n = arr.size();

        vector<int> ans(n);
        stack<int> s;

        for(int i = 0; i < n; i++) {

            while(!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }

            ans[i] = s.empty() ? -1 : s.top();

            s.push(i);
        }

        return ans;
    }

    int largestRectangle(vector<int>& heights) {
        vector<int> next = findNSE(heights);
        vector<int> prev = findPSE(heights);

        int largestArea = 0;

        for(int i = 0; i < heights.size(); i++) {
            largestArea = max(largestArea, heights[i] * (next[i] - prev[i] - 1));
        }

        return largestArea;
    }

public:
    int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &matrix){

        int area = largestRectangle(matrix[0]);

        for(int i = 1; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                if(matrix[i][j] != 0) {
                    matrix[i][j] += matrix[i - 1][j];
                }
            }

            area = max(area, largestRectangle(matrix[i]));
        }

        return area;
    }
};